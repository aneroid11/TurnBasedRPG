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
    //Console.WriteLine("Вы попали на островной город и находитесь в каком-то доме. Вам нужно уплыть с острова. Удачи!");

    std::vector< std::array<std::wstring, 2> > screenText {
        { L"text", L"Вы попали на островной город и находитесь \nв каком-то доме. Вам нужно уплыть с острова. \nУдачи!"},
        { L"button", L"Начать" }
    };

    this->scroll->displayAndWaitForChoice(screenText);
}
