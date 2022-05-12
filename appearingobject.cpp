#include "appearingobject.h"

AppearingObject::AppearingObject(float secondsToAppear)
{
    this->secondsToAppear = secondsToAppear;
    this->fromCreation.restart();
}

void AppearingObject::update()
{
    float alphaCoef = this->fromCreation.getElapsedTime().asSeconds() / this->secondsToAppear;
    unsigned currentAlpha = 255 * alphaCoef;

    if (currentAlpha > 255) { currentAlpha = 255; }

    this->setAlpha(currentAlpha);
}
