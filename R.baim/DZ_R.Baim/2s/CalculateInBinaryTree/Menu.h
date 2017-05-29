#pragma once

#include <string.h>

#include <iostream>
#include <limits>

typedef void(*FN)(void);

class Menu {
    static struct STACK {
        static int num;
        Menu *elem;
        STACK *last;
    } *stack;
    void push(STACK *&stack, Menu *i);
    Menu *pop(STACK *&stack);
    int lines;
    struct Line {
        char NameFunc[32];
        FN Func;
        Menu *Next;
    } *line;
    friend std::ostream &operator<<(std::ostream &stream, Menu &obj);
public:
    void PushLine(int i, char *name, Menu *A, FN a);
    void Run();
    Menu();
    Menu(int n);
    ~Menu();
};
