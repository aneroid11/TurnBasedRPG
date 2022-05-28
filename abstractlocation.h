#ifndef ABSTRACTLOCATION_H
#define ABSTRACTLOCATION_H

#include <vector>
#include <string>

class AbstractLocation
{
public:
    std::vector<AbstractLocation *> getPossibleLocations() const
    {
        return this->possibleLocations;
    }

    void setPossibleLocations(const std::vector<AbstractLocation *> possibleDests);

    virtual std::wstring getName() = 0;
    virtual void action() = 0;

protected:
    std::vector<AbstractLocation *> possibleLocations;
};

#endif // ABSTRACTLOCATION_H
