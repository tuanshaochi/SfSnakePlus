#pragma once

#include <SFML/Graphics.hpp>

#include "screen/Screen.h"
#include "widget/Button.h"

#include <vector>

namespace sfSnake
{
    class BeginScreen : public Screen
    {
    public:
        BeginScreen();

        void handleInput(sf::RenderWindow &window) override;
        void update(sf::Time delta) override;
        void render(sf::RenderWindow &window) override;

    private:
        Button play;
        Button bgmenu;
        Button lanmenu;
        Button info;
        Button quit;

    };
}