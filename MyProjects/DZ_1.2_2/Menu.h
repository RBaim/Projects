#pragma once

#include <string.h>

#include <iostream>
#include <limits>
#include <vector>

typedef void(*FN)(void);

class Menu {
    static struct STACK {
        static int num;
        Menu *elem;
        STACK *last;
    } *stack;
    void push(STACK *&stack, Menu *i);
    Menu *pop(STACK *&stack);
    struct Line {
        std::string NameFunc;
        FN Func;
        Menu *Next;
    };
    std::vector<Line> line;
    int count_line = 0;
    friend std::ostream &operator<<(std::ostream &stream, Menu &obj);
public:
    void PushLine(std::string name, Menu *A, FN a);
    void Run();
};
