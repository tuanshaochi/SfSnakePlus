#include <SFML/Graphics.hpp>

#include <iostream>

#include "screen/GameScreen.h"
#include "screen/InfoScreen.h"
#include "screen/BeginScreen.h"

#include "Game.h"

using namespace sfSnake;

InfoScreen::InfoScreen()
{
    float characterSize = Game::Width / 25.f;
    text_.setFont(Game::GlobalFont);
    text_.setString(
        Game::LanList[Game::Lan][INFOM]);
    text_.setCharacterSize(Game::Width / 35.0f);
    text_.setFillColor(Game::WordColor1);
    setMiddle(text_);
    text_.setPosition(Game::Width / 2.0, Game::Height / 2.0);

    back=Button (
        Game::LanList[Game::Lan][BACK],
        Game::GlobalFont,
        characterSize,
        Game::NonSeletedColor,
        sf::Vector2f(Game::Width / 10.0f * 1.0f, Game::Height / 10.0f * 1.0f));
}

void InfoScreen::handleInput(sf::RenderWindow& window)
{
    auto mousePosition = sf::Mouse::getPosition(window);

    back.focused();
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
}

void InfoScreen::update(sf::Time delta)
{
}

void InfoScreen::render(sf::RenderWindow& window)
{
    back.render(window);
    window.draw(text_);
}