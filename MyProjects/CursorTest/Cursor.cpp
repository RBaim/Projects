#include "Cursor.h"

Cursor::Cursor() {
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cur_info;
    GetConsoleCursorInfo(handle, &cur_info);
    cur_info.bVisible = false;
    cur_info.dwSize = 1;
    SetConsoleCursorInfo(handle, &cur_info);
}

void Cursor::SetPos(int x, int y) {
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(handle, coord);
}
