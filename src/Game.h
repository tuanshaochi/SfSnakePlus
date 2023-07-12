#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <memory>
#include <cmath>

#include "screen/Screen.h"
#include "widget/BGimg.h"

#define BGMENU 0
#define PLAY 1
#define QUIT 2
#define GAMEOVER 3
#define ABOUT 4
#define SCORE 5
#define PAUSE 6
#define BACK 7
#define RESTART 8
#define CONTI 9
#define WHITE 10
#define BLACK 11
#define BROWN 12
#define OFF 13
#define ON 14
#define GRID 15
#define GRIDC 16
#define BGC 17
#define LAN 18
#define SKIN 19
#define GREEN 20
#define YELLOW 21
#define BLUE 22
#define RED 23
#define INFO 24
#define INFOM 25

namespace sfSnake
{
    class Game
    {
    public:
        Game();
        ~Game() = default;

        void run();

    private:
        void handleInput();
        void update(sf::Time delta);
        void render();

    public:
        static const sf::Color WordColor1;//按钮文字颜色设置
        static const sf::Color WordColor2;
        static const sf::Color NonSeletedColor;
        static const sf::Color Background[3];//背景颜色设置
        static const sf::Color Grid[3];//网格颜色设置
        static const sf::Color Fruit[5];//水果颜色设置
        static const sf::Color SnakeColor1[4];//皮肤颜色设置
        static const sf::Color SnakeColor2[4];

        static const int Width;//窗口尺寸
        static const int Height;

        static sf::Font GlobalFont;
        static BGimg GlobalTitle;//背景图片导入
        static BGimg PauseTitle;

        static std::shared_ptr<Screen> MainScreen;//屏幕状态存储
        static std::shared_ptr<Screen> TmpGameScreen;//暂停时返回游戏


        static int GridStatus;//界面和语言状态标记
        static int BackgroundColor;
        static int Skin;
        static int Lan;

        static const std::vector<std::vector<sf::String>> LanList;

        static bool mouseButtonLocked;//鼠标锁控制
        static sf::Clock mouseButtonClock;
        static sf::Time mouseButtonCDtime;

        static bool kbLocked;//键盘锁控制
        static sf::Clock kbClock;
        static sf::Time kbCDtime;

    private:
        sf::RenderWindow window_;

        sf::Time TimePerFrame_;

        sf::Music bgMusic_;

        sf::Image icon_;
    };

    template <typename T>
    inline sf::FloatRect setMiddle(T &shape)
    {
        sf::FloatRect shapeBounds = shape.getLocalBounds();
        shape.setOrigin(shapeBounds.left + shapeBounds.width / 2,
                        shapeBounds.top + shapeBounds.height / 2);
        return shapeBounds;
    }
}