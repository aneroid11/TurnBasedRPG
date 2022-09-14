#include "toolsshoplocat.h"
#include "gamescroll.h"

void ToolsShopLocat::action(Player *player)
{
    GameScroll* scroll = GameScroll::getInstance();

    scroll->placeText(L"Здесь вы можете купить или продать оружие или броню. Для продажи они должны находиться у вас в инвентаре");

    prices[L"палка"] = 30;
    prices[L"шапка"] = 20;

    AbstractShopLocat::action(player);
}
