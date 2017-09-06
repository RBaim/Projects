#include <iostream>
#include <ctime>
#include "Table.h"
#include "MyTcpIP.h"

using std::cout;
using std::endl;
using std::cin;

bool GameOn;
bool Win;
char a[3];
MyTcpIP con;
Ships player[10];
Table play(player);

void Draw_V(char *sms) {
    Cursor cur;
    cur.SetPos(0, 12);
    cout << "    ";
    int j = 0;
    cur.SetPos(15, j);
    cout << ' ';
    for (int i = 0; i < 10; ++i)
        cout << char('a' + i);
    j++;
    cur.SetPos(15, j);
    for (int i = 0; i < 10; i++) {
        cout << char('0' + i);
        cur.SetPos(26, i + 1);
        cout << char('0' + i);
        j++;
        cur.SetPos(15, j);
    }
    cout << ' ';
    for (int i = 0; i < 10; i++)
        cout << char('a' + i);
    for (int i = 0; i < 10; ++i) {
        cur.SetPos(16, i + 1);
        for (int k = 0; k < 10; ++k) {
            if (sms[i * 10 + k] == '#') {
                cout << ' ';
                continue;
            } else cout << sms[i * 10 + k];
        }
    }
    cur.SetPos(0, 12);
}

void Logic() {
    char sms[106];
    bool temp;
    for (int i = 0; i < 106; ++i) sms[i] = 0;
    play.Draw();
    if(recv(con.Client, sms, 106, 0) <= 0) {
        Win = true;
        return;
    }
    if (!sms[101]) {
        Win = true;
        return;
    }
    if (sms[104]) {
        a[0] = sms[102];
        a[1] = sms[103];
        Draw_V(sms);
        GameOn = false;
        if(!sms[105])
            temp = play.Attac(a); //WinCh
        else
            temp = false;
        for (int i = 0; i < 10; ++i)
            if (!player[i].DestrCh()) GameOn = true;
        play.Draw();
        if (GameOn && !temp)
            cin >> a;
        sms[105] = temp; //two_ch
        if (temp) {
            sms[102] = 0;//Coord
            sms[103] = 0;//Coord
        } else {
            sms[102] = a[0];//Coord
            sms[103] = a[1];//Coord
        }
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < 10; ++j)
                sms[i * 10 + j] = play.Symb(i, j);
        sms[101] = GameOn;//Win
        sms[104] = 1;//Ochered
        send(con.Client, sms, 106, 0);
    }
}

void Run() {
    GameOn = true;
    Win = false;
}

int main() {
    srand(unsigned(time(0)));
    Run();
    while (GameOn && !Win) {
        Logic();
    }
    if (Win)
        cout << "Your Win!!!" << endl;
    else
        cout << "Your loser..." << endl;
    system("pause");
    return 0;
}
