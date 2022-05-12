#ifndef APPEARINGTEXT_H
#define APPEARINGTEXT_H

#include "screenobject.h"

struct TextParameters
{
    sf::String string;
    sf::Font font;
    unsigned int characterSize;
    sf::Vector2f position;
};

class AppearingText : public ScreenObject
{
public:
    AppearingText(const TextParameters& params);
    ~AppearingText() override {}

    void update() override;
    void draw(sf::RenderWindow* window) override;

    sf::Text getText() const { return this->text; }

private:
    sf::Text text;
    sf::Clock clockSinceCreated;

    float secondsToAppear;
};

#endif // APPEARINGTEXT_H
