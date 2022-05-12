#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "gamescroll.h"

int main()
{
    GameScroll* scroll = GameScroll::getInstance();

    for (int i = 0; i < 100; i++)
    {
        std::wstring text = std::wstring(L"Текст ") + std::to_wstring(i);
        scroll->display(text);
    }

    GameScroll::deleteInstance();

    return 0;
}
