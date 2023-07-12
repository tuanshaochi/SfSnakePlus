#pragma once

#include <SFML/Graphics.hpp>

namespace sfSnake
{
    class Fruit
    {
        sf::CircleShape shape_;
        int score_;
        int cidx_;
    public:
        Fruit(sf::Vector2f position, sf::Color color, int score,int cidx);

        void render(sf::RenderWindow &window);

        sf::CircleShape getShape() const;
        int getScore() const;
        int getCidx() const;
    };
}