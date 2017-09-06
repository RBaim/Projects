#pragma once

class Ships {
private:
    char **arr;
    int size;
    int x;
    int y;
    bool dir;
    bool kill;
public:
    Ships() = default;
    Ships(int size, int x, int y, bool dir, char **arr);
    Ships(const Ships& copy);
    bool DestrCh();
    Ships operator&=(const Ships& p);
};
