#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "gamescroll.h"

int main()
{
    GameScroll* scroll = GameScroll::getInstance();

    for (int i = 0; i < 10; i++)
    {
        std::wstring text = std::wstring(L"Текст\nТекст текст фщалыфщвлщфыщвлЧ\nТектфывл") + std::to_wstring(i);
        scroll->display(text);
    }

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
