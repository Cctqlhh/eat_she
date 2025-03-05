#ifndef FOOD_H
#define FOOD_H

#include "Point.h"

class Food {
private:
    Point position;
    int width;
    int height;

public:
    Food(int gameWidth, int gameHeight);
    
    void generate();
    const Point& getPosition() const { return position; }
    
    void setPosition(const Point& pos) { position = pos; }
    bool isColliding(const Point& point) const { return position == point; }
};

#endif // FOOD_H