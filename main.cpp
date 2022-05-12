#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "gamescroll.h"

int main()
{
    GameScroll* scroll = GameScroll::getInstance();

    scroll->display(L"Банальные, но неопровержимые выводы, а также базовые сценарии поведения ");
    scroll->display(L"пользователей являются только методом политического участия и описаны ");
    scroll->display(L"максимально подробно. С другой стороны, социально-экономическое развитие ");
    scroll->display(L"предоставляет широкие возможности для распределения внутренних резервов и ресурсов!");

    GameScroll::deleteInstance();

    return 0;
}
