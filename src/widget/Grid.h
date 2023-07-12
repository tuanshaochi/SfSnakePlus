#pragma once

#include <SFML/Graphics.hpp>

namespace sfSnake
{
    class Grid
    {
    private:
        sf::RectangleShape gridV;   // ��ֱ��
        sf::RectangleShape gridH;   // ˮƽ��

    public:
        Grid();
        ~Grid() = default;
        void render(sf::RenderWindow &window);
    };
    
    
}