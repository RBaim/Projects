#include <iostream>
#include <iomanip>
#include <conio.h>
#include <time.h>
#include "Player.h"
#include "Cursor.h"
#include "MyTcpIP.h"

using namespace std;

bool GameExit;
bool NewFruit;
bool print_first, print_two;
const int columns = 30;
const int rows = 30;
Player play;
int ElemX[100], ElemY[100];
int CountElem;
Cursor cur;
MyTcpIP Con;

void Out(int x, int y, char c) {
    cur.SetPos(x, y);
    cout << c;
}

void Out_score(int x, int y, int c) {
    cur.SetPos(x, y);
    cout << "00";
    cur.SetPos(x, y);
    cout << setw(2) << c;
}

void Draw() {
    /*for(int i = 1; i < rows - 1; i++) {
        cur.SetPos(1, i);
        for(int j = 1; j < columns - 1; j++) {
            cout << ' ';
        }
    }*/
    while(print_two) {}
    print_first = true;
    if(NewFruit) {
        Out(play.FruitX, play.FruitY, 'F');
        NewFruit = false;
    }
    Out(play.x, play.y, 'O');
    if(CountElem) {
        Out(ElemX[0], ElemY[0], 'o');
        Out(ElemX[CountElem - 1], ElemY[CountElem - 1], 'o');
    }
    Out_score(0, rows, play.score);
    /*for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(play.x == j && play.y == i) cout << "O";
            else if(i == rows - 1 || i == 0 || j == columns - 1 || j == 0) cout << "#";
            else if(play.FruitX == j && play.FruitY == i) cout << "F";
            else {
                bool print = true;
                for(int k = 0; k < CountElem; k++) {
                    if(ElemX[k] == j && ElemY[k] == i){
                        cout << 'o';
                        print = false;
                    }
                }
                if(print) cout << " ";
            }
        }
        cout << endl;
    }*/
    print_first = false;
}

void Logic() {
    Sleep(150);
    while(print_two) {}
    print_first = true;
    if(play.dir != STOP) {
        Out(play.x, play.y, ' ');
        /*for(int i = 0; i < CountElem; i++) {
            cur.SetPos(ElemX[i], ElemY[i]);
            cout << ' ';
        }*/
        if (CountElem) {
            Out(ElemX[CountElem - 1], ElemY[CountElem - 1], ' ');
        }
        int LastX = ElemX[0], LastY = ElemY[0];
        int Last2X, Last2Y;
        ElemX[0] = play.x;
        ElemY[0] = play.y;
        for (int i = 1; i <= CountElem; i++) {
            Last2X = ElemX[i];
            Last2Y = ElemY[i];
            ElemX[i] = LastX;
            ElemY[i] = LastY;
            LastX = Last2X;
            LastY = Last2Y;
        }
        switch (play.dir) {
            case LEFT:
                play.x--;
                break;
            case RIGHT:
                play.x++;
                break;
            case UP:
                play.y--;
                break;
            case DOWN:
                play.y++;
        }
        if (play.x <= 0) {
            play.x = columns - 2;
        }
        if (play.y <= 0) {
            play.y = rows - 2;
        }
        if (play.x >= columns - 1) {
            play.x = 1;
        }
        if (play.y >= rows - 1) {
            play.y = 1;
        }
        if (play.x == play.FruitX && play.y == play.FruitY) {
            do {
                play.FruitX = rand() % (columns - 2) + 1;
                play.FruitY = rand() % (rows - 2) + 1;
            } while ([]() {
                for (int i = 0; i < CountElem; i++)
                    if (ElemX[i] == play.FruitX && ElemY[i] == play.FruitY)
                        return true;
                return false;
            }());
            play.score++;
            CountElem++;
            NewFruit = true;
        }
        for (int i = 0; i < CountElem; i++) {
            if (ElemX[i] == play.x && ElemY[i] == play.y) {
                GameExit = true;
                break;
            }
        }
        if (CountElem == 50) {
            cout << "You win!!!!" << endl;
            GameExit = true;
        }
    }
    print_first = false;
}

