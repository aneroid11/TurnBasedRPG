#include "inventory.h"
#include "player.h"
#include "gamescroll.h"

const std::wstring equipSuffix = L" [использовать]";
const std::wstring unequipSuffix = L" [переместить в инвентарь]";

std::wstring genMsg(std::wstring item, std::wstring suffix)
{
    return item + suffix;
}

std::wstring getItemFromMsg(std::wstring msg, std::wstring suffix)
{
    if (msg.find(suffix) == std::wstring::npos)
    {
        return msg;
    }

    msg.erase(msg.find(suffix), suffix.size());
    return msg;
}

std::wstring canEquipMsg(std::wstring item)
{
    return genMsg(item, equipSuffix);
}

std::wstring getItemFromCanEquip(std::wstring msg)
{
    return getItemFromMsg(msg, equipSuffix);
}

std::wstring canUnequipMsg(std::wstring item)
{
    return genMsg(item, unequipSuffix);
}

std::wstring getItemFromCanUnequip(std::wstring msg)
{
    return getItemFromMsg(msg, unequipSuffix);
}

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
        scroll->placeOption(canUnequipMsg(eqItem));
    }

    scroll->addScreenText({L"text", L"Инвентарь:"});

    if (player->getInventoryItems().size() < 1)
    {
        scroll->addScreenText({L"text", L"Пуст!"});
    }
    for (std::wstring invItem : player->getInventoryItems())
    {
        scroll->placeOption(canEquipMsg(invItem));
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

        if (player->hasEquipped(getItemFromCanUnequip(choice)))
        {
            choice = getItemFromCanUnequip(choice);
            player->addToInventory(choice);
            player->deleteFromEquipment(choice);
        }
        else if (player->hasInInventory(getItemFromCanEquip(choice)))
        {
            choice = getItemFromCanEquip(choice);

            if (choice == L"банан" || choice == L"рыба")
            {
                int addHealth = 20;

                if (choice == L"рыба")
                {
                    addHealth = 10;
                }

                player->heal(addHealth);

                scroll->placeText(L"Вы съели [" + choice + L"]");
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
                    player->addToEquipment(choice);
                    player->deleteFromInventory(choice);
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
