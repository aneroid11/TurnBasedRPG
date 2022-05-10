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

    for (sf::Drawable* d : objectsToDraw)
    {
        delete d;
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

void GameScroll::handleMousePressedEvent(const sf::Event& event)
{
    if (event.mouseButton.button == sf::Mouse::Left)
    {
        gotUserInput = true;
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
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                handleMousePressedEvent(event);
            }
        }

        this->window->clear();
        this->window->draw(bgSprite);

        for (sf::Drawable* obj : objectsToDraw)
        {
            this->window->draw(*obj);
        }

        this->window->display();
    }
}

void GameScroll::display(std::string text)
{
    this->gotUserInput = false;
    std::cout << text << "\n";

    while (!this->gotUserInput)
    {
        sf::sleep(sf::milliseconds(30));
    }
}
