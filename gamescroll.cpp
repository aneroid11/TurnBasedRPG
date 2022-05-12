#include "gamescroll.h"
#include "errorandexit.h"
#include "appearingtext.h"

GameScroll* GameScroll::instance = nullptr;

GameScroll::GameScroll()
{
    this->window = new sf::RenderWindow(sf::VideoMode(750, 800), "Resolution res");

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
    deleteScreenObjects();

    delete this->textFont;
    delete this->bgTexture;
    delete this->bgSprite;
}

void GameScroll::deleteScreenObjects()
{
    for (ScreenObject* o : this->objectsToDraw)
    {
        delete o;
    }
    this->objectsToDraw.clear();
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

        for (ScreenObject* obj : objectsToDraw)
        {
            obj->update();
        }
        for (ScreenObject* obj : objectsToDraw)
        {
            obj->draw(this->window);
        }

        this->window->display();
    }
}

void GameScroll::display(std::wstring text)
{
    TextParameters params;
    params.characterSize = 30;
    params.font = *this->textFont;
    params.position = this->textCursorPos;
    params.string = text.c_str();
    AppearingText* drawableText = new AppearingText(params);

    float textHeight = drawableText->getText().getGlobalBounds().height;

    if ((this->textCursorPos + sf::Vector2f(0.0f, textHeight)).y >= this->window->getSize().y)
    {
        this->deleteScreenObjects();
        this->textCursorPos = sf::Vector2f(10.0f, 0.0f);
        drawableText->setPosition(this->textCursorPos.x, this->textCursorPos.y);
    }

    this->objectsToDraw.push_back(drawableText);
    float lineSpacing = this->textFont->getLineSpacing(params.characterSize) - params.characterSize;

    this->textCursorPos += sf::Vector2f(0.0f, textHeight + lineSpacing);

    this->drawScrollUntilUserInput();
}
