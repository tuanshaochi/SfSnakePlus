#include <SFML/Graphics.hpp>

#include <memory>
#include <iostream>
#include <string>
#include "screen/BeginScreen.h"
#include "Game.h"

using namespace sfSnake;

const int Game::Width = 1000; //全局窗口大小
const int Game::Height = 618;

const sf::Color Game::WordColor1 = //文字颜色橙色
    sf::Color(0xff7f00ff);
const sf::Color Game::WordColor2 = //文字颜色蓝色
    sf::Color(0x6adbffff);
const sf::Color Game::NonSeletedColor = //文字颜色，浅灰
    sf::Color(0x00000055);
const sf::Color Game::Background[] =
    {
        sf::Color(0xeaeaeaee), // 白
        sf::Color(0x747474ff), // 黑
        sf::Color(0xffa67d3d)  // 棕
};
const sf::Color Game::Grid[] =
    {
        sf::Color(0xfbfbfbaa), // 白
        sf::Color(0x31313116), // 黑
        sf::Color(0x5a351d16)  // 棕
};

const sf::Color Game::Fruit[] =
    {
        sf::Color(0x212f3dff), // 黑
        sf::Color(0x935116ff), // 棕
        sf::Color(0xe74c3cff), // 红
        sf::Color(0x5dade2ff), // 蓝
        sf::Color(0x2ecc71ff)  // 绿
};

const sf::Color Game::SnakeColor1[] =
{
    sf::Color(0x238e23ff), // 绿
    sf::Color(0xcd7032ff), // 黄
    sf::Color(0x23238eff), // 蓝
    sf::Color(0x2f2f4eff) // 红
};

const sf::Color Game::SnakeColor2[] =
{
    
    sf::Color(0x7fff00ff), // 绿
    sf::Color(0xffff00ff), // 黄
    sf::Color(0x5dade2ff), // 蓝
    sf::Color(0xff7f00ff)// 红
};

// 全局语言文字列表
const std::vector<std::vector<sf::String>> Game::LanList =
{ {L"界面菜单",L"开始游戏",L"退出游戏",L"最终分数：",L"关于",L"分数：",L"暂停",L"返回菜单",L"重玩",L"继续",L"白",L"黑",L"棕",L"关闭",L"开启",L"网格设置",L"网格颜色",L"背景颜色",L"语言设置",L"皮肤设置",L"绿",L"黄",L"蓝",L"红",L"帮助信息",L"游戏中，按上下左右键切换方向\n点击或长按鼠标可指引蛇的移动\n长按空格加速\n屏幕上有5种不同颜色的水果：\n黑色、棕色（0分），红色（3分），蓝色（2分），绿色（1分）\n游戏屏幕实时显示已经吃到的各种水果的数量\n可以设置不同的网格、背景颜色和皮肤，并且可以切换语言\n\n 作者：段绍知\n 如有相关问题，欢迎咨询20307130235@fudan.edu.cn"}, //简体中文
   {L"介面選單",L"開始遊戲",L"退出遊戲",L"最終分數：",L"關於",L"分數：",L"暫停",L"返回選單",L"重玩",L"繼續",L"白色",L"黑色",L"棕色",L"關閉",L"開啟",L"網格設置",L"網格顏色",L"背景顏色",L"語言設定",L"皮膚設定",L"綠",L"黃",L"藍",L"紅",L"幫助訊息",L"遊戲中，按上下左右鍵切換方向\n點擊或長按滑鼠可指引蛇的移動\n長按空格加速\n荧幕上有5種不同顏色的水果：\n黑色、棕色（0分），紅色（3分），藍色（2分），綠色（1分）\n遊戲荧幕實时顯示已經吃到的各種水果的數量\n可以設定不同的網格、背景顏色和皮膚， 並且可以切換語言\n\n作者：段紹知\n如有相關問題，歡迎諮詢 20307130235@fudan.edu.cn"}, //繁体中文
    {L"Interface", L"Start", L"Exit", L"Final Score: ", L"About", L"Score: ", L"Pause", L"Back", L"Replay", L"Continue", L"White", L"Black", L"Brown", L"Close", L"On", L"Grid Settings", L"Grid Color", L"Background",L"Language",L"Skin",L"Green",L"Yellow",L"Blue",L"Red",L"Help Information",L"In the game, press keyboard to switch directions. \nClick the mouse to guide the snake's movement. \nLong press the space to accelerate. \nThere are 5 different colors of fruits on the screen: \n black, brown (no score), red (3 points),\n blue (2 points), and green (1 point).\n Different grids, background colors, and skins can be set\n And you can switch languages. \n\n Author: Shaochi Tuan \n If you have any related questions,consult 20307130235@fudan.edu.cn"}, //英语
    {L"インタフェース",L"開始",L"終了",L"最終スコア：",L"概要",L"スコア：",L"一時停止",L"戻る",L"再放送",L"継続",L"白",L"黒",L"茶色",L"閉じる",L"開く",L"メッシュ設定",L"メッシュ色",L"背景",L"言語",L"皮膚",L"緑",L"黄色",L"青",L"赤",L"ヘルプ情報",L"ゲーム中、上下左右のボタンを押して方向を切り替える \nマウスをクリックしてヘビの移動を誘導します。 \nスペースを長押しすると加速 \n画面には5種類の異なる色の果物があります： \n黒、茶色（無得点）、赤（3点）、青（2点）、緑（1点） \nをリアルタイムで表示し、異なるメッシュ、\n背景色、皮膚を設定することができます。\nまた、言語を切り替えることができます \n\n著者：段紹知 \n関連問題があれば、お問い合わせください20307130235@fudan.edu.cn"}, //日语
    {L"인터페이스",L"시작",L"종료",L"최종점수: ",L"정보",L"점수: ",L"일시정지",L"반환",L"재생시작",L"계속",L"화이트",L"블랙",L"브라운",L"닫기",L"켜기",L"그리드설정",L"그리드색상",L"배경",L"언어",L"스킨",L"그린",L"노란색",L"파란색",L"빨간색",L"도움말 정보",L"게임에서 누르거나 상하좌우 키를 눌러 방향을 전환합니다.\n클릭하거나 마우스를 길게 눌러 뱀의 움직임을 안내합니다.\n스페이스 바를 길게 눌러 가속\n화면에는 5가지 다른 색깔의 과일이 있습니다.\n검은색, 갈색(점수 없음), 빨간색(3점), 파란색(2점), 녹색(1점)\n게임 화면에는 이미 먹은 각종 과일의 수량을 실시간으로 표시합니다.\n다른 격자, 배경색, 피부, 피부,또한 언어를 전환할 수 있습니다.\n\n 저자: 단소지\n 관련 질문이 있으면 문의를 환영합니다.20307130235@fudan.edu.cn"} //韩语
};

