#include "fishingpier.h"
#include "gamescroll.h"
#include "player.h"

void FishingPier::action(Player *pl)
{
    GameScroll* scroll = GameScroll::getInstance();

    scroll->placeText(L"Порыбачим?");
    scroll->placeOption(L"Да");
    scroll->placeOption(L"Нет, идём дальше");

    if (scroll->displayAddedObjectsAndChoice() == L"Да")
    {
        if (!pl->hasInInventory(L"червь") || !pl->hasInInventory(L"удочка"))
        {
            scroll->placeText(L"У вас нет червя или удочки для рыбалки!");
            return;
        }

        std::wstring choice;

        do
        {
            pl->deleteFromInventory(L"червь");

            if (rand() % 100 > 50)
            {
                scroll->placeText(L"Вы словили рыбу!");
                pl->addToInventory(L"рыба");
            }
            else
            {
                scroll->placeText(L"Вы потратили одного червя, но ничего не словили");
            }

            if (!pl->hasInInventory(L"червь"))
            {
                scroll->placeText(L"Вы потратили всех червей и больше не можете рыбачить");
                return;
            }

            int worms = 0;
            int fishes = 0;

            for (std::wstring item : pl->getInventoryItems())
            {
                worms += item == L"червь";
                fishes += item == L"рыба";
            }

            scroll->placeText(L"Червей у вас: " + std::to_wstring(worms));
            scroll->placeText(L"Рыб у вас: " + std::to_wstring(fishes));
            scroll->placeText(L"Порыбачим ещё?");

            scroll->placeOption(L"ещё посидим (-1 червь)");
            scroll->placeOption(L"нет, кажется, всё выловили");

            choice = scroll->displayAddedObjectsAndChoice();
        }
        while (choice == L"ещё посидим (-1 червь)");
    }
}
