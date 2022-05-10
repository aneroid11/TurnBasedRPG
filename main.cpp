#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

void errorAndExit(std::string errMsg)
{
    std::cerr << errMsg << "\n";
    exit(-1);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(750, 1000), "Resolution res");
    sf::CircleShape shape(100.0f);
    shape.setFillColor(sf::Color::Green);

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
    }

    return 0;
}
