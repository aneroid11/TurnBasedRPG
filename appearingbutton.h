#ifndef APPEARINGBUTTON_H
#define APPEARINGBUTTON_H

#include "appearingobject.h"

#include <Thor/Shapes.hpp>
#include <Thor/Graphics.hpp>

#include <functional>

class AppearingButton : public AppearingObject
{
public:
    AppearingButton(std::wstring str, sf::Font& font, sf::Vector2f position);
    ~AppearingButton() override;

    void update(sf::Event& e, sf::RenderWindow& window) override;
    void setAlpha(unsigned alpha) override;

    sf::Vector2f getSize() const
    {
        return sf::Vector2f(this->background->getGlobalBounds().width,
                            this->background->getGlobalBounds().height);
    }

    //void setClickHandler(std::function<void()> handler) { this->clickHandler = handler; }

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    AppearingButton(const AppearingButton& other) = delete;

    sf::Text* text = nullptr;
    sf::ConvexShape* background = nullptr;

    //std::function<void()> clickHandler;

    bool clicked;
};

#endif // APPEARINGBUTTON_H
