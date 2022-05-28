#include "homelocat.h"
#include "gamescroll.h"
#include "player.h"

void HomeLocat::action(Player *player)
{
    GameScroll* scroll = GameScroll::getInstance();

    scroll->addScreenText({L"text", L"Смеркается. \nЧто будем делать?"});
    scroll->addScreenText({L"button", L"Спать"});
    scroll->addScreenText({L"button", L"Смотреть телек"});

    if (scroll->displayAddedObjectsAndChoice() == L"Спать")
    {
        player->heal(100);

        ScreenTextList list2
        {
            {L"text", L"Вы просыпаетесь утром.\nЗдоровье за ночь полностью восстановилось."},
            {L"button", L"Подняться с кровати"}
        };
        scroll->displayAndWaitForChoice(list2);
    }
    else
    {
        player->damage(10, L"Вы умерли.\nВас номинируют на премию Дарвина.");

        ScreenTextList list2
        {
            {L"text", L"Вы всю ночь смотрели телек и наутро у вас \nболит голова -10 hp."},
            {L"text", L"Ваше здоровье: " + std::to_wstring(player->getHealth())},
            {L"button", L"Подняться с кровати"}
        };
        scroll->displayAndWaitForChoice(list2);
    }
}
