#include "screen/LanMenuScreen.h"
#include "screen/BeginScreen.h"

#include "Game.h"
#include <iostream>

using namespace sfSnake;

LanMenuScreen::LanMenuScreen()
    :
    LanOptions_(5),
    Lanfocused_(-1),
    back()
{
    float characterSize = Game::Width / 25.f;

    LanOptions_[0]=Button (
        L"简体中文",
        Game::GlobalFont,
        characterSize,
        Game::NonSeletedColor,
        sf::Vector2f(Game::Width / 2.0f,Game::Height / 6.0f * 1.0f));
    LanOptions_[1]=Button (
        L"繁體中文",
        Game::GlobalFont,
        characterSize,
        Game::NonSeletedColor,
        sf::Vector2f(Game::Width / 2.0f,Game::Height / 6.0f * 2.0f));
    LanOptions_[2]=Button (
        L"English",
        Game::GlobalFont,
        characterSize,
        Game::NonSeletedColor,
        sf::Vector2f(Game::Width / 2.0f,Game::Height / 6.0f * 3.0f));
    LanOptions_[3]=Button (
        L"日本語",
        Game::GlobalFont,
        characterSize,
        Game::NonSeletedColor,
        sf::Vector2f(Game::Width / 2.0f,Game::Height / 6.0f * 4.0f));
    LanOptions_[4]=Button (
        L"한국어",
        Game::GlobalFont,
        characterSize,
        Game::NonSeletedColor,
        sf::Vector2f(Game::Width / 2.0f,Game::Height / 6.0f * 5.0f));
    back=Button (
        Game::LanList[Game::Lan][BACK],
        Game::GlobalFont,
        characterSize,
        Game::NonSeletedColor,
        sf::Vector2f(Game::Width / 10.0f * 1.0f,Game::Height / 10.0f * 1.0f));
}

void LanMenuScreen::handleInput(sf::RenderWindow& window)
{
    auto mousePosition = sf::Mouse::getPosition(window);

    if (LanOptions_[0].contains(mousePosition))
    {
        Lanfocused_ = 0;
        if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::Lan = 0;
            return;
        }
    }
    if (LanOptions_[1].contains(mousePosition))
    {
        Lanfocused_ = 1;
        if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::Lan = 1;
            return;
        }
    }
    if (LanOptions_[2].contains(mousePosition))
    {
        Lanfocused_ = 2;
        if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::Lan = 2;
            return;
        }
    }
    if (LanOptions_[3].contains(mousePosition))
    {
        Lanfocused_ = 3;
        if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::Lan = 3;
            return;
        }
    }
    if (LanOptions_[4].contains(mousePosition))
    {
        Lanfocused_ = 4;
        if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::Lan = 4;
            return;
        }
    }

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

void LanMenuScreen::update(sf::Time delta)
{

    for (auto& i : LanOptions_)
        i.clear();

    LanOptions_[Game::Lan].seleted();
    if (Lanfocused_ != -1)
        LanOptions_[Lanfocused_].focused();
}

void LanMenuScreen::render(sf::RenderWindow& window)
{
    for (auto& i : LanOptions_)
        i.render(window);

    back.render(window);
}