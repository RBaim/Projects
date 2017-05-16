#include <clocale>
#include <cstring>
#include <iostream>

using namespace std;

bool RecCheckIden(char *arr) {
    if(strlen(arr) == 0) return true;
    if(strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789", arr[0])) return RecCheckIden(arr + 1);
    else return false;
}

bool CheckIden(char *arr) {
    if(strlen(arr) > 0) {
        if(!strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", arr[0])) {
            return false;
        } else {
            return RecCheckIden(arr + 1);
        }
    }
    return false;
}

void RecCheckIdenFunc(char *arr, bool& res) {
    if(strlen(arr) == 0) { res = true; return;}
    if(strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789", arr[0])) RecCheckIdenFunc(arr + 1, res);
    else { res = false; return;}
}

void CheckIdenFunc(char *arr, bool &res) {
    if(strlen(arr) > 0) {
        if(!strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", arr[0])) {
            res =  false;
            return;
        } else {
            RecCheckIdenFunc(arr + 1, res); return;
        }
    }
    res = false;
}

int main() {
    setlocale(0, "Russian");
    char str[25];
    do {
        cin >> str;
        bool ch;
        CheckIdenFunc(str, ch);
        cout << ch << endl;
    } while(strcmp(str, "end"));
    return 0;
}