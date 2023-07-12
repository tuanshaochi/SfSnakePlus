#include <iostream>

#include "widget/BGimg.h"
#include "Game.h"

using namespace sfSnake;

BGimg::BGimg(std::string filename)
    : texture_(), imgset_(), rotate_(true)
{
    texture_.loadFromFile(filename);
    texture_.setSmooth(true);
    imgset_.setTexture(texture_);

    sf::FloatRect titleSpriteBounds = setMiddle(imgset_);
    imgset_.setScale(Game::Width / titleSpriteBounds.width, Game::Width / titleSpriteBounds.width);
    imgset_.setPosition(Game::Width /2,Game::Height / 2);
}

void BGimg::rotate(sf::Time delta)
{
    if (rotate_)
    {
        imgset_.rotate(delta.asSeconds());
        if (imgset_.getRotation() >= 10.0f && imgset_.getRotation() <= 11.0f)
            rotate_ = false;
    }
    else
    {
        imgset_.rotate(-delta.asSeconds());
        if (imgset_.getRotation() >= 349.0f && imgset_.getRotation() <= 350.0f)
            rotate_ = true;
    }
}

void BGimg::render(sf::RenderWindow &window)
{
    window.draw(imgset_);
}