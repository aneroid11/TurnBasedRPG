#ifndef SCREENOBJECT_H
#define SCREENOBJECT_H

#include <SFML/Graphics.hpp>

class ScreenObject : public sf::Drawable
{
public:
    virtual ~ScreenObject() {}

    virtual void update() = 0;
};

#endif // SCREENOBJECT_H
