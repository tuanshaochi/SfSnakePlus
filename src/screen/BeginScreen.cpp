#include <SFML/Graphics.hpp>

#include <iostream>

#include "screen/GameScreen.h"
#include "screen/BeginScreen.h"
#include "screen/BGMenuScreen.h"
#include "screen/LanMenuScreen.h"
#include "screen/InfoScreen.h"
#include "Game.h"

using namespace sfSnake;

BeginScreen::BeginScreen()
{
    Game::GlobalFont.loadFromFile("assets/fonts/SourceHanSansSC-Bold.otf");

    play=Button(
        Game::LanList[Game::Lan][PLAY],
        Game::GlobalFont,
        Game::Width / 20.0,
        Game::WordColor2,
        sf::Vector2f(Game::Width /2.0f,Game::Height / 7.0f * 2.0f));

    bgmenu = Button(
        Game::LanList[Game::Lan][BGMENU],
        Game::GlobalFont,
        Game::Width / 20.0,
        Game::WordColor2,
        sf::Vector2f(Game::Width / 2.0f,Game::Height / 7.0f * 3.0f));

    lanmenu = Button(
        Game::LanList[Game::Lan][LAN],
        Game::GlobalFont,
        Game::Width / 20.0,
        Game::WordColor2,
        sf::Vector2f(Game::Width / 2.0f,Game::Height / 7.0f * 4.0f));

    info=Button (
        Game::LanList[Game::Lan][INFO],
        Game::GlobalFont,
        Game::Width / 20.0,
        Game::WordColor2,
        sf::Vector2f(Game::Width / 2.0f, Game::Height / 7.0f * 5.0f));

    quit=Button (
        Game::LanList[Game::Lan][QUIT],
        Game::GlobalFont,
        Game::Width / 20.0,
        Game::WordColor2,
        sf::Vector2f(Game::Width /2.0f,Game::Height / 7.0f * 6.0f));
}

void BeginScreen::handleInput(sf::RenderWindow &window)
{
    static sf::Vector2i mousePosition;
    mousePosition = sf::Mouse::getPosition(window);

    bgmenu.clear();
    lanmenu.clear();
    play.clear();
    info.clear();
    quit.clear();

    if (bgmenu.contains(mousePosition))
    {
        bgmenu.focused();
        if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::mouseButtonCDtime = sf::Time::Zero;
            Game::mouseButtonLocked = true;
            Game::MainScreen = std::make_shared<BGMenuScreen>();
            return;
        }
    }

    if (lanmenu.contains(mousePosition))
    {
        lanmenu.focused();
        if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::mouseButtonCDtime = sf::Time::Zero;
            Game::mouseButtonLocked = true;
            Game::MainScreen = std::make_shared<LanMenuScreen>();
            return;
        }
    }

    if (play.contains(mousePosition))
    {
        play.focused();
        if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::mouseButtonLocked = true;
            Game::mouseButtonCDtime = sf::Time::Zero;
            Game::MainScreen = std::make_shared<GameScreen>();
            return;
        }
    }

    if (info.contains(mousePosition))
    {
        info.focused();
        if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::mouseButtonLocked = true;
            Game::mouseButtonCDtime = sf::Time::Zero;
            Game::MainScreen = std::make_shared<InfoScreen>();
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

void BeginScreen::update(sf::Time delta)
{
    Game::GlobalTitle.rotate(delta);
}

void BeginScreen::render(sf::RenderWindow &window)
{
    Game::GlobalTitle.render(window);
    bgmenu.render(window);
    lanmenu.render(window);
    play.render(window);
    info.render(window);
    quit.render(window);
}