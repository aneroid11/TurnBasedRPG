#ifndef GAME_H
#define GAME_H

#include "gamescroll.h"
#include "abstractlocation.h"

class Game
{
public:
    Game();
    ~Game();

    void run();

private:
    void save(Player* pl);
    void load(Player* pl);
    bool saveFileExists() const;
    AbstractLocation* selectNextLocation(Player* pl);

    GameScroll* scroll = nullptr;
};

#endif // GAME_H
