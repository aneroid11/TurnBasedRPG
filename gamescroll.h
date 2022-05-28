#ifndef GAMESCROLL_H
#define GAMESCROLL_H

#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <array>

#include <SFML/Graphics.hpp>

#include "screenobject.h"
#include "iobserver.h"

typedef std::vector< std::array<std::wstring, 2> > ScreenTextList;

class GameScroll : public IObserver
{
public:
    static GameScroll* getInstance();
    static void deleteInstance();

    std::wstring displayAndWaitForChoice(const ScreenTextList& screenObjects);

    void addScreenText(const std::array<std::wstring, 2>& text);
    std::wstring displayAddedObjectsAndChoice();

    void placeText(const std::wstring& text) { this->addScreenText({L"text", text}); }
    void placeOption(const std::wstring& option) { this->addScreenText({L"button", option}); }

    void update(const std::wstring msgFromSubject) override;

private:
    GameScroll();
    GameScroll(const GameScroll& gs) = delete;
    ~GameScroll();

    void addText(const std::wstring& text);
    void addButton(const std::wstring& buttonText);

    void deleteScreenObjects();

    GameScroll operator =(const GameScroll& gs) = delete;

    static GameScroll* instance;

    void drawScrollUntilUserInput();

    sf::RenderWindow* window = nullptr;
    std::list<ScreenObject *> objectsToDraw;

    sf::Font* textFont;
    sf::Texture* bgTexture;
    sf::Sprite* bgSprite;
    bool transferControlToCaller = true;
    sf::Vector2f textCursorPos = sf::Vector2f(10.0f, 0.0f);

    ScreenTextList addedScreenText;

    std::wstring userChoice = L"";
    bool gotInputFromUser = false;
};

#endif // GAMESCROLL_H
