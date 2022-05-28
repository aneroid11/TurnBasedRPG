#ifndef PLAYER_H
#define PLAYER_H

#include "abstractlocation.h"

class Player
{
public:
    Player(AbstractLocation* initialLocation)
    {
        this->currentDestination = initialLocation;
        this->previousLocation = nullptr;
    }

    void displayStatus();

    AbstractLocation* getCurrentLocation() { return this->currentDestination; }

    void goToLocation(AbstractLocation* loc)
    {
        this->previousLocation = this->currentDestination;
        this->currentDestination = loc;
    }

    void goToPreviousLocation()
    {
        std::swap(this->currentDestination, this->previousLocation);
    }

    void setHealth(int health) { this->health = health; }
    int getHealth() const { return this->health; }

    void setGold(int gold) { this->gold = gold; }
    int getGold() const { return this->gold; }

    std::vector<std::wstring> getInventoryItems() const { return this->inventory; }
    std::vector<std::wstring> getEquipmentItems() const { return this->equipment; }

private:
    AbstractLocation* currentDestination;
    AbstractLocation* previousLocation;

    int health = 100;
    int gold = 30;

    std::vector<std::wstring> inventory;
    std::vector<std::wstring> equipment;
};

#endif // PLAYER_H
