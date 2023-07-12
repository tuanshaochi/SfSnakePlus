#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

#include "screen/Screen.h"
#include "widget/Button.h"
#include "Game.h"



namespace sfSnake
{
    class PauseScreen : public Screen
    {
    public:
        PauseScreen();

        void handleInput(sf::RenderWindow& window) override;
        void update(sf::Time delta) override;
        void render(sf::RenderWindow& window) override;

    private:
        Button conti;
        Button restart;
        Button back;
    };
}