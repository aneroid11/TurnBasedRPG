#include "gamescroll.h"
#include "errorandexit.h"
#include "appearingtext.h"
#include "appearingbutton.h"

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
    while (true)
    {
        sf::Event event;
        if (this->window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                this->window->close();
                exit(0);
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    return;
                }
            }
        }

        for (ScreenObject* obj : objectsToDraw)
        {
            obj->update(event, *this->window);
        }

        this->window->clear();
        this->window->draw(*this->bgSprite);

        for (ScreenObject* obj : objectsToDraw)
        {
            this->window->draw(*obj);
        }

        this->window->display();
    }
}

void GameScroll::display(std::wstring text)
{
    TextParameters params;
    params.characterSize = 30;
    params.font = this->textFont;
    params.position = this->textCursorPos;
    params.string = text.c_str();
    AppearingText* drawableText = new AppearingText(params);

    float lineSpacing = this->textFont->getLineSpacing(params.characterSize) - params.characterSize;
    float textHeight = drawableText->getText().getGlobalBounds().height + lineSpacing;

    if ((this->textCursorPos + sf::Vector2f(0.0f, textHeight)).y >= this->window->getSize().y)
    {
        this->deleteScreenObjects();
        this->textCursorPos = sf::Vector2f(10.0f, 0.0f);
        drawableText->setPosition(this->textCursorPos.x, this->textCursorPos.y);
    }

    this->objectsToDraw.push_back(drawableText);

    this->textCursorPos += sf::Vector2f(0.0f, textHeight);

    this->drawScrollUntilUserInput();
}

std::wstring GameScroll::getUserChoice(const std::list<std::wstring>& choices)
{
    // вывести на экран список возможных вариантов в виде кнопок, считать нажатие на кнопку и вернуть
    // тот вариант, на который нажал игрок

    for (const std::wstring& choice : choices)
    {
        AppearingButton* button = new AppearingButton(choice, *this->textFont,
                                                      sf::Vector2f(this->window->getSize().x / 2,
                                                                   this->textCursorPos.y));
        this->textCursorPos.y += button->getSize().y;
        this->objectsToDraw.push_back(button);
    }

    this->drawScrollUntilUserInput();

    return L"Choice 1";
}
