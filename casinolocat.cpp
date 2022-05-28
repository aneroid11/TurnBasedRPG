#include "casinolocat.h"
#include "gamescroll.h"

void CasinoLocat::action(Player *pl)
{
    GameScroll* scroll = GameScroll::getInstance();
    scroll->placeText(L"Поиграем?");

    scroll->placeOption(L"Сделать ставку: 5 золотых");
    scroll->placeOption(L"Не сегодня");

    if (scroll->displayAddedObjectsAndChoice() == L"Сделать ставку: 5 золотых")
    {
        scroll->placeText(L"Зря.");
    }
}
