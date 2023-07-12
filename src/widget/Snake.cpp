#include <SFML/Graphics.hpp>

#include <memory>
#include <iostream>

#include "widget/Snake.h"
#include "widget/Fruit.h"

#include "screen/GameOverScreen.h"
#include "Game.h"

using namespace sfSnake;

const int Snake::InitialSize = 5;

Snake::Snake()
    : direction_(Direction(0, -1)),hitSelf_(false),speed_(1),
      nodeRadius_(Game::Width / 100.0f),tailplus_(0u),
      nodeShape1(nodeRadius_),nodeShape2(sf::Vector2f(nodeRadius_ * std::sqrt(3), nodeRadius_)),
      score_(InitialSize),count_(5)
{
    initNodes();

    nodeShape1.setFillColor(Game::SnakeColor1[Game::Skin]);
    nodeShape2.setFillColor(Game::SnakeColor2[Game::Skin]);


    switch (Game::Skin)//处理皮肤读入
    {
    case(0):
        headTexture.loadFromFile("assets/image/head1.png");
        break;
    case(1):
        headTexture.loadFromFile("assets/image/head2.png");
        break;
    case(2):
        headTexture.loadFromFile("assets/image/head3.png");
        break;
    case(3):
        headTexture.loadFromFile("assets/image/head4.png");
        break;
    default:
        break;
    }
    headTexture.setSmooth(true);
    sf::Vector2u TextureSize = headTexture.getSize();
    float headScale = nodeRadius_ / TextureSize.y * 2.8;
    headSprite.setTexture(headTexture);
    headSprite.setScale(headScale, headScale);//绘制出精灵头部

    setMiddle(headSprite);
    setMiddle(nodeShape1);
    setMiddle(nodeShape2);

    pickupBuffer_.loadFromFile("assets/sounds/pickup.wav");
    pickupSound_.setBuffer(pickupBuffer_);
    pickupSound_.setVolume(30);

    dieBuffer_.loadFromFile("assets/sounds/die.wav");
    dieSound_.setBuffer(dieBuffer_);
    dieSound_.setVolume(50);//音乐载入
}

void Snake::initNodes()
{
    nodes_.push_back(SnakeNode(
        Game::Width / 2.0f,
       Game::Height / 2.0f));
    for (int i = 1; i <= 10 * InitialSize; i++)
    {
        nodes_.push_back(SnakeNode(
            Game::Width / 2.0f -
                direction_.x * i * nodeRadius_ / 5.0,
           Game::Height / 2.0f -
                direction_.y * i * nodeRadius_ / 5.0));
    }
}

void Snake::handleInput(sf::RenderWindow &window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) )
        direction_ = Direction(0, -1);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        direction_ = Direction(0, 1);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        direction_ = Direction(-1, 0);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        direction_ = Direction(1, 0);

    speed_ = sf::Keyboard::isKeyPressed(sf::Keyboard::Space)? 2:1; // 加速

    if (!Game::mouseButtonLocked)
    {
        if (
            sf::Mouse::isButtonPressed(sf::Mouse::Left) ||
            sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            static sf::Vector2i MousePosition;
            MousePosition = sf::Mouse::getPosition(window);
            if (
                distance(MousePosition,
                    sf::Vector2f(Game::Width / 20.0f * 19.0f,Game::Width / 20.0f)) >
                Game::Width / 20.0f)//当点击右上角暂停键时，不触发移动
            {
                direction_ =
                    static_cast<sf::Vector2f>(MousePosition) - backWindow(nodes_.front());
                double dire_mod = modulu(direction_);
                direction_.x /= dire_mod;
                direction_.y /= dire_mod;//向量模长归一化
            }
        }
    }
}

void Snake::update(sf::Time delta)
{
    move();
    checkEdgeCollisions();//出界判断
    checkSelfCollisions();//游戏结束判断
}

void Snake::checkFruitCollisions(std::deque<Fruit> &fruits)
{
    SnakeNode headnode = nodes_.front();
    decltype(fruits.begin()) toRemove = fruits.end();
    
    for (auto i = fruits.begin(); i != fruits.end(); ++i)
    {
        if (distance(i->getShape().getPosition(), backWindow(headnode)) <
            nodeRadius_ + i->getShape().getRadius()) //吃到水果
            toRemove = i;
    }

    if (toRemove != fruits.end())
    {
        pickupSound_.play();
        grow(toRemove->getScore(), toRemove->getCidx());
        fruits.erase(toRemove);
    }
}

unsigned Snake::getScore() const
{
    return score_;
}

unsigned Snake::getCount(int cidx) const
{
    return count_[cidx];
}

