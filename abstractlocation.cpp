#include "abstractlocation.h"

void AbstractLocation::setPossibleLocations(const std::vector<AbstractLocation *> possibleDests)
{
    this->possibleLocations = possibleDests;
}
