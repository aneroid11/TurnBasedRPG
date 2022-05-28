#include "game.h"
#include "gamescroll.h"

Game::Game()
{
    this->scroll = GameScroll::getInstance();
}

Game::~Game()
{
    GameScroll::deleteInstance();
}

bool Game::saveFileExists() const
{
    // TODO: check if the save file (player.json) exists.
    return true;
}

void Game::run()
{
    while (true)
    {
        std::vector< std::array<std::wstring, 2> > screenText {
            { L"text", L"Добро пожаловать!"},
            { L"text", L"текст 2!" },
            { L"button", L"Кнопка" },
            { L"text", L"Ещё текст" },
            { L"button", L"Ещё кнопка" }
        };

        this->scroll->displayAndWaitForChoice(screenText);
    }
}
