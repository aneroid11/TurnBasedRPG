#ifndef GAMESCROLL_H
#define GAMESCROLL_H

#include <string>
#include <iostream>
#include <thread>
#include <functional>

#include <SFML/Graphics.hpp>

class GameScroll
{
public:
    static GameScroll* getInstance();
    static void deleteInstance();

    void display(std::string text);
    void gameLoop();

private:
    GameScroll();
    ~GameScroll();
    GameScroll(const GameScroll& gs) = delete;
    GameScroll operator =(const GameScroll& gs) = delete;

    static GameScroll* instance;

    sf::RenderWindow* window = nullptr;

    std::thread* gameLoopThread;
};

#endif // GAMESCROLL_H
