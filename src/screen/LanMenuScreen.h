#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

#include "screen/Screen.h"
#include "widget/Button.h"

namespace sfSnake
{
    class LanMenuScreen : public Screen
    {
    public:
        LanMenuScreen();

        void handleInput(sf::RenderWindow& window) override;
        void update(sf::Time delta) override;
        void render(sf::RenderWindow& window) override;

    private:
        std::vector<Button> LanOptions_;

        int Lanfocused_;

        Button back;
    };
}