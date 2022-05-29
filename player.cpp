#include "player.h"
#include "gamescroll.h"

#include <string>
#include <locale>
#include <codecvt>

void Player::displayStatus()
{
    GameScroll* scroll = GameScroll::getInstance();

    scroll->placeText(L"Вы находитесь в [" + getCurrentLocation()->getName() + L"]");
    scroll->placeText(L"Золото: " + std::to_wstring(getGold()));
    scroll->placeText(L"Здоровье: " + std::to_wstring(this->getHealth()));
}

std::string wstringToString(const std::wstring &ws)
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::string narrow = converter.to_bytes(ws);

    return narrow;
}

std::wstring stringToWstring(const std::string &s)
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring wide = converter.from_bytes(s);

    return wide;
}

json Player::serializeToJson() const
{
    json j;
    j["health"] = getHealth();
    j["gold"] = getGold();
    j["inventory"] = {};
    j["equipment"] = {};

    for (auto item : inventory)
    {
        j["inventory"].push_back(wstringToString(item));
    }
    for (auto item : equipment)
    {
        j["equipment"].push_back(wstringToString(item));
    }

    return j;
}

bool Player::deserializeFromJson(json j)
{
    if (!j.contains("health") || !j.contains("gold") || !j.contains("inventory") || !j.contains("equipment"))
    {
        return false;
    }

    health = j["health"];
    gold = j["gold"];

    for (auto item : j["inventory"])
    {
        addToInventory(stringToWstring(item));
    }
    for (auto item : j["equipment"])
    {
        addToInventory(stringToWstring(item));
    }

    return true;
}

void Player::damage(int dmg, std::wstring deathMsg)
{
    health -= dmg;

    if (health <= 0)
    {
        health = 0;

        if (hasEquipped(L"шапка"))
        {
            heal(100);
            deleteFromEquipment(L"шапка");
            GameScroll::getInstance()->placeText(L"Шапка уничтожена!");
        }
        else
        {
            die(deathMsg);
        }
    }
}

void Player::die(std::wstring msg)
{
    GameScroll* scroll = GameScroll::getInstance();

    if (msg == L"") { msg = L"Вы мертвы."; }

    scroll->placeText(msg);
    scroll->placeOption(L"Завершить игру");
    scroll->displayAddedObjectsAndChoice();
    exit(0);
}