sf::Font Game::GlobalFont = sf::Font();
BGimg Game::GlobalTitle = BGimg("assets/image/title2.jpg"); //背景图片设置
BGimg Game::PauseTitle = BGimg("assets/image/pause2.png");

std::shared_ptr<Screen> Game::MainScreen = std::make_shared<BeginScreen>();
std::shared_ptr<Screen> Game::TmpGameScreen = nullptr;


int Game::GridStatus = 0;
int Game::BackgroundColor = 0;
int Game::Skin = 0;
int Game::Lan = 0;

sf::Clock Game::mouseButtonClock = sf::Clock();
sf::Time Game::mouseButtonCDtime = sf::Time();
bool Game::mouseButtonLocked = false;

sf::Clock Game::kbClock = sf::Clock();
sf::Time Game::kbCDtime = sf::Time();
bool Game::kbLocked = false;


Game::Game()
    : TimePerFrame_(sf::seconds(1.f / 100.f)), window_(sf::VideoMode(Game::Width, Game::Height), "sfSnake")
{
    icon_.loadFromFile("assets/image/favicon.jpg");
    window_.setIcon(icon_.getSize().x, icon_.getSize().y, icon_.getPixelsPtr());

    bgMusic_.openFromFile("assets/music/bgm.wav");
    bgMusic_.setVolume(30);
    bgMusic_.setLoop(true);
    bgMusic_.play();
}

void Game::handleInput()
{
    static sf::Event event;

    while (window_.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window_.close();
    }
    Game::MainScreen->handleInput(window_);
}

void Game::update(sf::Time delta)
{
    Game::MainScreen->update(delta);
}

void Game::render()
{
    window_.clear(Game::Background[BackgroundColor]);
    Game::MainScreen->render(window_);
    window_.display();
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    mouseButtonClock.restart();
    kbClock.restart();

    while (window_.isOpen())
    {
        sf::Time delta = clock.restart();
        timeSinceLastUpdate += delta;

        while (timeSinceLastUpdate > TimePerFrame_)
        {
            timeSinceLastUpdate -= TimePerFrame_;
            handleInput();

            update(TimePerFrame_);

            render();
        }

        delta = mouseButtonClock.restart();
        mouseButtonCDtime += delta;

        if (mouseButtonCDtime.asSeconds() > 0.5f)
        {
            mouseButtonCDtime -= sf::seconds(0.5f);
            mouseButtonLocked = false;
        }

        delta = kbClock.restart();
        kbCDtime += delta;

        if (kbCDtime.asSeconds() > 0.5f)
        {
            kbCDtime -= sf::seconds(0.5f);
            kbLocked = false;
        }
    }
}