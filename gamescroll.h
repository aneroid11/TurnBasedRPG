#ifndef GAMESCROLL_H
#define GAMESCROLL_H

#include <string>
#include <iostream>
#include <thread>
#include <functional>
#include <list>

#include <SFML/Graphics.hpp>

class GameScroll
{
public:
    static GameScroll* getInstance();
    static void deleteInstance();

    void display(std::string text);

private:

    GameScroll();
    GameScroll(const GameScroll& gs) = delete;
    ~GameScroll();

    GameScroll operator =(const GameScroll& gs) = delete;

    static GameScroll* instance;

    void handleMousePressedEvent(const sf::Event& event);
    void gameLoop();

    sf::RenderWindow* window = nullptr;
    std::list<sf::Drawable *> objectsToDraw;
    std::thread* gameLoopThread;

    bool gotUserInput = true;
};

#endif // GAMESCROLL_H
