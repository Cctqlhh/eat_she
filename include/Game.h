#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"
#include <iostream>

class Game {
private:
    bool gameOver;
    int score;
    Snake snake;
    Food food;
    const int width;
    const int height;

    void draw();
    void input();
    void logic();

public:
    Game(int width = 20, int height = 20);
    void run();
};

#endif // GAME_H