#include "../include/Game.h"
#include <conio.h>
#include <windows.h>

Game::Game(int width, int height) 
    : gameOver(false)
    , score(0)
    , snake(width / 2, height / 2)
    , food(width, height)
    , width(width)
    , height(height) {}

void Game::draw() {
    system("cls"); // 清屏

    // 绘制上边界
    for (int i = 0; i < width + 2; i++)
        std::cout << "#";
    std::cout << std::endl;

    // 绘制游戏区域
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                std::cout << "#"; // 左边界

            bool isPrinted = false;
            // 绘制蛇
            for (const auto& p : snake.getBody()) {
                if (p.x == j && p.y == i) {
                    std::cout << "O";
                    isPrinted = true;
                    break;
                }
            }

            // 绘制食物
            if (!isPrinted && food.getPosition().x == j && food.getPosition().y == i) {
                std::cout << "F";
                isPrinted = true;
            }

            // 绘制空白
            if (!isPrinted)
                std::cout << " ";

            if (j == width - 1)
                std::cout << "#"; // 右边界
        }
        std::cout << std::endl;
    }

    // 绘制下边界
    for (int i = 0; i < width + 2; i++)
        std::cout << "#";
    std::cout << std::endl;

    // 显示分数
    std::cout << "Score: " << score << std::endl;
}

void Game::input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            snake.setDirection(LEFT);
            break;
        case 'd':
            snake.setDirection(RIGHT);
            break;
        case 'w':
            snake.setDirection(UP);
            break;
        case 's':
            snake.setDirection(DOWN);
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Game::logic() {
    snake.move();

    // 检查是否吃到食物
    if (snake.getHead() == food.getPosition()) {
        score += 10;
        snake.grow();
        food.generate();
    }

    // 检查是否撞墙或撞到自己
    if (snake.checkWallCollision(width, height) || snake.checkSelfCollision()) {
        gameOver = true;
    }
}

void Game::run() {
    std::cout << "贪吃蛇游戏开始！\n";
    std::cout << "使用 W/A/S/D 控制方向，X 退出游戏\n";
    std::cout << "按任意键开始...";
    _getch();

    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(100); // 控制游戏速度
    }
    std::cout << "\nGame Over! Your score: " << score << std::endl;
}