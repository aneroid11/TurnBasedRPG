#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game();
    ~Game();

    void run();

    void runDriver();

    bool saveFileExists() const;
};

#endif // GAME_H
