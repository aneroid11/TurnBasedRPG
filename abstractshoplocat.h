#ifndef ABSTRACTSHOPLOCAT_H
#define ABSTRACTSHOPLOCAT_H

#include "abstractlocation.h"

#include <map>

class AbstractShopLocat : public AbstractLocation
{
public:
    void action(Player *player) override;

protected:
    std::map<std::wstring, int> prices;

private:
    std::wstring showShop(Player* player);

    std::wstring genSellOption(std::wstring item);
    std::wstring genBuyOption(std::wstring item);
};

#endif // ABSTRACTSHOPLOCAT_H
