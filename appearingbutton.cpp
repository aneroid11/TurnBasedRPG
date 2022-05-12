#include "appearingbutton.h"

AppearingButton::AppearingButton(std::wstring str, sf::Font& font, sf::Vector2f position)
    : AppearingObject(0.2f), text(str, font)
{
    sf::Vector2f textSize = sf::Vector2f(text.getGlobalBounds().width, text.getGlobalBounds().height);
    float bgScaleCoef = 1.5f;
    sf::Vector2f bgSize = sf::Vector2f(textSize.x * bgScaleCoef, textSize.y * bgScaleCoef);
    this->background = thor::Shapes::roundedRect(bgSize, 3.0f, sf::Color(100, 100, 100),
                                                 1.0f, sf::Color(100, 100, 100));

    this->background.setOrigin(this->background.getGlobalBounds().width / 2,
                               0);
    this->background.setPosition(position);

    this->text.setOrigin(this->text.getGlobalBounds().width/2,
                         0);
    this->text.setPosition(position);

    this->text.setFillColor(sf::Color(200, 200, 200));
    this->text.setOutlineThickness(1.0f);
    this->text.setOutlineColor(sf::Color(200, 200, 200));
}

AppearingButton::~AppearingButton()
{
}

void AppearingButton::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->background, states);
    target.draw(this->text, states);
}

void AppearingButton::update(sf::Event& e, sf::RenderWindow& window)
{
    AppearingObject::update(e, window);
}

void AppearingButton::setAlpha(unsigned alpha)
{
    sf::Color bgColor = this->background.getFillColor();
    sf::Color textColor = this->text.getFillColor();

    this->background.setFillColor(sf::Color(bgColor.r, bgColor.g, bgColor.b, alpha));
    this->background.setOutlineColor(sf::Color(bgColor.r, bgColor.g, bgColor.b, alpha));

    this->text.setFillColor(sf::Color(textColor.r, textColor.g, textColor.b, alpha));
    this->text.setOutlineColor(sf::Color(textColor.r, textColor.g, textColor.b, alpha));
}
