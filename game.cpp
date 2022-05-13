#include "game.h"
#include "gamescroll.h"

Game::Game()
{

}

void Game::run()
{
    GameScroll* scroll = GameScroll::getInstance();

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

    GameScroll::deleteInstance();
}
