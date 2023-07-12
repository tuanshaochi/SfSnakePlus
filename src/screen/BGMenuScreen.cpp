#include "screen/BGMenuScreen.h"
#include "screen/BeginScreen.h"

#include "Game.h"
#include <iostream>

using namespace sfSnake;

BGMenuScreen::BGMenuScreen()
    : optionName_(3),
    GridOptions_(4), BGColorOptions_(3), SkinOptions_(4),
Gridfocused_(-1), BGColorfocused_(-1), Skinfocused_(-1),
      grid_(), back()
{
    float characterSize = Game::Width / 25.f;

    // init optionlist
    optionName_[0]=Button (
        Game::LanList[Game::Lan][GRID],
        Game::GlobalFont,
        characterSize,
        Game::WordColor2,
        sf::Vector2f(Game::Width / 5.0f,Game::Height / 4.0f * 1.0f));

    optionName_[1]=Button (
        Game::LanList[Game::Lan][BGC],
        Game::GlobalFont,
        characterSize,
        Game::WordColor2,
        sf::Vector2f(Game::Width / 5.0f,Game::Height / 4.0f * 2.0f));

    optionName_[2]=Button (
        Game::LanList[Game::Lan][SKIN],
        Game::GlobalFont,
        characterSize,
        Game::WordColor2,
        sf::Vector2f(Game::Width / 5.0f,Game::Height / 4.0f * 3.0f));

    // option GridShow
    GridOptions_[0]=Button (
        Game::LanList[Game::Lan][OFF],
        Game::GlobalFont,
        characterSize,
        Game::NonSeletedColor,
        sf::Vector2f(Game::Width / 7.0f * 3.0f,Game::Height / 4.0f * 1.0f));
    GridOptions_[1]=Button (
        Game::LanList[Game::Lan][WHITE],
        Game::GlobalFont,
        characterSize,
        Game::NonSeletedColor,
        sf::Vector2f(Game::Width / 7.0f * 4.0f,Game::Height / 4.0f * 1.0f));

    // option GridColor
    GridOptions_[2]=Button (
        Game::LanList[Game::Lan][BLACK],
        Game::GlobalFont,
        characterSize,
        Game::NonSeletedColor,
        sf::Vector2f(Game::Width / 7.0f * 5.0f,Game::Height / 4.0f * 1.0f));
    GridOptions_[3]=Button (
        Game::LanList[Game::Lan][BROWN],
        Game::GlobalFont,
        characterSize,
        Game::NonSeletedColor,
        sf::Vector2f(Game::Width / 7.0f * 6.0f,Game::Height / 4.0f * 1.0f));

    // option BGColor
    BGColorOptions_[0]=Button (
        Game::LanList[Game::Lan][WHITE],
        Game::GlobalFont,
        characterSize,
        Game::NonSeletedColor,
        sf::Vector2f(Game::Width / 5.0f * 2.0f,Game::Height / 4.0f * 2.0f));
    BGColorOptions_[1]=Button (
        Game::LanList[Game::Lan][BLACK],
        Game::GlobalFont,
        characterSize,
        Game::NonSeletedColor,
        sf::Vector2f(Game::Width / 5.0f * 3.0f,Game::Height / 4.0f * 2.0f));
    BGColorOptions_[2]=Button (
        Game::LanList[Game::Lan][BROWN],
        Game::GlobalFont,
        characterSize,
        Game::NonSeletedColor,
        sf::Vector2f(Game::Width / 5.0f * 4.0f,Game::Height / 4.0f * 2.0f));

    SkinOptions_[0]=Button (
        Game::LanList[Game::Lan][GREEN],
        Game::GlobalFont,
        characterSize,
        Game::NonSeletedColor,
        sf::Vector2f(Game::Width / 7.0f * 3.0f,Game::Height / 4.0f * 3.0f));
    SkinOptions_[1]=Button (
        Game::LanList[Game::Lan][YELLOW],
        Game::GlobalFont,
        characterSize,
        Game::NonSeletedColor,
        sf::Vector2f(Game::Width / 7.0f * 4.0f,Game::Height / 4.0f * 3.0f));
    SkinOptions_[2]=Button (
        Game::LanList[Game::Lan][BLUE],
        Game::GlobalFont,
        characterSize,
        Game::NonSeletedColor,
        sf::Vector2f(Game::Width / 7.0f * 5.0f,Game::Height / 4.0f * 3.0f));
    SkinOptions_[3]=Button (
        Game::LanList[Game::Lan][RED],
        Game::GlobalFont,
        characterSize,
        Game::NonSeletedColor,
        sf::Vector2f(Game::Width / 7.0f * 6.0f,Game::Height / 4.0f * 3.0f));

    back=Button (
        Game::LanList[Game::Lan][BACK],
        Game::GlobalFont,
        characterSize,
        Game::NonSeletedColor,
        sf::Vector2f(Game::Width / 10.0f * 1.0f,Game::Height / 10.0f * 1.0f));
}

