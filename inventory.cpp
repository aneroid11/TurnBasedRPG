#include "inventory.h"
#include "player.h"
#include "gamescroll.h"

std::wstring Inventory::showInventory(Player *player)
{
    GameScroll* scroll = GameScroll::getInstance();

    scroll->addScreenText({L"text", L"Снаряжение:"});

    if (player->getEquipmentItems().size() < 1)
    {
        scroll->addScreenText({L"text", L"Пусто!"});
    }
    for (std::wstring eqItem : player->getEquipmentItems())
    {
        scroll->addScreenText({L"button", eqItem});
    }

    scroll->addScreenText({L"text", L"Инвентарь:"});

    if (player->getEquipmentItems().size() < 1)
    {
        scroll->addScreenText({L"text", L"Пуст!"});
    }
    for (std::wstring invItem : player->getInventoryItems())
    {
        scroll->addScreenText({L"button", invItem});
    }

    scroll->addScreenText({L"button", L"\nЗакрыть"});

    return scroll->displayAddedObjectsAndChoice();
}

void Inventory::action(Player *player)
{
    GameScroll* scroll = GameScroll::getInstance();
    scroll->addScreenText({L"text", L"В инвентаре пока ничего нет"});
    scroll->addScreenText({L"button", L"Ладно"});

    GameScroll::getInstance()->displayAddedObjectsAndChoice();

    player->goToPreviousLocation();
}
