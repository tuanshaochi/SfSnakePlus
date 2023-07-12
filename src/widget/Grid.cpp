#include "widget/Grid.h"
#include "Game.h"

using namespace sfSnake;

Grid::Grid()
    : gridV(sf::Vector2f(Game::Width / 500.0f,Game::Height)),
      gridH(sf::Vector2f(Game::Width, Game::Width / 500.0f))
{
}

void Grid::render(sf::RenderWindow &window)
{
    gridV.setFillColor(Game::Grid[Game::GridStatus-1]);
    gridH.setFillColor(Game::Grid[Game::GridStatus-1]);

    float gridSpace = Game::Width / 50.0f;
    for (float i = 0.f; i < Game::Width; i += gridSpace)
    {
        gridV.setPosition(i, 0);
        window.draw(gridV);
    }

    for (float i = 0.f; i <Game::Height; i += gridSpace)
    {
        gridH.setPosition(0, i);
        window.draw(gridH);
    }
}