void Run() {
    while(print_two) {}
    print_first = true;
    GameExit = false;
    play.dir = STOP;
    play.score = 0;
    do {
        play.FruitX = rand() % (columns - 2) + 1;
        play.FruitY = rand() % (rows - 2) + 1;
    } while(play.FruitX == columns / 2 && play.FruitY == rows / 2);
    play.x = columns / 2;
    play.y = rows / 2;
    CountElem = 0;
    NewFruit = true;
    for(int i = 0; i < columns; i++)
        cout << "#";
    cout << endl;
    for(int i = 1; i < rows - 1; i++) {
        cout << "#";
        cur.SetPos(columns - 1, i);
        cout << "#" << endl;
    }
    for(int i = 0; i < columns; i++)
        cout << "#";
    cur.SetPos(columns + 4,0);
    for(int i = 0; i < columns; i++)
        cout << "#";
    cur.SetPos(columns + 4,1);
    for(int i = 1; i < rows - 1; i++) {
        cout << "#";
        cur.SetPos(2*columns + 3, i);
        cout << "#";
        cur.SetPos(columns + 4, i + 1);
    }
    for(int i = 0; i < columns; i++)
        cout << "#";
}

void Input() {
    if(_kbhit()) {
            switch(getch()) {
                case 'a': if(play.dir != RIGHT) play.dir = LEFT; break;
                case 'w': if(play.dir != DOWN) play.dir = UP; break;
                case 'd': if(play.dir != LEFT) play.dir = RIGHT; break;
                case 's': if(play.dir != UP) play.dir = DOWN; break;
                case 'q': play.dir = STOP; break;
                case '`': GameExit = true; break;
            }
    }
}

void SendMessageToClient() {
    char out[(columns - 2)*(rows - 2) + 1];
    for (;;) {
        print_two = false;
        for(int i = 0; i < (columns - 2)*(rows - 2) + 1; i++) out[i] = 0;
        if (recv(Con.Client, out, (columns - 2)*(rows - 2) + 1, 0) > 0) {
            while(print_first){}
            print_two = true;
            for(int i = 1; i < rows - 1; i++) {
                for(int j = 1; j < columns - 1; j++) {
                    Out(j + columns + 4, i, ' ');
                    if(out[j - 1 + (i - 1)*(columns - 2)] != ' ') {
                        Out(j + columns + 4, i, out[j - 1 + (i - 1)*(columns - 2)]);
                    }
                }
            }
            Out_score(columns + 4, rows, out[(columns - 2)*(rows - 2)]);
        }
    }
}

void SendMessageForClient() {
    char out[(columns - 2)*(rows - 2) + 1];
    for (;; Sleep(500)) {
        for(int i = 0; i < (columns - 2)*(rows - 2) + 1; i++)
            out[i] = ' ';
        out[play.x - 1 + (play.y - 1)*(columns - 2)] = 'O';
        out[play.FruitX - 1 + (play.FruitY - 1)*(columns - 2)] = 'F';
        for(int k = 0; k < CountElem; k++)
            out[ElemX[k] - 1 + (ElemY[k] - 1)*(columns - 2)] = 'o';
        out[(columns - 2)*(rows - 2)] = play.score;
        send(Con.Client, out, (columns - 2)*(rows - 2) + 1, 0);
    }
}

int main() {
    srand(time(NULL));
    bool restart;
    CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE) SendMessageToClient, CreateMutex(NULL, FALSE, NULL), NULL,
                 NULL);
    CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE) SendMessageForClient, CreateMutex(NULL, FALSE, NULL), NULL,
                 NULL);
    do {
        system("cls");
        Run();
        print_first = false;
        while (!GameExit) {
            Input();
            Logic();
            Draw();
        }
        while(print_two) {}
        print_first = true;
        cur.SetPos(0, rows);
        cout << "Game Over, you score: " << play.score << endl;
        cur.SetPos(0, rows + 2);
        cout << "Restart? ";
        cin >> restart;
    } while(restart);
    getch();
    return 0;
}