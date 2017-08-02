#include <iostream>
#include "Cursor.h"
#include "MyTcpIP.h"

using namespace std;

const int columns = 30;
const int rows = 30;
Cursor cur;
MyTcpIP Con("127.0.0.1", 8012);

void Out(int x, int y, char c) {
    cur.SetPos(x, y);
    cout << c;
}

void SendMessageToClient() {
    char out[(columns - 2)*(rows - 2)];
    for (;; Sleep(150)) {
        for(int i = 0; i < (columns - 2)*(rows - 2); i++) out[i] = 0;
        if (recv(Con.Client, out, (columns - 2)*(rows - 2), 0) > 0) {
            for(int i = 1; i < rows - 1; i++) {
                for(int j = 1; j < columns - 1; j++) {
                    Out(j, i, ' ');
                    if(out[j - 1 + (i - 1)*(columns - 2)] != ' ') {
                        Out(j, i, out[j - 1 + (i - 1)*(columns - 2)]);
                    }
                }
            }
        }
    }
}


int main() {
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
    SendMessageToClient();
    return 0;
}