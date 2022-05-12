#ifndef APPEARINGBUTTON_H
#define APPEARINGBUTTON_H

#include "appearingobject.h"

namespace style
{
enum
{
    none = 0,
    save = 1,
    cancel = 2,
    clean = 3,
};
}

namespace state
{
enum
{
    normal = 0,
    hovered = 1,
    clicked = 2
};
}

class AppearingButton : public AppearingObject
{
public:
    AppearingButton();
    AppearingButton(std::wstring s, sf::Font& font, sf::Vector2f position, sf::Uint32 style);

    ~AppearingButton() override;

    void setColorTextNormal(sf::Color text) { m_textNormal = text; }
    void setColorTextHover(sf::Color text) {m_textHover = text; }
    void setColorTextClicked(sf::Color text) { m_textClicked = text; }
    void setColorNormal(sf::Color bgNormal) {m_bgNormal = bgNormal; }
    void setColorHover(sf::Color bgHover){ m_bgHover = bgHover; }
    void setColorClicked(sf::Color bgClicked) { m_bgClicked = bgClicked; }
    void setBorderColor(sf::Color border) { m_border = border; }
    void setBorderThickness(float t) { m_borderThickness = t; }
    void setBorderRadius(float r) { m_borderRadius = r; }
    void setPosition(sf::Vector2f position) { m_position = position; }
    void setSize(unsigned int size);

    void setText(std::wstring s)
    {
        m_text.setString(s);
        m_shadow = m_text;
    }

    void setStyle(sf::Uint32 style);
    void setFont(sf::Font& font);

    sf::Vector2f getPosition() { return m_position; }
    sf::Vector2f getDimensions() { return sf::Vector2f(m_button.getGlobalBounds().width, m_button.getGlobalBounds().height); }
    sf::Uint32 getState() { return m_btnstate; }

    void update(sf::Event& e, sf::RenderWindow& window) override;

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::Color m_bgNormal;
    sf::Color m_bgHover;
    sf::Color m_bgClicked;
    sf::Color m_textNormal;
    sf::Color m_textHover;
    sf::Color m_textClicked;
    sf::Color m_border;

    float m_borderThickness;
    float m_borderRadius;
    sf::Vector2f m_size;
    sf::Vector2f m_position;
    sf::Uint32 m_style;
    sf::Uint32 m_btnstate;

    sf::ConvexShape m_button;
    sf::Font m_font;
    unsigned int m_fontSize;
    sf::Text m_text;
    sf::Text m_shadow;
};

#endif // APPEARINGBUTTON_H
