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

// runs the main game loop.
// main game loop is HERE.
// this method should receive player as a parameter.
void Game::runDriver()
{
    for (int i = 0; i < 10; i++)
    {
        this->scroll->display(L"Игровое сообщение");
    }
}

void Game::run()
{
    //MainMenu* menu = new MainMenu();
    //delete menu;

    if (this->saveFileExists())
    {
        this->scroll->display(L"Загрузить сохранение?");
        std::list<std::wstring> choices = { L"Да", L"Нет" };
        std::wstring choice = this->scroll->getUserChoice(choices);

        if (choice == L"Да")
        {
            this->scroll->display(L"Загружаем...");

            // Load the save file here.
        }
    }

    this->runDriver();

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
