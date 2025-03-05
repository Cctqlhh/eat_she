#include "../include/Food.h"
#include <cstdlib>
#include <ctime>

Food::Food(int gameWidth, int gameHeight) : width(gameWidth), height(gameHeight) {
    srand(static_cast<unsigned>(time(nullptr)));
    generate();
}

void Food::generate() {
    position.x = rand() % width;
    position.y = rand() % height;
}