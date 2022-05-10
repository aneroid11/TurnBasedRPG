#include "gamescroll.h"
#include "errorandexit.h"

GameScroll* GameScroll::instance = nullptr;

GameScroll::GameScroll()
{
    this->window = new sf::RenderWindow(sf::VideoMode(750, 1000), "Resolution res");

    auto func = std::bind(&GameScroll::gameLoop, this);
    this->gameLoopThread = new std::thread(func);
}

GameScroll::~GameScroll()
{
    this->gameLoopThread->join();
    delete this->gameLoopThread;

    if (this->window)
    {
        delete this->window;
    }
}

GameScroll* GameScroll::getInstance()
{
    if (instance) { return instance; }

    return new GameScroll();
}

void GameScroll::deleteInstance()
{
    if (instance)
    {
        delete instance;
        instance = nullptr;
    }
}

void GameScroll::gameLoop()
{
    sf::Texture bgTexture;
    if (!bgTexture.loadFromFile("resources/images/bg_texture.png"))
    {
        errorAndExit("Cannot load texture");
    }

    sf::Sprite bgSprite(bgTexture);

    while (this->window->isOpen())
    {
        sf::Event event;
        while (this->window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                this->window->close();
                return;
            }
        }

        this->window->clear();
        this->window->draw(bgSprite);
        this->window->display();
    }
}

void GameScroll::display(std::string text)
{
    std::cout << text << "\n";
}
