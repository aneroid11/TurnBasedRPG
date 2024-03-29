#include "game.h"
#include "gamescroll.h"

#include "player.h"
#include "homelocat.h"
#include "inventory.h"
#include "casinolocat.h"
#include "toolsshoplocat.h"
#include "zdrasshoplocat.h"
#include "citygatelocat.h"
#include "fieldlocat.h"
#include "hilllocat.h"
#include "forestlocat.h"
#include "pierwithangryfisherman.h"
#include "pierwithgoodfisherman.h"
#include "pierwithenglishman.h"
#include "baywithboatlocat.h"

#include <fstream>
#include <sstream>
#include <map>

Game::Game()
{
    srand(time(nullptr));
    this->scroll = GameScroll::getInstance();
}

Game::~Game()
{
    GameScroll::deleteInstance();
}

std::string readAllText(std::ifstream& in)
{
    std::ostringstream sstr;
    sstr << in.rdbuf();
    return sstr.str();
}

void Game::save(Player *pl)
{
    std::ofstream out("resources/.svpl.json");
    out << pl->serializeToJson().dump(2);
    out.close();

    scroll->placeText(L"Игра сохранена");
}

void Game::load(Player *pl)
{
    std::ifstream in("resources/.svpl.json");
    std::string str = readAllText(in);
    json plJson = json::parse(str);

    if (!pl->deserializeFromJson(plJson))
    {
        scroll->placeText(L"Сохранение было повреждено, поэтому его не удалось загрузить");
        return;
    }

    scroll->placeText(L"Сохранение загружено");
}

bool Game::saveFileExists() const
{
    std::ifstream in("resources/.svpl.json");
    return in.is_open();
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

void Game::showNewGameMsg()
{
    scroll->placeText(L"Вы попали на островной город и находитесь в каком-то доме. Вам нужно уплыть с острова.");
    scroll->placeText(L"Вы начинаете с 30 золотыми монетами. В ближайших магазинах вы можете купить за них полезные вещи.");
    scroll->placeText(L"Получить деньги можно разными способами, например, продать что-нибудь. За городом вы можете "
                      L"найти места, в которых можно получить предметы на продажу.");
    scroll->placeText(L"Не забывайте, что ваши здоровье и инвентарь не бесконечные. Вы не можете нести более 10 предметов в "
                      L"инвентаре, а за городом могут встретиться враги.");
    scroll->placeText(L"Удачи!");
}

void Game::run()
{
    this->scroll->placeOption(L"Начать новую игру");

    if (saveFileExists())
    {
        this->scroll->placeOption(L"Загрузить сохранение");
    }

    this->scroll->placeOption(L"Не начинать");

    std::wstring choice = this->scroll->displayAddedObjectsAndChoice();

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
        locations[L"Магазин инструментов"] = new ToolsShopLocat();
        locations[L"Zdras Shop"] = new ZdrasShopLocat();
        locations[L"Выход из города"] = new CityGateLocat();
        locations[L"Поле"] = new FieldLocat();
        locations[L"Лес"] = new ForestLocat();
        locations[L"Холм"] = new HillLocat();
        locations[L"Пирс 1"] = new PierWithAngryFisherman();
        locations[L"Пирс 2"] = new PierWithGoodFisherman();
        locations[L"Пирс 3"] = new PierWithEnglishman();
        locations[L"Бухта"] = new BayWithBoatLocat();

        locations[L"Дом"]->setPossibleLocations({
                                                    locations[L"Инвентарь"],
                                                    locations[L"Казино"],
                                                    locations[L"Магазин инструментов"],
                                                    locations[L"Zdras Shop"],
                                                    locations[L"Выход из города"]
                                                });
        locations[L"Казино"]->setPossibleLocations({
                                                       locations[L"Инвентарь"],
                                                       locations[L"Дом"],
                                                       locations[L"Магазин инструментов"],
                                                       locations[L"Zdras Shop"],
                                                       locations[L"Выход из города"]
                                                   });
        locations[L"Магазин инструментов"]->setPossibleLocations({
                                                                     locations[L"Инвентарь"],
                                                                     locations[L"Дом"],
                                                                     locations[L"Казино"],
                                                                     locations[L"Zdras Shop"],
                                                                     locations[L"Выход из города"]
                                                                 });
        locations[L"Zdras Shop"]->setPossibleLocations({
                                                           locations[L"Инвентарь"],
                                                           locations[L"Дом"],
                                                           locations[L"Казино"],
                                                           locations[L"Магазин инструментов"],
                                                           locations[L"Выход из города"]
                                                       });
        locations[L"Выход из города"]->setPossibleLocations({
                                                                locations[L"Инвентарь"],
                                                                locations[L"Дом"],
                                                                locations[L"Казино"],
                                                                locations[L"Магазин инструментов"],
                                                                locations[L"Zdras Shop"],
                                                                locations[L"Поле"]
                                                            });
        locations[L"Поле"]->setPossibleLocations({
                                                     locations[L"Инвентарь"],
                                                     locations[L"Выход из города"],
                                                     locations[L"Лес"]
                                                 });
        locations[L"Лес"]->setPossibleLocations({
                                                    locations[L"Инвентарь"],
                                                    locations[L"Поле"],
                                                    locations[L"Холм"]
                                                });
        locations[L"Холм"]->setPossibleLocations({
                                                     locations[L"Инвентарь"],
                                                     locations[L"Лес"],
                                                     locations[L"Пирс 1"]
                                                 });
        locations[L"Пирс 1"]->setPossibleLocations({
                                                       locations[L"Инвентарь"],
                                                       locations[L"Холм"],
                                                       locations[L"Пирс 2"]
                                                   });
        locations[L"Пирс 2"]->setPossibleLocations({
                                                       locations[L"Инвентарь"],
                                                       locations[L"Пирс 1"],
                                                       locations[L"Пирс 3"]
                                                   });
        locations[L"Пирс 3"]->setPossibleLocations({
                                                       locations[L"Инвентарь"],
                                                       locations[L"Пирс 2"],
                                                       locations[L"Бухта"]
                                                   });
        locations[L"Бухта"]->setPossibleLocations({
                                                      locations[L"Инвентарь"],
                                                      locations[L"Пирс 3"]
                                                  });

        Player* player = new Player(locations[L"Дом"]);

        if (choice == L"Загрузить сохранение")
        {
            load(player);
        }
        else
        {
            showNewGameMsg();
        }

        while (true)
        {
            AbstractLocation* destination = this->selectNextLocation(player);
            player->goToLocation(destination);

            player->displayStatus();
            player->getCurrentLocation()->action(player);

            if (player->getCurrentLocation()->getName() == L"Дом")
            {
                save(player);
            }
        }

        delete player;
        for (auto locPair : locations)
        {
            delete locPair.second;
        }
    }
}
