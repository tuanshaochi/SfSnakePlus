#pragma once

#include <SFML/Graphics.hpp>
#include <deque>

#include "screen/Screen.h"
#include "widget/Snake.h"
#include "widget/Fruit.h"
#include "widget/Grid.h"
#include "widget/Button.h"

namespace sfSnake
{
    class GameScreen : public Screen
    {
    public:
        GameScreen();

        void handleInput(sf::RenderWindow &window) override;
        void update(sf::Time delta) override;
        void render(sf::RenderWindow &window) override;

        void generateFruit();

    private:
        Snake snake_;
        std::deque<Fruit> fruit_;
        Grid grid_;

        Button pause;

        sf::Text score_;
        std::vector<sf::Text> count_;
    };
}