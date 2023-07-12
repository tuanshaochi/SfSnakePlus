#pragma once

#include <SFML/Graphics.hpp>

namespace sfSnake
{
    class BGimg
    {
    private:
        sf::Texture texture_;
        sf::Sprite imgset_;
        bool rotate_;

    public:
        BGimg(std::string filename);

        void rotate(sf::Time delta);
        void render(sf::RenderWindow &window);
    };
}
