#include "casinolocat.h"
#include "gamescroll.h"
#include "player.h"

#include <cstdlib>
#include <ctime>

void CasinoLocat::action(Player *pl)
{
    srand(time(nullptr));

    GameScroll* scroll = GameScroll::getInstance();
    scroll->placeText(L"Поиграем?");

    scroll->placeOption(L"Сделать ставку: 5 золотых");
    scroll->placeOption(L"Не сегодня");

    if (scroll->displayAddedObjectsAndChoice() == L"Сделать ставку: 5 золотых")
    {
        if (pl->getGold() < 5)
        {
            scroll->placeText(L"У вас недостаточно денег!");
            return;
        }

        std::wstring choice;

        do
        {
            if (rand() % 100 >= 90)
            {
                scroll->placeText(L"Вы выиграли 100 золотых!");
                pl->setGold(pl->getGold() + 100);
            }
            else
            {
                pl->setGold(pl->getGold() - 5);

                scroll->placeText(L"Вы ничего не выиграли.");

                if (pl->getGold() < 5)
                {
                    scroll->placeText(L"Вы спустили почти все деньги и не можете больше делать ставки");
                    return;
                }
            }

            scroll->placeText(L"Денег у вас: " + std::to_wstring(pl->getGold()));
            scroll->placeText(L"Играем дальше?");
            scroll->placeOption(L"Ещё ставку");
            scroll->placeOption(L"Нет, с меня хватит");

            choice = scroll->displayAddedObjectsAndChoice();
        } while (choice == L"Ещё ставку");
    }
}
