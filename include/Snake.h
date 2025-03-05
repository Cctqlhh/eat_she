#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "Point.h"

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

class Snake {
private:
    std::vector<Point> body;
    Direction direction;

public:
    Snake(int startX, int startY);
    
    void move();
    void grow();
    void setDirection(Direction dir);
    Direction getDirection() const { return direction; }
    
    bool checkCollision(const Point& point) const;
    bool checkSelfCollision() const;
    bool checkWallCollision(int width, int height) const;
    
    const Point& getHead() const { return body[0]; }
    const std::vector<Point>& getBody() const { return body; }
};

#endif // SNAKE_H