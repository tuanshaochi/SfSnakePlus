#include "widget/Button.h"

#include "Game.h"
#include <iostream>

using namespace sfSnake;

Button::Button(
    sf::String content,
    sf::Font &font,
    float characterSize,
    sf::Color color,
    sf::Vector2f position)
{
    text_.setFont(font);
    text_.setString(content);
    text_.setCharacterSize(characterSize);
    text_.setFillColor(color);
    setMiddle(text_);
    text_.setPosition(position);

    originColor_ = color;
}

void Button::clear()
{
    text_.setStyle(sf::Text::Regular);
    text_.setFillColor(originColor_);
}

void Button::focused()
{
    text_.setStyle(sf::Text::Underlined);
}

void Button::seleted()
{
    text_.setFillColor(Game::WordColor1);
}

void Button::render(sf::RenderWindow &window)
{
    window.draw(text_);
}
