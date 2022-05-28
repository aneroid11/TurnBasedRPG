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

    scroll->addScreenText({L"button", L"Закрыть"});

    return scroll->displayAddedObjectsAndChoice();
}

void Inventory::action(Player *player)
{
    GameScroll* scroll = GameScroll::getInstance();

    std::wstring choice = L"";

    do
    {
        choice = this->showInventory(player);

        std::vector<std::wstring> playerInv = player->getInventoryItems();
        std::vector<std::wstring> playerEqp = player->getEquipmentItems();

        if (player->hasEquipped(choice))
        {
            player->addToInventory(choice);
            player->deleteFromEquipment(choice);
        }
        else if (player->hasInInventory(choice))
        {
            if (choice == L"банан" || choice == L"рыба")
            {

            }
        }
    } while (choice != L"Закрыть");

    player->goToPreviousLocation();
}
