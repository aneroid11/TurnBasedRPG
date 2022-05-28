#include "game.h"
#include "gamescroll.h"
#include "mainmenu.h"

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
        scroll->display(L"Добро пожаловать");

        std::list<std::wstring> choices = {
            L"Начать новую игру",
            L"Загрузить сохранение",
        };
        std::wstring choice = scroll->getUserChoice(choices);

        scroll->display(L"Понял");

        if (choice == L"Начать новую игру")
        {
            scroll->display(L"Начинаем");
        }
        else
        {
            scroll->display(L"Загружаем");
        }
    }
}
