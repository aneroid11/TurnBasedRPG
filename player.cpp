#include "player.h"
#include "gamescroll.h"

void Player::displayStatus()
{
    GameScroll* scroll = GameScroll::getInstance();

    std::wstring text = L"Вы находитесь в [";
    text += this->getCurrentLocation()->getName();
    text += L"].\n";
    text += L"Золото: " + std::to_wstring(this->getGold());
    text += L"\nЗдоровье: " + std::to_wstring(this->getHealth());
    scroll->addScreenText({L"text", text});
}
