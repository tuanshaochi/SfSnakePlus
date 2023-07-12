#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "screen/Screen.h"
#include "screen/GameScreen.h"
#include "widget/Grid.h"
#include "widget/Button.h"

namespace sfSnake
{
    class BGMenuScreen : public Screen
    {
    public:
        BGMenuScreen();

        void handleInput(sf::RenderWindow &window) override;
        void update(sf::Time delta) override;
        void render(sf::RenderWindow &window) override;

    private:
        std::vector<Button> optionName_;
        std::vector<Button> GridOptions_;
        std::vector<Button> BGColorOptions_;
        std::vector<Button> SkinOptions_;

        int Gridfocused_;
        int BGColorfocused_;
        int Skinfocused_;

        Grid grid_;

        Button back;
    };
}