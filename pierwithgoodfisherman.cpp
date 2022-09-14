#include "pierwithgoodfisherman.h"
#include "gamescroll.h"

void PierWithGoodFisherman::action(Player *pl)
{
    GameScroll* scroll = GameScroll::getInstance();

    scroll->placeText(L"На этом пирсе вы встречаете дружелюбного рыбака. Он говорит, что для рыбалки нужна удочка и черви.");
    scroll->placeText(L"Пойманную рыбу можно съесть, чтобы восполнить здоровье, или продать в Zdras Shop");

    FishingPier::action(pl);
}
