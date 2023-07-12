#pragma once

#include <SFML/Graphics.hpp>

namespace sfSnake
{
    class Grid
    {
    private:
        sf::RectangleShape gridV;   // 竖直线
        sf::RectangleShape gridH;   // 水平线

    public:
        Grid();
        ~Grid() = default;
        void render(sf::RenderWindow &window);
    };
    
    
}