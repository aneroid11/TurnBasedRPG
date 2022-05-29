#include "baywithboatlocat.h"
#include "gamescroll.h"
#include "player.h"

void BayWithBoatLocat::action(Player *pl)
{
    GameScroll* s = GameScroll::getInstance();

    s->placeText(L"В бухте вы видите лодку. Что делаем?");
    s->placeOption(L"Попробовать завести");
    s->placeOption(L"Идти дальше");

    if (s->displayAddedObjectsAndChoice() == L"Попробовать завести")
    {
        s->placeText(L"Двигатель лодки не заводится: в баке нет горючего");

        if (pl->hasInInventory(L"горючее"))
        {
            s->placeText(L"Вы вспоминаете, что у вас есть горючее. Что делаем?");
            s->placeOption(L"Заправить и попробовать завести");
            s->placeOption(L"Уйти");

            if (s->displayAddedObjectsAndChoice() == L"Заправить и попробовать завести")
            {
                s->placeText(L"Двигатель лодки заводится и вы уплываете с острова навстречу новым приключениям");
                s->placeOption(L"Завершить игру");
                s->displayAddedObjectsAndChoice();
                exit(0);
            }
        }
    }
}
