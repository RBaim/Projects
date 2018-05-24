#include "Table.h"

using std::cout;
using std::endl;

void SetAllShips(char **arr, Ships *tmp);

Table::Table(Ships *tmp_p) {
    tmp = tmp_p;
    arr = new char *[10];
    for (int i = 0; i < 10; ++i)
        arr[i] = new char[10];
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            arr[i][j] = ' ';
    SetAllShips(arr, tmp);
}

Table::~Table() {
    for (int i = 0; i < 10; ++i)
        delete[] arr[i];
    delete[] arr;
}

void Table::Draw() {
    Cursor cur;
    cur.SetPos(0, 0);
    cout << ' ';
    for(int i = 0; i < 10; i++)
        cout << char('a' + i);
    cout << endl;
    for(int i = 0; i < 10; i++) {
        cout << char('0' + i);
        cur.SetPos(11, i + 1);
        cout << char('0' + i) << endl;
    }
    cout << ' ';
    for(int i = 0; i < 10; i++)
        cout << char('a' + i);
    for (int i = 0; i < 10; ++i) {
        cur.SetPos(1, i + 1);
        for (int j = 0; j < 10; ++j)
            cout << arr[i][j];
    }
    cur.SetPos(0, 12);
}

void Table::DrawV() {
    Cursor cur;
    int j = 0;
    cur.SetPos(15, j);
    cout << ' ';
    for(int i = 0; i < 10; ++i)
        cout << char('a' + i);
    j++;
    cur.SetPos(15, j);
    for(int i = 0; i < 10; i++) {
        cout << char('0' + i);
        cur.SetPos(26, i + 1);
        cout << char('0' + i);
        j++;
        cur.SetPos(15, j);
    }
    cout << ' ';
    for(int i = 0; i < 10; i++)
        cout << char('a' + i);
    for (int i = 0; i < 10; ++i) {
        cur.SetPos(16, i + 1);
        for(int k = 0; k < 10; ++k) {
            if(arr[i][k] == '#') {cout << ' '; continue;}
            else cout << arr[i][k];
        }
    }
    cur.SetPos(0, 12);
    cout << "          ";
    cur.SetPos(0, 12);
}

char Table::Symb(int i, int j) {
    return arr[i][j];
}

bool Table::Attac(const char *at) { //at[0]~x at[1]~y
    int x = at[0] - 'a';
    int y = at[1] - '0';
    if(x >= 0 && x < 10 && y >= 0 && y < 10) {
        switch (arr[y][x]) {
            case ' ':
                arr[y][x] = '*';
                return false;
            case '#':
                arr[y][x] = 'x'; return true;
        }
    }
    return false;
}

bool CheckSet(char **arr, int size, int x, int y, bool dir) {
    if (dir) {
        for (int i = std::max(0, y - 1); i <= std::min(9, y + 1); ++i)
            for (int j = std::max(0, x - 1); j <= std::min(9, x + size); ++j)
                if (arr[i][j] == '#') return false;
    } else {
        for (int i = std::max(0, y - 1); i <= std::min(9, y + size); ++i)
            for (int j = std::max(0, x - 1); j <= std::min(9, x + 1); ++j)
                if (arr[i][j] == '#') return false;
    }
    return true;
}

Ships SetShips(char **arr, int size) {
    srand(unsigned(time(0)));
    bool dir = rand() % 2;
    int x = 0;
    int y = 0;
    do {
        do {
            x = rand() % 10;
        } while (dir && x > 10 - size);
        do {
            y = rand() % 10;
        } while (!dir && y > 10 - size);
    } while (!CheckSet(arr, size, x, y, dir));
    if (dir) {
        for (int j = x; j < x + size; ++j)
            arr[y][j] = '#';
    } else {
        for (int i = y; i < y + size; ++i)
            arr[i][x] = '#';
    }
    return Ships(size, x, y, dir, arr);
}

void SetAllShips(char **arr, Ships *tmp) {
    for (int i = 0; i < 1; ++i)
        tmp[i] = SetShips(arr, 4);
    for (int i = 1; i < 3; ++i)
        tmp[i] = SetShips(arr, 3);
    for (int i = 3; i < 6; ++i)
        tmp[i] = SetShips(arr, 2);
    for (int i = 6; i < 10; ++i)
        tmp[i] = SetShips(arr, 1);
}
