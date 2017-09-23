#include <ctime>

#include <iostream>
#include <fstream>

#include "PieceCod.h"
#include "Menu.h"

std::vector<int> int_vec;

void One() {
    std::ofstream fin("1.txt", std::ios_base::trunc);
    CreateData(std::ostream_iterator<int>(fin, "\n"));
    fin.close();
    std::cout << "All ok" << std::endl;
}

void Two() {
    std::ofstream fin("1.txt", std::ios_base::trunc);
    CreateData(fin, std::true_type());
    fin.close();
    std::cout << "All ok" << std::endl;
}

void Three() {
    std::ifstream fout("1.txt");
    int_vec.clear();
    LoadData(std::back_inserter(int_vec), std::istream_iterator<int>(fout));
    std::cout << "All ok" << std::endl;
    fout.close();
}

void Four() {
    std::ifstream fout("1.txt");
    int_vec.clear();
    LoadData(std::back_inserter(int_vec), fout, std::true_type());
    fout.close();
    std::cout << "All ok" << std::endl;
}

void Five() {
    Modify(int_vec.begin(), int_vec.end());
    std::cout << "All ok" << std::endl;
}

void Six() {
    Modify(int_vec);
    std::cout << "All ok" << std::endl;
}

void Seven() {
    Modify(int_vec.begin(), int_vec.end(), [](int &i){ i = i * i;});
    std::cout << "All ok" << std::endl;
}

void Eight() {
    std::ifstream fout("1.txt");
    std::ofstream fin("2.txt", std::ios_base::out);
    int del = DelSearch(std::istream_iterator<int>(fout));
    fout.close();
    fout.open("1.txt");
    Modify(std::istream_iterator<int>(fout), std::ostream_iterator<int>(fin, "\n"), [&del](int i){ return i/del;});
    fin.close();
    fout.close();
    std::cout << "All ok" << std::endl;
}

void Nine() {
    std::ofstream fin("1.txt", std::ios_base::trunc);
    OutputResult(int_vec.begin(), int_vec.end(), fin, std::true_type());
    fin.close();
    std::cout << "All ok" << std::endl;
}

void Ten() {
    std::ofstream fin("1.txt", std::ios_base::trunc);
    OutputResult(int_vec.begin(), int_vec.end(), std::ostream_iterator<int>(fin, "\n"));
    OutputResult(int_vec.begin(), int_vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    fin.close();
    std::cout << "All ok" << std::endl;
}

int main() {
    srand(time(NULL));
    Menu menu;
    menu.PushLine("CreateData(std::ostream_iterator<int>(file)", nullptr, One);
    menu.PushLine("CreateData(fin)", nullptr, Two);
    menu.PushLine("LoadData(std::back_inserter(int_vec), std::istream_iterator<int>(fout))", nullptr, Three);
    menu.PushLine("LoadData(Iter beg, Iter end, std::istream& stream)", nullptr, Four);
    menu.PushLine("Modify(int_vec.begin(), int_vec.end())", nullptr, Five);
    menu.PushLine("Modify(int_vec)", nullptr, Six);
    menu.PushLine("Modify(int_vec.begin(), int_vec.end(), [](int &i) { i *= i;})", nullptr, Seven);
    menu.PushLine("Modify(std::istream_iterator<int>(fout), std::ostream_iterator<int>(fin, \\n))", nullptr, Eight);
    menu.PushLine("OutputResult(int_vec.begin(), int_vec.end(), fin)", nullptr, Nine);
    menu.PushLine("OutputResult(int_vec.begin(), int_vec.end(), std::ostream_iterator<int>(fin)", nullptr, Ten);
    menu.PushLine("Exit", nullptr, nullptr);
    menu.Run();
    return 0;
}