#include "abstractlocwithpalm.h"
#include "player.h"
#include "gamescroll.h"

void AbstractLocWithPalm::action(Player *pl)
{
    AbstractFightLocation::action(pl);

    GameScroll* scroll = GameScroll::getInstance();

    std::wstring choice;

    do
    {
        scroll->placeText(L"Вы видите пальму. Что будем делать?");
        scroll->placeOption(L"потрясти пальму");
        scroll->placeOption(L"идти дальше");

        choice = scroll->displayAddedObjectsAndChoice();

        if (choice == L"потрясти пальму")
        {
            shakesCount--;

            if (shakesCount > 2)
            {
                pl->addToInventory(L"банан");

                scroll->placeText(L"С пальмы падает банан, вы его поднимаете и кладёте в инвентарь.");
            }
            else if (shakesCount == 0 && getName() == L"Лес" && !pl->hasInInventory(L"англо-русский словарь"))
            {
                scroll->placeText(L"С пальмы падает англо-русский словарь. Неизвестно, зачем он вам может пригодиться, но вы решаете положить его в инвентарь на всякий случай");
                pl->addToInventory(L"англо-русский словарь");
            }
            else
            {
                scroll->placeText(L"С пальмы ничего не упало");
            }
        }
    } while (choice != L"идти дальше");
}
