#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "gamescroll.h"

int main()
{
    GameScroll* scroll = GameScroll::getInstance();

    scroll->display(L"Выбери:");
    scroll->display(L"Давай, выбирай:");

    std::list<std::wstring> choices = {
        L"Направо пойдёшь - коня потеряешь",
        L"Налево пойдёшь - золото найдёшь",
        L"Прямо пойдёшь - голову потеряешь"
    };
    std::wstring choice = scroll->getUserChoice(choices);
    std::wcout << choice << "\n";

    GameScroll::deleteInstance();

    return 0;
}
