#include <SFML/Graphics.hpp>

#include <iostream>

#include "screen/GameScreen.h"
#include "screen/PauseScreen.h"
#include "screen/BGMenuScreen.h"
#include "screen/BeginScreen.h"

using namespace sfSnake;

PauseScreen::PauseScreen()
{

    conti=Button (
        Game::LanList[Game::Lan][CONTI],
        Game::GlobalFont,
        Game::Width / 20.0,
        Game::WordColor2,
        sf::Vector2f(Game::Width / 6.0f * 1.0f,Game::Height / 3.0f * 2.0f));

    restart=Button (
        Game::LanList[Game::Lan][RESTART],
        Game::GlobalFont,
        Game::Width / 20.0,
        Game::WordColor2,
        sf::Vector2f(Game::Width / 6.0f * 3.0f,Game::Height / 3.0f * 2.0f));

    back=Button (
        Game::LanList[Game::Lan][BACK],
        Game::GlobalFont,
        Game::Width / 20.0,
        Game::WordColor2,
        sf::Vector2f(Game::Width / 6.0f * 5.0f,Game::Height / 3.0f * 2.0f));
}

void PauseScreen::handleInput(sf::RenderWindow& window)
{
    auto mousePosition = sf::Mouse::getPosition(window);

    conti.clear();
    restart.clear();
    back.clear();

        if (restart.contains(mousePosition))
        {
            restart.focused();
            if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                Game::mouseButtonCDtime = Game::mouseButtonClock.restart();
                Game::mouseButtonLocked = true;
                Game::MainScreen = std::make_shared<GameScreen>();
                return;
            }
        }

    if (back.contains(mousePosition))
    {
        back.focused();
        if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::mouseButtonCDtime = Game::mouseButtonClock.restart();
            Game::mouseButtonLocked = true;
            Game::MainScreen = std::make_shared<BeginScreen>();
            Game::TmpGameScreen = nullptr;
            return;
        }
    }

    if (conti.contains(mousePosition))
    {
        conti.focused();
        if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::mouseButtonCDtime = Game::mouseButtonClock.restart();
            Game::mouseButtonLocked = true;
            Game::MainScreen = Game::TmpGameScreen;
            Game::TmpGameScreen = nullptr;
            return;
        }
    }

}

void PauseScreen::update(sf::Time delta)
{
}

void PauseScreen::render(sf::RenderWindow& window)
{
    Game::PauseTitle.render(window);
    conti.render(window);
    restart.render(window);
    back.render(window);
}