#include "game.h"
#include "gamescroll.h"
#include "mainmenu.h"

Game::Game()
{
    GameScroll::getInstance();
}

Game::~Game()
{
    GameScroll::deleteInstance();
}

void Game::run()
{
    MainMenu* menu = new MainMenu();
    delete menu;

    GameScroll* scroll = GameScroll::getInstance();

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
