#include <SFML/Graphics.hpp>

#include "Fruit.h"
#include "Game.h"

using namespace sfSnake;

Fruit::Fruit(sf::Vector2f position, sf::Color color, int score,int cidx)
    : score_(score),cidx_(cidx)
{
    shape_.setRadius(Game::Width / 256.0f);
    setMiddle(shape_);
    shape_.setPosition(position);
    shape_.setFillColor(color);
}

void Fruit::render(sf::RenderWindow &window)
{
    window.draw(shape_);
}

sf::CircleShape sfSnake::Fruit::getShape() const
{
    return shape_;
}

int sfSnake::Fruit::getScore() const
{
    return score_;
}

int sfSnake::Fruit::getCidx() const
{
    return cidx_;
}
