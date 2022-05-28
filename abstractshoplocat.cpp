#include "abstractshoplocat.h"
#include "gamescroll.h"

void AbstractShopLocat::action(Player *player)
{

}

std::wstring AbstractShopLocat::showShop(Player *player)
{
    GameScroll* scroll = GameScroll::getInstance();

    scroll->placeOption(L"Выйти из магазина");
    scroll->placeText(L"Ассортимент:");

    for (auto item : prices)
    {
        scroll->placeOption(item.first + L" - " + std::to_wstring(item.second) + L" золотых");
    }

    scroll->placeText(L"Следующие вещи в вашем инвентаре могут быть \nпроданы в этом магазине:");
}
