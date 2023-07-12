#pragma once

#include <SFML/Graphics.hpp>

namespace sfSnake
{
    class Button
    {
    private:
        sf::Text text_;
        sf::Color originColor_;

    public:
        Button(sf::String content,
            sf::Font& font,
            float characterSize,
            sf::Color color,
            sf::Vector2f position);
        Button(){};
        ~Button() = default;

        void settext(sf::String t) {
            text_.setString(t);
        }
        void clear();
        void focused();
        void seleted();

        void render(sf::RenderWindow &window);

        template <typename T>
        bool contains(sf::Vector2<T> point);
    };

    template <typename T>
    bool Button::contains(sf::Vector2<T> point)
    {
        return text_.getGlobalBounds().contains(static_cast<sf::Vector2f>(point));
    }
}