void BGMenuScreen::handleInput(sf::RenderWindow &window)
{
    auto mousePosition = sf::Mouse::getPosition(window);
    Gridfocused_ = -1;
    BGColorfocused_ = -1;
    Skinfocused_ = -1;

    if (GridOptions_[0].contains(mousePosition))
    {
        Gridfocused_ = 0;
        if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::GridStatus = 0;
            return;
        }
    }
    if (GridOptions_[1].contains(mousePosition))
    {
        Gridfocused_ = 1;
        if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::GridStatus = 1;
            return;
        }
    }

    if (GridOptions_[2].contains(mousePosition))
    {
        Gridfocused_ = 2;
        if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::GridStatus = 2;
            return;
        }
    }


    if (GridOptions_[3].contains(mousePosition))
    {
        Gridfocused_ = 3;
        if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::GridStatus = 3;
            return;
        }
    }

    if (BGColorOptions_[0].contains(mousePosition))
    {
        BGColorfocused_ = 0;
        if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::BackgroundColor = 0;
            return;
        }
    }
    if (BGColorOptions_[1].contains(mousePosition))
    {
        BGColorfocused_ = 1;
        if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::BackgroundColor = 1;
            return;
        }
    }
    if (BGColorOptions_[2].contains(mousePosition))
    {
        BGColorfocused_ = 2;
        if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::BackgroundColor = 2;
            return;
        }
    }

    if (SkinOptions_[0].contains(mousePosition))
    {
        Skinfocused_ = 0;
        if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::Skin = 0;
            return;
        }
    }
    if (SkinOptions_[1].contains(mousePosition))
    {
        Skinfocused_ = 1;
        if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::Skin = 1;
            return;
        }
    }
    if (SkinOptions_[2].contains(mousePosition))
    {
        Skinfocused_ = 2;
        if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::Skin = 2;
            return;
        }
    }

    if (SkinOptions_[3].contains(mousePosition))
    {
        Skinfocused_ = 3;
        if (!Game::mouseButtonLocked && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::Skin = 3;
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

void BGMenuScreen::update(sf::Time delta)
{
    for (auto &i : GridOptions_)
        i.clear();

    for (auto &i : BGColorOptions_)
        i.clear();

    for (auto& i : SkinOptions_)
        i.clear();

    GridOptions_[Game::GridStatus].seleted();
    if (Gridfocused_ != -1)
        GridOptions_[Gridfocused_].focused();


    BGColorOptions_[Game::BackgroundColor].seleted();
    if (BGColorfocused_ != -1)
        BGColorOptions_[BGColorfocused_].focused();

    SkinOptions_[Game::Skin].seleted();
    if (Skinfocused_ != -1)
        SkinOptions_[Skinfocused_].focused();
}

void BGMenuScreen::render(sf::RenderWindow &window)
{
    if (Game::GridStatus)
        grid_.render(window);
    for (auto &i : optionName_)
        i.render(window);
    for (auto &i : GridOptions_)
        i.render(window);
    for (auto &i : BGColorOptions_)
        i.render(window);
    for (auto& i : SkinOptions_)
        i.render(window);

    back.render(window);
}