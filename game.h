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
    bool saveFileExists() const;
    AbstractLocation* selectNextLocation(Player* pl);

    GameScroll* scroll = nullptr;
};

#endif // GAME_H
