#include "appearingobject.h"
#include <iostream>

AppearingObject::AppearingObject(float secondsToAppear)
{
    this->secondsToAppear = secondsToAppear;
    this->fromCreation.restart();
}

void AppearingObject::update(sf::Event& ev, sf::RenderWindow& window)
{
    std::cout << "AppearingObject::update()\n";

    (void)ev;
    (void)window;

    float alphaCoef = this->fromCreation.getElapsedTime().asSeconds() / this->secondsToAppear;
    unsigned currentAlpha = 255 * alphaCoef;

    if (currentAlpha > 255) { currentAlpha = 255; }

    this->setAlpha(currentAlpha);
}
