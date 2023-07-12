#include <SFML/Graphics.hpp>

#include <iostream>

#include "Game.h"
#include "screen/GameScreen.h"
#include "screen/GameOverScreen.h"
#include "screen/BeginScreen.h"

using namespace sfSnake;

GameOverScreen::GameOverScreen(std::size_t score)
    : score_(score)
{
    text_.setFont(Game::GlobalFont);
    text_.setString(Game::LanList[Game::Lan][GAMEOVER] + std::to_string(score));
    text_.setFillColor(Game::WordColor1);
    text_.setCharacterSize(Game::Width / 15);
    setMiddle(text_);
    text_.setPosition(Game::Width / 2.0f,Game::Height / 6.0f);

    back=Button (
        Game::LanList[Game::Lan][BACK],
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

    quit=Button (
        Game::LanList[Game::Lan][QUIT],
        Game::GlobalFont,
        Game::Width / 20.0,
        Game::WordColor2,
        sf::Vector2f(Game::Width / 6.0f * 5.0f,Game::Height / 3.0f * 2.0f));
}

void GameOverScreen::handleInput(sf::RenderWindow &window)
{
    static sf::Vector2i mousePosition;
    mousePosition = sf::Mouse::getPosition(window);

    back.clear();
    restart.clear();
    quit.clear();

    if (back.contains(mousePosition))
    {
        back.focused();
        if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::mouseButtonCDtime = sf::Time::Zero;
            Game::mouseButtonLocked = true;
            Game::MainScreen = std::make_shared<BeginScreen>();
            return;
        }
    }

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

    if (quit.contains(mousePosition))
    {
        quit.focused();
        if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            window.close();
            return;
        }
    }
}

void GameOverScreen::update(sf::Time delta)
{
}

void GameOverScreen::render(sf::RenderWindow &window)
{
    Game::PauseTitle.render(window);
    window.draw(text_);
    back.render(window);
    restart.render(window);
    quit.render(window);
}