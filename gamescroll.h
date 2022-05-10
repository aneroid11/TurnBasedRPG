#ifndef GAMESCROLL_H
#define GAMESCROLL_H

#include <string>
#include <iostream>
#include <thread>
#include <functional>
#include <mutex>
#include <list>

#include <SFML/Graphics.hpp>

class GameScroll
{
public:
    static GameScroll* getInstance();
    static void deleteInstance();

    void display(std::wstring text);

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
    std::mutex mutex;

    sf::Font* textFont;
    bool transferControlToCaller = true;
    sf::Vector2f textCursorPos = sf::Vector2f(10.0f, 0.0f);
};

#endif // GAMESCROLL_H
