#pragma once

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN};

class Player{
public:
    int x, y;
    int FruitX, FruitY;
    int score;
    Direction dir;
};
