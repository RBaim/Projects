#include "Ships.h"

Ships::Ships(int size_p, int x_p, int y_p, bool dir_p, char **arr_p) : size(size_p), x(x_p),
                                                                       y(y_p), dir(dir_p), arr(arr_p), kill(false) {}

bool Ships::DestrCh() {
    if(kill) return true;
    if(dir) {
        for (int j = x; j < x + size; ++j)
            if(arr[y][j] != 'x') return false;
    } else {
        for(int i = y; i < y + size; ++i)
            if(arr[i][x] != 'x') return false;
    }
    if(dir) {
        for (int j = x; j < x + size; ++j)
            arr[y][j] = '+';
    } else {
        for(int i = y; i < y + size; ++i)
            arr[i][x] = '+';
    }
    kill = true;
    return true;
}

Ships::Ships(const Ships& copy) {
    (*this) = copy;
}

Ships Ships::operator&=(const Ships &p) {
    x = p.x;
    y = p.y;
    size = p.size;
    arr = p.arr;
    dir = p.dir;
}
