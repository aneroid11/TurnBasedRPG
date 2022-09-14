#ifndef INVENTORY_H
#define INVENTORY_H

#include "abstractlocation.h"

class Inventory : public AbstractLocation
{
public:
    std::wstring getName() override
    {
        return L"Снаряжение и инвентарь";
    }

    void action(Player* player) override;

private:
    std::wstring showInventory(Player* player);
};

#endif // INVENTORY_H
