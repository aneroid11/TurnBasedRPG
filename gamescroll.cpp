#include "gamescroll.h"
#include "errorandexit.h"

GameScroll* GameScroll::instance = nullptr;

GameScroll::GameScroll()
{
    this->window = new sf::RenderWindow(sf::VideoMode(750, 1000), "Resolution res");

    this->textFont = new sf::Font();
    if (!this->textFont->loadFromFile("resources/fonts/Ubuntu-B.ttf"))
    {
        errorAndExit("Cannot load font");
    }

    this->bgTexture = new sf::Texture();
    if (!this->bgTexture->loadFromFile("resources/images/bg_texture.png"))
    {
        errorAndExit("Cannot load texture");
    }

    this->bgSprite = new sf::Sprite(*this->bgTexture);
}

GameScroll::~GameScroll()
{
    if (this->window)
    {
        delete this->window;
    }
    for (sf::Drawable* d : this->objectsToDraw)
    {
        delete d;
    }

    delete this->textFont;
    delete this->bgTexture;
    delete this->bgSprite;
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

void GameScroll::drawScrollUntilUserInput()
{
    while (this->window->isOpen())
    {
        sf::Event event;
        while (this->window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                this->window->close();
                //return;
                exit(0);
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                //handleMousePressedEvent(event);
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    return;
                }
            }
        }

        this->window->clear();
        this->window->draw(*this->bgSprite);

        for (sf::Drawable* obj : objectsToDraw)
        {
            this->window->draw(*obj);
        }

        this->window->display();
    }
}

void GameScroll::display(std::wstring text)
{
    sf::Text* drawableText = new sf::Text(text.c_str(), *(this->textFont));

    unsigned int alpha = 200;
    drawableText->setOutlineColor(sf::Color(200, 200, 200, alpha));
    drawableText->setOutlineThickness(1.0f);
    drawableText->setPosition(this->textCursorPos);
    //drawableText->setColor(sf::Color(0, 0, 0, 0));
    drawableText->setFillColor(sf::Color(drawableText->getFillColor().r,
                                         drawableText->getFillColor().g,
                                         drawableText->getFillColor().b,
                                         alpha));
    this->objectsToDraw.push_back(drawableText);

    this->textCursorPos += sf::Vector2f(0.0f, drawableText->getGlobalBounds().height);

    this->drawScrollUntilUserInput();
}