void Snake::grow(int score,int cidx)
{
    score_ += score;
    count_[cidx] += 1;
    tailplus_ += score * 5;
}


bool Snake::hitSelf() const
{
    return hitSelf_;
}

void Snake::move()
{
    SnakeNode &headNode = nodes_.front();
    for (int i = 1; i <= speed_; i++)
    {
        nodes_.push_front(SnakeNode(
            headNode.x + direction_.x * i * nodeRadius_ / 5.0,
            headNode.y + direction_.y * i * nodeRadius_ / 5.0));
        if (tailplus_)
            tailplus_--;
        else
            nodes_.pop_back();
    }
}

void Snake::checkSelfCollisions()
{
    SnakeNode head = backWindow(nodes_.front());

    for (decltype(nodes_.size()) i = 30; i < nodes_.size(); ++i)
        if (distance(head, backWindow(nodes_[i])) < 2.0f * nodeRadius_)
        {
            dieSound_.play();
            sf::sleep(sf::seconds(dieBuffer_.getDuration().asSeconds()));
            hitSelf_ = true;
            break;
        }
}

void Snake::checkEdgeCollisions()//判断是否出界，否则按一定规则更新
{
    bool isOut = true;
    for (const auto &i : nodes_)
    {
        if (i.x >= 0 && i.x<= Game::Width && i.y>=0 && i.y<= Game::Height)
            isOut = false;
    }
    if (isOut)
    {
        SnakeNode &tail = nodes_.back();
        if (tail.x < 0)
            for (auto &i : nodes_)
                i.x = i.x + Game::Width;
        else if (tail.x > Game::Width)
            for (auto &i : nodes_)
                i.x = i.x - Game::Width;
        else if (tail.y < 0)
            for (auto &i : nodes_)
                i.y = i.y +Game::Height;
        else if (tail.y >Game::Height)
            for (auto &i : nodes_)
                i.y = i.y -Game::Height;
    }
}

SnakeNode Snake::backWindow(SnakeNode node)
{
    while (node.x < 0) node.x = node.x + Game::Width;
    while (node.x > Game::Width) node.x = node.x - Game::Width;
    while (node.y < 0) node.y = node.y + Game::Height;
    while (node.y >Game::Height) node.y = node.y - Game::Height;
    return node;
}

void Snake::render(sf::RenderWindow &window)
{
    static SnakeNode lastCircleNode, curCircleNode;
    static SnakeNode lastRecNode, curRecNode;
    static SnakeNode curHeadNode;
    
    static Direction newDirection;
    static int count;

    lastCircleNode = nodes_.front();
    curHeadNode = backWindow(lastCircleNode);

    static float angle;
    newDirection = direction_;
    angle = std::acos(newDirection.y / modulu(newDirection)) / std::acos(double(-1)) * 180.0;
    if (direction_.x > 0)
        angle = -angle;
    headSprite.setPosition(curHeadNode);
    headSprite.setRotation(angle);

    renderNode(curHeadNode, headSprite, window); // 渲染头部，包含角度

    for (decltype(nodes_.size()) i = 1; i < nodes_.size(); ++i)
    {
        if (! (i % 5))
        {
            if (i % 2)
                lastRecNode = nodes_[i];
            else
            {
                curCircleNode = nodes_[i];

                newDirection = curCircleNode - lastCircleNode;
                angle =
                    std::acos(newDirection.y / modulu(newDirection)) /
                    std::acos(double(-1)) * 180.0;
                if (newDirection.x > 0)
                    angle = -angle;
                nodeShape2.setRotation(angle);

                lastCircleNode = curCircleNode;
                curCircleNode = backWindow(curCircleNode);
                curRecNode = backWindow(lastRecNode);
                renderNode(curCircleNode, nodeShape1, window);
                renderNode(curRecNode, nodeShape2, window);//更新迭代，渲染两种不同节点
                
            }
        }
    }
}

template <typename T>
void Snake::renderNode(sf::Vector2f &nowPosition, T &shape, sf::RenderWindow &window)
{
    shape.setPosition(nowPosition);
    window.draw(shape);
}

template <typename T1, typename T2>
inline double Snake::distance(sf::Vector2<T1> node1, sf::Vector2<T2> node2) //计算距离
{
    return std::sqrt(
        std::pow((static_cast<double>(node1.x) - static_cast<double>(node2.x)), 2) +
        std::pow((static_cast<double>(node1.y) - static_cast<double>(node2.y)), 2));
}

template <typename T>
inline double Snake::modulu(sf::Vector2<T> node) //取模长
{
    return std::sqrt(
        std::pow(static_cast<double>(node.x), 2) +
        std::pow(static_cast<double>(node.y), 2));
}