#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "gamescroll.h"

int main()
{
    GameScroll* scroll = GameScroll::getInstance();

    scroll->display(L"Выбери:");
    scroll->display(L"Давай, выбирай:");

    do
    {
        std::list<std::wstring> choices = {
            L"Направо пойдёшь - коня потеряешь",
            L"Налево пойдёшь - золото найдёшь",
            L"Прямо пойдёшь - голову потеряешь",
            L"Да-да"
        };
        std::wstring choice = scroll->getUserChoice(choices);

        scroll->display(L"Выбрал? Молодец.");

        if (choice == L"Да-да")
        {
            scroll->display(L"Правда, мне не нравится твой выбор");
            scroll->display(L"Поэтому давай его поменяем");
        }
        else
        {
            break;
        }
    } while (true);

    scroll->display(L"Вот теперь хорошо.");

    GameScroll::deleteInstance();

    return 0;
}
