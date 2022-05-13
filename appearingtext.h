#ifndef APPEARINGTEXT_H
#define APPEARINGTEXT_H

#include "appearingobject.h"

struct TextParameters
{
    sf::String string;
    sf::Font* font;
    unsigned int characterSize;
    sf::Vector2f position;
};

class AppearingText : public AppearingObject
{
public:
    AppearingText(TextParameters params);
    ~AppearingText() override;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void setAlpha(unsigned alpha) override;

    sf::Text getText() const { return *this->text; }

    void setPosition(float x, float y) { text->setPosition(x, y); }

private:
    AppearingText(const AppearingText& other) = delete;

    sf::Text* text = nullptr;
};

#endif // APPEARINGTEXT_H
