#include <iostream>


int SumChisl(int n) {
    if (n / 10 != 0)
        return n % 10 + SumChisl(n / 10);
    return n;
}

void OutChObrat(int n) {
    if (n / 10 == 0) std::cout << n;
    else {
        std::cout << n % 10;
        OutChObrat(n / 10);
    }
}

int Fibonachi(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    else {
        return Fibonachi(n - 1) + Fibonachi(n - 2);
    }
}

void IntToBinary(int n) {
    if (n / 2)
        IntToBinary(n / 2);
    std::cout << n % 2;
}

void Hanoy(char one, char two, char tree, int n) {
    if (n == 1) {
        std::cout << one << " -> " << tree << std::endl;
    }
    else {
        Hanoy(one, tree, two, n - 1);
        std::cout << one << " -> " << tree << std::endl;
        Hanoy(two, one, tree, n - 1);
    }
}

int main() {
    int num;
    std::cin >> num;
    int a = num; int b = 0, c = 0;
    std::cout << "a b c" << std::endl;
    Hanoy('a', 'b', 'c', num);
    std::cout << std::endl;
    system("pause");
    return 0;
}