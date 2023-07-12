#include <SFML/Graphics.hpp>

#include <random>
#include <iostream>

#include "screen/GameScreen.h"
#include "screen/GameOverScreen.h"
#include "screen/PauseScreen.h"

using namespace sfSnake;

GameScreen::GameScreen()
    : snake_(), grid_(), pause(),count_(5)
{
    pause=Button (
        Game::LanList[Game::Lan][PAUSE],
        Game::GlobalFont,
        Game::Width / 30.0,
        Game::WordColor2,
        sf::Vector2f(Game::Width / 16.0f * 15.0f,Game::Height / 16.0f * 1.0f));

    score_.setFont(Game::GlobalFont);
    score_.setString(Game::LanList[Game::Lan][SCORE] + std::to_string(snake_.getScore()));
    score_.setCharacterSize(Game::Width / 25.0f);
    score_.setFillColor(Game::WordColor1);
    setMiddle(score_);
    score_.setPosition(
        Game::Width / 9.0f*1.0f,
        Game::Width * 0.05f);

    count_[0].setFont(Game::GlobalFont);
    count_[0].setString(std::to_string(snake_.getCount(0)));
    count_[0].setCharacterSize(Game::Width / 40.0f);
    count_[0].setFillColor(Game::Fruit[0]);
    setMiddle(count_[0]);
    count_[0].setPosition(
        Game::Width / 24.0f * 1.0f,
        Game::Width * 0.1f);

    count_[1].setFont(Game::GlobalFont);
    count_[1].setString(std::to_string(snake_.getCount(1)));
    count_[1].setCharacterSize(Game::Width / 40.0f);
    count_[1].setFillColor(Game::Fruit[1]);
    setMiddle(count_[1]);
    count_[1].setPosition(
        Game::Width / 24.0f*2.0f,
        Game::Width * 0.1f);

    count_[2].setFont(Game::GlobalFont);
    count_[2].setString(std::to_string(snake_.getCount(2)));
    count_[2].setCharacterSize(Game::Width / 40.0f);
    count_[2].setFillColor(Game::Fruit[2]);
    setMiddle(count_[2]);
    count_[2].setPosition(
        Game::Width / 24.0f * 3.0f,
        Game::Width * 0.1f);
    count_[3].setFont(Game::GlobalFont);
    count_[3].setString(std::to_string(snake_.getCount(3)));
    count_[3].setCharacterSize(Game::Width / 40.0f);
    count_[3].setFillColor(Game::Fruit[3]);
    setMiddle(count_[3]);
    count_[3].setPosition(
        Game::Width / 24.0f * 4.0f,
        Game::Width * 0.1f);

    count_[4].setFont(Game::GlobalFont);
    count_[4].setString(std::to_string(snake_.getCount(4)));
    count_[4].setCharacterSize(Game::Width / 40.0f);
    count_[4].setFillColor(Game::Fruit[4]);
    setMiddle(count_[4]);
    count_[4].setPosition(
        Game::Width / 24.0f * 5.0f,
        Game::Width * 0.1f);
}

void GameScreen::handleInput(sf::RenderWindow &window)
{
    snake_.handleInput(window);

    auto mousePosition = sf::Mouse::getPosition(window);

    pause.clear();

    if (pause.contains(mousePosition))
    {
        pause.focused();
        if (
            !Game::mouseButtonLocked &&
            sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Game::mouseButtonCDtime = sf::Time::Zero;
            Game::mouseButtonLocked = true;
            Game::TmpGameScreen = Game::MainScreen;
            Game::MainScreen = std::make_shared<PauseScreen>();
            return;
        }
    }
}

void GameScreen::update(sf::Time delta)
{
    while (fruit_.size() < 5)
        generateFruit();

    snake_.update(delta);
    snake_.checkFruitCollisions(fruit_);

    if (snake_.hitSelf())
    {
        Game::MainScreen = std::make_shared<GameOverScreen>(snake_.getScore());
        return;
    }

    score_.setString(Game::LanList[Game::Lan][SCORE] + std::to_string(snake_.getScore()));
    count_[0].setString(std::to_string(snake_.getCount(0)));
    count_[1].setString(std::to_string(snake_.getCount(1)));
    count_[2].setString(std::to_string(snake_.getCount(2)));
    count_[3].setString(std::to_string(snake_.getCount(3)));
    count_[4].setString(std::to_string(snake_.getCount(4)));
}

void GameScreen::render(sf::RenderWindow &window)
{
    if (Game::GridStatus)
        grid_.render(window);
    snake_.render(window);
    for (auto fruit : fruit_)
        fruit.render(window);
    pause.render(window);
    window.draw(score_);
    window.draw(count_[0]);
    window.draw(count_[1]);
    window.draw(count_[2]);
    window.draw(count_[3]);
    window.draw(count_[4]);
}

void GameScreen::generateFruit()
{
    static std::default_random_engine engine(time(NULL));
    static std::default_random_engine colorEngine(time(NULL));

    static std::uniform_int_distribution<int> xPos(
        Game::Width / 15.0f, Game::Width - Game::Width / 10.0f);

    static std::uniform_int_distribution<int> yPos(
        Game::Width / 10.0f, Game::Height - Game::Width / 15.0f);

    static std::uniform_int_distribution<int> fruitColor(0, 7);

    switch (fruitColor(colorEngine))
    {
    case 0: // 黑1
        fruit_.push_back(Fruit(
            sf::Vector2f(xPos(engine), yPos(engine)),
            Game::Fruit[0],0,0));
        break;
    case 1: // 棕1
        fruit_.push_back(Fruit(
            sf::Vector2f(xPos(engine), yPos(engine)),
            Game::Fruit[1],0,1));
        break;
    case 2:
    case 3: // 红2
        fruit_.push_back(Fruit(
            sf::Vector2f(xPos(engine), yPos(engine)),
            Game::Fruit[2],3,2));
        break;
    case 4:
    case 5: // 蓝2
        fruit_.push_back(Fruit(
            sf::Vector2f(xPos(engine), yPos(engine)),
            Game::Fruit[3],2,3));
        break;
    case 6:
    case 7: // 绿2
        fruit_.push_back(Fruit(
            sf::Vector2f(xPos(engine), yPos(engine)),
            Game::Fruit[4],1,4));
        break;
    default:
        break;
    }
}