#ifndef SCREENOBJECT_H
#define SCREENOBJECT_H

#include <SFML/Graphics.hpp>

class ScreenObject
{
public:
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow* window) = 0;
};

#endif // SCREENOBJECT_H
