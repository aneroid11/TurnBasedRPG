#include "abstractfightlocation.h"
#include "player.h"
#include "gamescroll.h"

void AbstractFightLocation::action(Player *pl)
{
    srand(time(nullptr));

    GameScroll* scroll = GameScroll::getInstance();

    if (rand() % 100 >= 50) { return; }

    int spanielHealth = 100;

    scroll->placeText(L"На вас напал бешеный кокерспаниель!");

    if (pl->getHealth() > 70)
    {
        scroll->placeText(L"У вас достаточно сил, чтобы попытаться убежать, но может и не получиться. Что делаем?");
        scroll->placeOption(L"Дерёмся");
        scroll->placeOption(L"Бежим");

        if (scroll->displayAddedObjectsAndChoice() == L"Бежим")
        {
            if (rand() % 100 < 80)
            {
                scroll->placeText(L"Вы убежали от собаки!");
                return;
            }

            scroll->placeText(L"Убежать не получилось, собака двигается слишком быстро. Придётся драться!");
        }
    }

    while (spanielHealth > 0)
    {
        scroll->placeText(L"Ваше здоровье: " + std::to_wstring(pl->getHealth()));
        scroll->placeText(L"Здоровье собаки: " + std::to_wstring(spanielHealth));

        if (pl->hasEquipped(L"палка"))
        {
            scroll->placeOption(L"Ударить палкой");
        }
        else
        {
            scroll->placeOption(L"Ударить кулаком");
        }

        scroll->displayAddedObjectsAndChoice();

        if (rand() % 100 < spanielHealth)
        {
            scroll->placeText(L"Собака укусила вас!");
            pl->damage(8, L"Вас загрыз бешеный кокерспаниель. Не такой участи вы ожидали от тихого островного городка...");
        }
        else
        {
            scroll->placeText(L"Собака попыталась вас укусить, но вы сумели увернуться");
        }

        if (rand() % 100 < pl->getHealth())
        {
            if (pl->hasEquipped(L"палка"))
            {
                scroll->placeText(L"Вы ударили собаку палкой");
                spanielHealth -= 30;
            }
            else
            {
                scroll->placeText(L"Вы ударили собаку кулаком");
                spanielHealth -= 10;
            }
        }
        else
        {
            scroll->placeText(L"Вы попытались ударить собаку, но она увернулась");
        }
    }

    scroll->placeText(L"Собака сдохла");

    int rndLoot = rand() % 3;
    std::wstring loot;

    switch (rndLoot) {
    case 0:
        loot = L"палка";
        pl->addToInventory(loot);
        break;
    case 1:
        loot = L"шапка";
        pl->addToInventory(loot);
        break;
    case 2:
        loot = L"15 золота";
        pl->setGold(pl->getGold() + 15);
    default:
        break;
    }

    scroll->placeText(L"Из неё выпал лут: " + loot);
}
