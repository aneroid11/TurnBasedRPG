#include "zdrasshoplocat.h"
#include "player.h"
#include "gamescroll.h"

void ZdrasShopLocat::action(Player *pl)
{
    GameScroll* scroll = GameScroll::getInstance();

    scroll->placeText(L"Zdras Shop - это магазинчик городской семьи. Тут вы можете купить или продать различный инвентарь или еду");

    prices[L"банан"] = 30;
    prices[L"рыба"] = 10;
    prices[L"червь"] = 2;
    prices[L"удочка"] = 20;
    prices[L"горючее"] = 100;

    AbstractShopLocat::action(pl);
}
