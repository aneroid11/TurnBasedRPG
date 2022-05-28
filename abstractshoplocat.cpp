#include "abstractshoplocat.h"
#include "gamescroll.h"
#include "player.h"

#include <algorithm>

std::wstring AbstractShopLocat::genBuyOption(std::wstring item)
{
    return (L"Купить " +
            item +
            L" - " +
            std::to_wstring(prices[item]) +
            L" золотых");
}

std::wstring AbstractShopLocat::genSellOption(std::wstring item)
{
    return (L"Продать [" +
            item +
            L"] - " +
            std::to_wstring(prices[item] / 2) +
            L" золотых");
}

void AbstractShopLocat::action(Player *player)
{
    GameScroll* scroll = GameScroll::getInstance();

    std::wstring choice;

    do
    {
        choice = showShop(player);

        for (auto item : prices)
        {
            std::wstring name = item.first;

            if (choice == genBuyOption(name))
            {
                if (player->getGold() >= prices[name])
                {
                    player->setGold(player->getGold() - prices[name]);
                    player->addToInventory(name);

                    scroll->placeText(L"Вы купили " + name);
                    scroll->placeText(L"У вас осталось " + std::to_wstring(player->getGold()) + L" золотых");
                }
                else
                {
                    scroll->placeText(L"У вас недостаточно денег для покупки этого предмета!");
                }
            }
        }

        for (auto item : player->getEquipmentItems())
        {
            if (choice == genSellOption(item))
            {
                int price = prices[item] / 2;
                player->setGold(player->getGold() + price);
                player->deleteFromInventory(item);

                scroll->placeText(L"Вы продали: " + item);
                scroll->placeText(L"Теперь у вас " + std::to_wstring(player->getGold()) + L" золотых");
            }
        }
    } while (choice != L"Выйти из магазина");
}

std::wstring AbstractShopLocat::showShop(Player *player)
{
    GameScroll* scroll = GameScroll::getInstance();

    scroll->placeOption(L"Выйти из магазина");
    scroll->placeText(L"Ассортимент:");

    for (auto item : prices)
    {
        scroll->placeOption(genBuyOption(item.first));
    }

    scroll->placeText(L"Следующие вещи в вашем инвентаре могут быть проданы в этом магазине:");

    bool hasSmthToSell = false;

    for (std::wstring item : player->getInventoryItems())
    {
        for (auto shopItem : prices)
        {
            if (shopItem.first == item)
            {
                hasSmthToSell = true;
                scroll->placeOption(genSellOption(item));
            }
        }
    }

    if (!hasSmthToSell)
    {
        scroll->placeText(L"Вам нечего предложить на продажу. "
                          L"Возможно, нужно перенести какое-то снаряжение в инвентарь, чтобы "
                          L"им заинтересовались");
    }

    return scroll->displayAddedObjectsAndChoice();
}
