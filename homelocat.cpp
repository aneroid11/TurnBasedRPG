#include "homelocat.h"
#include "gamescroll.h"
#include "player.h"

void HomeLocat::action(Player *player)
{
    GameScroll* scroll = GameScroll::getInstance();

    scroll->addScreenText({L"text", L"Смеркается. Что будем делать?"});
    scroll->addScreenText({L"button", L"Спать"});
    scroll->addScreenText({L"button", L"Смотреть телек"});

    if (scroll->displayAddedObjectsAndChoice() == L"Спать")
    {
        player->heal(100);

        scroll->placeText(L"Вы просыпаетесь утром. Здоровье за ночь полностью восстановилось.");
        scroll->placeOption(L"Подняться с кровати");
    }
    else
    {
        player->damage(10, L"Вы умерли. Вас номинируют на премию Дарвина.");

        scroll->placeText(L"Вы всю ночь смотрели телек и наутро у вас болит голова -10 hp.");
        scroll->placeText(L"Ваше здоровье: " + std::to_wstring(player->getHealth()));
        scroll->placeOption(L"Подняться с кровати");
    }

    scroll->displayAddedObjectsAndChoice();
}
