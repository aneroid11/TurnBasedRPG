#include "citygatelocat.h"
#include "player.h"
#include "gamescroll.h"

void CityGateLocat::action(Player *pl)
{
    GameScroll* scroll = GameScroll::getInstance();

    if (pl->hasEquipped(L"палка"))
    {
        scroll->placeText(L"Привратник одобрительно смотрит на вашу палку и говорит что за городом она вам понадобится");
    }
    else if (pl->hasInInventory(L"палка"))
    {
        scroll->placeText(L"Привратник рекомендует вам взять палку в руки и быть наготове - за городом есть враги");
    }
    else
    {
        scroll->placeText(L"Привратник не рекомендует вам выходить из города без палки, её можно купить в магазине инструментов");
    }
}
