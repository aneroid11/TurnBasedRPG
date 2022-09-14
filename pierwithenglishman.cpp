#include "pierwithenglishman.h"
#include "player.h"
#include "gamescroll.h"

void PierWithEnglishman::action(Player *pl)
{
    GameScroll* scroll = GameScroll::getInstance();

    scroll->placeText(L"На пирсе сидит рыбак, говорящий только по-английски. Что делаем?");
    scroll->placeOption(L"Поздороваться");
    scroll->placeOption(L"Пройти мимо");

    if (scroll->displayAddedObjectsAndChoice() == L"Поздороваться")
    {
        if (!pl->hasInInventory(L"англо-русский словарь"))
        {
            scroll->placeText(L"Без словаря вы не можете сказать ни слова по-английски, поэтому, немного помолчав, вы уходите");
        }
        else
        {
            scroll->placeText(L"С помощью словаря вы немного говорите с англичанином, и он предлагает вам купить у него горючее всего за 50 золотых");

            if (pl->hasInInventory(L"горючее"))
            {
                scroll->placeText(L"Но у вас оно уже есть, поэтому вы отказываетесь и уходите");
            }
            else
            {
                if (pl->getGold() < 50)
                {
                    scroll->placeText(L"У вас сейчас нет таких денег, поэтому вы договариваетесь вернуться, когда они у вас будут");
                }
                else
                {
                    scroll->placeText(L"У вас как раз есть такие деньги. Что делаем?");

                    scroll->placeOption(L"купить горючее");
                    scroll->placeOption(L"отказаться");

                    if (scroll->displayAddedObjectsAndChoice() == L"купить горючее")
                    {
                        pl->setGold(pl->getGold() - 50);
                        pl->addToInventory(L"горючее");

                        scroll->placeText(L"Вы купили горючее за 50 золотых");
                    }
                }
            }
        }
    }

    FishingPier::action(pl);
}
