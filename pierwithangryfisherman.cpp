#include "pierwithangryfisherman.h"
#include "gamescroll.h"

void PierWithAngryFisherman::action(Player *pl)
{
    GameScroll::getInstance()->placeText(L"Вас встречает явно злой рыбак и говорит вам проваливать с его места");
    FishingPier::action(pl);
}
