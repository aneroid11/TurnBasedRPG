#ifndef GAME_H
#define GAME_H

#include "gamescroll.h"

class Game
{
public:
    Game();
    ~Game();

    void run();

private:
    void runDriver();

    bool saveFileExists() const;

    GameScroll* scroll = nullptr;
};

#endif // GAME_H
