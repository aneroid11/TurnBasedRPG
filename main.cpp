#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "gamescroll.h"

int main()
{
    GameScroll* scroll = GameScroll::getInstance();

    scroll->display(L"Банальные, но неопровержимые выводы,\nа также базовые сценарии поведения ");
    scroll->display(L"пользователей являются только методом\nполитического участия и описаны ");
    scroll->display(L"максимально подробно. С другой стороны, \nсоциально-экономическое развитие ");
    scroll->display(L"предоставляет широкие возможности для\nраспределения внутренних резервов \nи ресурсов!");

    GameScroll::deleteInstance();

    return 0;
}
