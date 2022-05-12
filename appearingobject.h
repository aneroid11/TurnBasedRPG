#ifndef APPEARINGOBJECT_H
#define APPEARINGOBJECT_H

#include "screenobject.h"

class AppearingObject : public ScreenObject
{
public:
    AppearingObject(float secondsToAppear = 0.2f);
    ~AppearingObject() override {}

    void update(sf::Event& e, sf::RenderWindow& window) override;
    virtual void setAlpha(unsigned alpha) = 0;

protected:
    sf::Clock fromCreation;
    float secondsToAppear;
};

#endif // APPEARINGOBJECT_H
