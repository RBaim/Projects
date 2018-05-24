#pragma once

#include <iostream>
#include <ctime>
#include "Cursor.h"
#include "Ships.h"

class Table {
private:
    char **arr;
    Ships *tmp;
public:
    Table(Ships *tmp);
    ~Table();
    void Draw();
    void DrawV();
    char Symb(int i, int j);
    bool Attac(const char *at);
};
