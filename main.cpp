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

    //GameScroll::getInstance()->display("this is going to be displayed by GameScroll");
    /*sf::RenderWindow window(sf::VideoMode(750, 1000), "Resolution res");

    sf::Texture bgTexture;
    if (!bgTexture.loadFromFile("resources/images/bg_texture.png"))
    {
        errorAndExit("Cannot load texture");
    }

    sf::Sprite bgSprite(bgTexture);

    sf::Font arial;
    if (!arial.loadFromFile("resources/fonts/arial.ttf"))
    {
        errorAndExit("Cannot load font");
    }

    sf::Text text;
    text.setFont(arial);
    text.setString("Ya sizhu i smotryu v chuzhoye nebo iz chuzhogo okna\n"
                   "Ya sizhu i smotryu v chuzhoye nebo iz chuzhogo okna\n"
                   "Ya sizhu i smotryu v chuzhoye nebo iz chuzhogo okna\n"
                   "Ya sizhu i smotryu v chuzhoye nebo iz chuzhogo okna");
    text.setOutlineColor(sf::Color(200, 200, 200));
    text.setOutlineThickness(1.0f);
    text.setPosition(10, 0);
    //std::cout << text.getPosition().y << "\n";

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.draw(bgSprite);
        window.draw(text);
        window.display();
    }*/

    return 0;
}
