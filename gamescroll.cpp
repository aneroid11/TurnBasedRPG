#include "gamescroll.h"
#include "errorandexit.h"
#include "appearingtext.h"
#include "appearingbutton.h"

#include <algorithm>

GameScroll* GameScroll::instance = nullptr;

GameScroll::GameScroll()
{
    this->window = new sf::RenderWindow(sf::VideoMode(750, 1000), "Zdras Town");

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

void GameScroll::addText(const std::wstring &text)
{
    TextParameters params;
    params.characterSize = 30;
    params.font = this->textFont;
    params.position = this->textCursorPos;
    params.string = text.c_str();
    AppearingText* drawableText = new AppearingText(params);

    //float lineSpacing = this->textFont->getLineSpacing(params.characterSize) - params.characterSize;
    //float textHeight = drawableText->getText().getGlobalBounds().height + lineSpacing;
    float textHeight = textFont->getLineSpacing(params.characterSize);

    this->objectsToDraw.push_back(drawableText);

    this->textCursorPos += sf::Vector2f(0.0f, textHeight);
}

void GameScroll::addButton(const std::wstring &buttonText)
{
    AppearingButton* button = new AppearingButton(buttonText, *this->textFont);
    button->setPosition(sf::Vector2f(this->window->getSize().x / 2,
                                     this->textCursorPos.y));
    button->attachObserver(this);

    this->textCursorPos.y += button->getSize().y;

    this->objectsToDraw.push_back(button);
}

void GameScroll::deleteScreenObjects()
{
    for (ScreenObject* o : this->objectsToDraw)
    {
        delete o;
    }
    this->objectsToDraw.clear();

    this->textCursorPos = sf::Vector2f(10.0f, 0.0f);
}

GameScroll* GameScroll::getInstance()
{
    if (instance) { return instance; }
    instance = new GameScroll();

    return instance;
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
    while (!this->gotInputFromUser)
    {
        sf::Event event;

        if (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                this->window->close();
                exit(0);
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

        sf::sleep(sf::milliseconds(10));
    }
}

std::wstring GameScroll::displayAndWaitForChoice(const ScreenTextList& screenObjects)
{
    this->deleteScreenObjects();
    const int numScreenObjects = screenObjects.size();

    std::vector<std::wstring> choices;

    for (int i = 0; i < numScreenObjects; i++)
    {
        const std::wstring type = screenObjects[i][0];
        const std::wstring value = screenObjects[i][1];

        if (type == L"text")
        {
            this->addText(value);
        }
        else if (type == L"button")
        {
            this->addButton(value);
            choices.push_back(value);
        }
    }

    this->gotInputFromUser = false;

    bool foundChoiceInList = false;
    do
    {
        this->drawScrollUntilUserInput();

        foundChoiceInList = (std::find(choices.cbegin(), choices.cend(), this->userChoice) != choices.cend());
    } while (!foundChoiceInList);

    return this->userChoice;
}

void GameScroll::addScreenText(const std::array<std::wstring, 2> &text)
{
    this->addedScreenText.push_back(text);
}

void GameScroll::placeText(const std::wstring &text)
{
    const int maxLen = 43; // for CURRENT screen width

    std::wstring line = text;

    while (line.size() > maxLen)
    {
        std::wstring firstPart;
        int i;

        for (i = maxLen - 1; i > 0; i--)
        {
            if (iswspace(line[i]))
            {
                break;
            }
        }
        for (int j = 0; j < i; j++)
        {
            firstPart += line[j];
        }
        line.erase(0, i + 1);
        this->addScreenText({L"text", firstPart});
    }

    this->addScreenText({L"text", line});
}

std::wstring GameScroll::displayAddedObjectsAndChoice()
{
    std::wstring choice = this->displayAndWaitForChoice(this->addedScreenText);
    this->addedScreenText.clear();
    return choice;
}

void GameScroll::update(const std::wstring msgFromButton)
{
    this->userChoice = msgFromButton;
    this->gotInputFromUser = true;
}
