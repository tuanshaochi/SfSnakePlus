#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <deque>

#include "Fruit.h"

namespace sfSnake
{
    using Direction = sf::Vector2f;
    using SnakeNode = sf::Vector2f;

    class Snake
    {
    public:
        Snake();

        void handleInput(sf::RenderWindow &window);
        void update(sf::Time delta);
        void render(sf::RenderWindow &window);

        void checkFruitCollisions(std::deque<Fruit> &fruits);

        bool hitSelf() const;

        unsigned getScore() const;
        unsigned getCount(int cidx) const;

    private:

        void move();
        void grow(int score, int cidx);
        void checkEdgeCollisions();
        void checkSelfCollisions();
        void initNodes();

        bool hitSelf_;

        unsigned int speed_;

        template <typename T>
        void renderNode(sf::Vector2f &nowPosition, T &shape, sf::RenderWindow &window);

        SnakeNode backWindow(SnakeNode node);
        
        Direction direction_;
        float nodeRadius_;
        
        unsigned tailplus_;

        sf::CircleShape nodeShape1;
        sf::RectangleShape nodeShape2;
        sf::Texture headTexture;
        sf::Sprite headSprite;

        unsigned int score_;
        std::vector<unsigned int> count_;

        sf::SoundBuffer pickupBuffer_;
        sf::Sound pickupSound_;

        sf::SoundBuffer dieBuffer_;
        sf::Sound dieSound_;

        std::deque<SnakeNode> nodes_;
        static const int InitialSize;

        template <typename T1, typename T2>
        static double distance(sf::Vector2<T1> node1, sf::Vector2<T2> node2);

        template <typename T>
        static double modulu(sf::Vector2<T> node);
    };
}