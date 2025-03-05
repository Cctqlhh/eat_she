#include <cstddef>
#include "../include/Snake.h"

Snake::Snake(int startX, int startY) : direction(STOP) {
    body.push_back(Point(startX, startY));
}

void Snake::move() {
    // 移动蛇身
    for (int i = body.size() - 1; i > 0; i--) {
        body[i] = body[i - 1];
    }

    // 移动蛇头
    switch (direction) {
    case LEFT:
        body[0].x--;
        break;
    case RIGHT:
        body[0].x++;
        break;
    case UP:
        body[0].y--;
        break;
    case DOWN:
        body[0].y++;
        break;
    default:
        break;
    }
}

void Snake::grow() {
    body.push_back(Point());
}

void Snake::setDirection(Direction dir) {
    // 防止直接掉头
    if ((dir == LEFT && direction != RIGHT) ||
        (dir == RIGHT && direction != LEFT) ||
        (dir == UP && direction != DOWN) ||
        (dir == DOWN && direction != UP)) {
        direction = dir;
    }
}

bool Snake::checkCollision(const Point& point) const {
    for (const auto& p : body) {
        if (p == point) {
            return true;
        }
    }
    return false;
}

bool Snake::checkSelfCollision() const {
    for (size_t i = 1; i < body.size(); i++) {
        if (body[0] == body[i]) {
            return true;
        }
    }
    return false;
}

bool Snake::checkWallCollision(int width, int height) const {
    const Point& head = body[0];
    return head.x < 0 || head.x >= width || head.y < 0 || head.y >= height;
}