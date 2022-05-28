#include "inventory.h"
#include "player.h"
#include "gamescroll.h"

std::wstring Inventory::showInventory(Player *player)
{
    GameScroll* scroll = GameScroll::getInstance();
    scroll->addScreenText({L"button", L"Закрыть"});

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

    if (player->getInventoryItems().size() < 1)
    {
        scroll->addScreenText({L"text", L"Пуст!"});
    }
    for (std::wstring invItem : player->getInventoryItems())
    {
        scroll->addScreenText({L"button", invItem});
    }

    return scroll->displayAddedObjectsAndChoice();
}

void Inventory::action(Player *player)
{
    GameScroll* scroll = GameScroll::getInstance();

    std::wstring choice = L"";

    do
    {
        choice = this->showInventory(player);

        if (player->hasEquipped(choice))
        {
            player->addToInventory(choice);
            player->deleteFromEquipment(choice);
        }
        else if (player->hasInInventory(choice))
        {
            if (choice == L"банан" || choice == L"рыба")
            {
                int addHealth = 20;

                if (choice == L"рыба")
                {
                    addHealth = 10;
                }

                player->heal(addHealth);

                scroll->placeText(L"Вы съели " + choice);
                scroll->placeText(L"Ваше здоровье увеличилось на " + std::to_wstring(addHealth));
                scroll->placeText(L"Ваше здоровье: " + std::to_wstring(player->getHealth()));

                player->deleteFromInventory(choice);
            }
            else if (choice == L"палка" || choice == L"шапка")
            {
                if (choice == L"палка" && player->hasEquipped(L"палка"))
                {
                    scroll->placeText(L"Нельзя переместить в снаряжение вторую палку!");
                }
                else
                {
                    player->addToEquipment(L"палка");
                    player->deleteFromInventory(L"палка");
                }
            }
            else
            {
                scroll->placeText(L"Вы не можете ничего сделать с этой вещью в данный момент.");
            }
        }
    } while (choice != L"Закрыть");

    player->goToPreviousLocation();
}
