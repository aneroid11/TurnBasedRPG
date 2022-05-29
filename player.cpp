#include "player.h"
#include "gamescroll.h"

void Player::displayStatus()
{
    GameScroll* scroll = GameScroll::getInstance();

    scroll->placeText(L"Вы находитесь в [" + getCurrentLocation()->getName() + L"]");
    scroll->placeText(L"Золото: " + std::to_wstring(getGold()));
    scroll->placeText(L"Здоровье: " + std::to_wstring(this->getHealth()));
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
