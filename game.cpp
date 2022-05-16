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

bool Game::saveFileExists() const
{
    // TODO: check if the save file (player.json) exists.
    return true;
}

// runs the main game loop.
// main game loop is HERE.
// this method should receive player as a parameter.
void Game::runDriver()
{

}

void Game::run()
{
    MainMenu* menu = new MainMenu();
    delete menu;

    GameScroll* scroll = GameScroll::getInstance();

    if (saveFileExists())
    {
        scroll->display(L"Загрузить сохранение?");
        std::list<std::wstring> choices = { L"Да", L"Нет" };
        std::wstring choice = scroll->getUserChoice(choices);

        if (choice == L"Да")
        {
            scroll->display(L"Загружаем...");

            // Load the save file.
        }
    }

    GameScroll::deleteInstance();

    /*while (true)
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
    }*/
}
