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

const int GAME_TEXT = 0;
const int CHOICE_BUTTON = 1;

class GameScroll : public IObserver
{
public:
    static GameScroll* getInstance();
    static void deleteInstance();

    void display(std::wstring text);
    std::wstring getUserChoice(const std::list<std::wstring>& choices);

    std::wstring displayAndWaitForChoice(const ScreenTextList& screenObjects);

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

    void handleMousePressedEvent(const sf::Event& event);
    void drawScrollUntilUserInput();

    sf::RenderWindow* window = nullptr;
    std::list<ScreenObject *> objectsToDraw;

    sf::Font* textFont;
    sf::Texture* bgTexture;
    sf::Sprite* bgSprite;
    bool transferControlToCaller = true;
    sf::Vector2f textCursorPos = sf::Vector2f(10.0f, 0.0f);

    std::wstring userChoice = L"";
    bool gotInputFromUser = false;
    int lastShown;
};

#endif // GAMESCROLL_H
