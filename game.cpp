#include "game.h"
#include "gamescroll.h"

#include "player.h"
#include "homelocat.h"
#include "inventory.h"
#include "casinolocat.h"

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

AbstractLocation* Game::selectNextLocation(Player *pl)
{
    this->scroll->addScreenText({L"text", L"Варианты локаций для перехода:"});

    std::vector<AbstractLocation*> possibleLocs = pl->getCurrentLocation()->getPossibleLocations();

    for (AbstractLocation* loc : possibleLocs)
    {
        this->scroll->addScreenText({L"button", loc->getName()});
    }

    const std::wstring name = this->scroll->displayAddedObjectsAndChoice();

    for (AbstractLocation* loc : possibleLocs)
    {
        if (name == loc->getName())
        {
            return loc;
        }
    }
    return possibleLocs[0];
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
        locations[L"Казино"] = new CasinoLocat();

        locations[L"Дом"]->setPossibleLocations({
                                                    locations[L"Инвентарь"],
                                                    locations[L"Казино"]
                                                });
        locations[L"Казино"]->setPossibleLocations({
                                                       locations[L"Инвентарь"],
                                                       locations[L"Дом"]
                                                   });

        Player* player = new Player(locations[L"Дом"]);

        while (true)
        {
            AbstractLocation* destination = this->selectNextLocation(player);
            player->goToLocation(destination);

            player->displayStatus();
            player->getCurrentLocation()->action(player);
        }

        delete player;
        for (auto locPair : locations)
        {
            delete locPair.second;
        }
    }
}
