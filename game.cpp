#include "game.h"
#include "gamescroll.h"

#include "player.h"
#include "abstractlocation.h"
#include "homelocat.h"
#include "inventory.h"

#include <map>

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

    std::vector< std::array<std::wstring, 2> > screenText
    {
        { L"text", L"Вы попали на островной город и находитесь \nв каком-то доме. Вам нужно уплыть с острова. \nУдачи!"},
        { L"button", L"Начать" },
        { L"button", L"Не начинать" }
    };

    std::wstring choice = this->scroll->displayAndWaitForChoice(screenText);

    if (choice == L"Не начинать")
    {
        std::vector< std::array<std::wstring, 2> > screenText2
        {
            { L"text", L"Мудрое решение."},
            { L"button", L"Да" }
        };
        this->scroll->displayAndWaitForChoice(screenText2);
    }
    else
    {
        std::map<std::wstring, AbstractLocation*> locations;
        locations[L"Дом"] = new HomeLocat();
        locations[L"Инвентарь"] = new Inventory();

        locations[L"Дом"]->setPossibleLocations({locations[L"Инвентарь"]});

        Player* player = new Player(locations[L"Дом"]);

        while (true)
        {
            AbstractLocation* destination = this->selectNextLocation(player);
            player->goToLocation(destination);
            player->getCurrentLocation()->action(player);
        }

        delete player;
        for (auto locPair : locations)
        {
            delete locPair.second;
        }
    }
}
