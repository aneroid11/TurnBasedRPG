#ifndef PLAYER_H
#define PLAYER_H

#include "abstractlocation.h"
#include "nlohmann/json.hpp"

#include <algorithm>

using json = nlohmann::json;

class Player
{
public:
    Player(AbstractLocation* initialLocation)
    {
        this->currentDestination = initialLocation;
        this->previousLocation = nullptr;
    }

    json serializeToJson() const;
    void deserializeFromJson(json j);

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

    void die(std::wstring msg = L"");

    void heal(int addHp)
    {
        this->health += addHp;

        if (this->health > 100) { this->health = 100; }
    }

    void damage(int dmg, std::wstring deathMsg = L"");

    void damageNotKill(int dmg)
    {
        this->health -= dmg;

        if (this->health <= 0) { this->health = 1; }
    }

    int getHealth() const { return this->health; }

    void setGold(int gold) { this->gold = gold; }
    int getGold() const { return this->gold; }

    std::vector<std::wstring> getInventoryItems() const { return this->inventory; }
    std::vector<std::wstring> getEquipmentItems() const { return this->equipment; }

    void addToInventory(std::wstring item) { this->inventory.push_back(item); }
    void addToEquipment(std::wstring item) { this->equipment.push_back(item); }

    void deleteFromInventory(std::wstring item)
    {
        this->inventory.erase(std::find(this->inventory.begin(),
                                        this->inventory.end(),
                                        item));
    }

    void deleteFromEquipment(std::wstring item)
    {
        this->equipment.erase(std::find(this->equipment.begin(),
                                        this->equipment.end(),
                                        item));
    }

    bool hasInInventory(std::wstring item)
    {
        return std::count(this->inventory.begin(),
                          this->inventory.end(),
                          item);
    }

    bool hasEquipped(std::wstring item)
    {
        return std::count(this->equipment.begin(),
                          this->equipment.end(),
                          item);
    }

private:
    AbstractLocation* currentDestination;
    AbstractLocation* previousLocation;

    int health = 100;
    int gold = 30;

    std::vector<std::wstring> inventory;
    std::vector<std::wstring> equipment;
};

#endif // PLAYER_H
