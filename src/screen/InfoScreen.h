#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "screen/Screen.h"
#include "widget/Button.h"

namespace sfSnake
{
    class InfoScreen : public Screen
    {
    public:
        InfoScreen();

        void handleInput(sf::RenderWindow& window) override;
        void update(sf::Time delta) override;
        void render(sf::RenderWindow& window) override;

    private:
        sf::Text text_;

        Button back;
    };
}