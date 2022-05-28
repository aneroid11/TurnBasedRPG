#include "inventory.h"
#include "player.h"
#include "gamescroll.h"

std::wstring Inventory::showInventory(Player *player)
{
    ScreenTextList textList;

    textList.push_back({L"text", L"Снаряжение:"});

    if (player->getEquipmentItems().size() < 1)
    {
        textList.push_back({L"text", L"Пусто!"});
    }
    for (std::wstring eqItem : player->getEquipmentItems())
    {
        textList.push_back({L"button", eqItem});
    }

    textList.push_back({L"text", L"Инвентарь:"});

    if (player->getEquipmentItems().size() < 1)
    {
        textList.push_back({L"text", L"Пуст!"});
    }
    for (std::wstring invItem : player->getInventoryItems())
    {
        textList.push_back({L"button", invItem});
    }

    textList.push_back({L"button", L"\nЗакрыть"});

    return GameScroll::getInstance()->displayAndWaitForChoice(textList);
}

void Inventory::action(Player *player)
{
    ScreenTextList textList
    {
        {L"text", L"В инвентаре пока ничего нет"},
        {L"button", L"Ладно"}
    };
    GameScroll::getInstance()->displayAndWaitForChoice(textList);

    player->goToPreviousLocation();
}
