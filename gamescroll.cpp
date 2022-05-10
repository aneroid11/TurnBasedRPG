#include "gamescroll.h"
#include "errorandexit.h"

GameScroll* GameScroll::instance = nullptr;

GameScroll::GameScroll()
{
    this->window = new sf::RenderWindow(sf::VideoMode(750, 1000), "Resolution res");

    this->textFont = new sf::Font();
    if (!this->textFont->loadFromFile("resources/fonts/arial.ttf"))
    {
        errorAndExit("Cannot load font");
    }

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

    delete this->textFont;
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
        this->transferControlToCaller = true;
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

        mutex.lock();
        for (sf::Drawable* obj : objectsToDraw)
        {
            this->window->draw(*obj);
        }
        mutex.unlock();

        this->window->display();
    }
}

void GameScroll::display(std::string text)
{
    this->mutex.lock();

    this->transferControlToCaller = false;

    sf::Text* drawableText = new sf::Text(text.c_str(), *(this->textFont));

    drawableText->setOutlineColor(sf::Color(200, 200, 200));
    drawableText->setOutlineThickness(1.0f);
    drawableText->setPosition(this->textCursorPos);
    this->objectsToDraw.push_back(drawableText);

    this->textCursorPos += sf::Vector2f(0.0f, drawableText->getGlobalBounds().height);

    this->mutex.unlock();

    while (!this->transferControlToCaller)
    {
        sf::sleep(sf::milliseconds(30));
    }
}
