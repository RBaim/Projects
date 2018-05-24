#pragma once

#include <windows.h>

class Cursor{
private:
    COORD coord;
    HANDLE handle;
public:
    Cursor();
    void SetPos(int x, int y);
};
