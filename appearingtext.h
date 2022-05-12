#ifndef APPEARINGTEXT_H
#define APPEARINGTEXT_H

#include "appearingobject.h"

struct TextParameters
{
    sf::String string;
    sf::Font font;
    unsigned int characterSize;
    sf::Vector2f position;
};

class AppearingText : public AppearingObject
{
public:
    AppearingText(const TextParameters& params);
    ~AppearingText() override {}

    void draw(sf::RenderWindow* window) override;
    void setAlpha(unsigned alpha) override;

    sf::Text getText() const { return this->text; }

    void setPosition(float x, float y) { text.setPosition(x, y); }

private:
    sf::Text text;
};

#endif // APPEARINGTEXT_H
