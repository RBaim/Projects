#include <iostream>
#include "Components.h"
#include "Menu.h"

MapInfo mp(1000);//1000 is date abs
std::vector<Product> res;

void HeaderTab(std::ostream& st) {
    st<< std::setw(5) << "KEY"
      << std::setw(10)
       << "STOCK_NUM"
       << std::setw(10)
       << "CODE_PROD"
       << std::setw(30)
       << "NAME_PROD"
       << std::setw(10)
       << "DATE"
       << std::setw(10)
       << "VALID"
       << std::setw(15)
       << "COST"
       << std::endl;
}

void HeaderTab2(std::ostream& st) {
    st << std::setw(10)
      << "STOCK_NUM"
      << std::setw(10)
      << "CODE_PROD"
      << std::setw(30)
      << "NAME_PROD"
      << std::setw(10)
      << "DATE"
      << std::setw(10)
      << "VALID"
      << std::setw(15)
      << "COST"
      << std::endl;
}

void NewFile() {
    std::ofstream file("new.bin", std::ios::binary);
    InputInfo(file);
    file.close();
}

void LoadDataoutFile() {
    std::ifstream file("new.bin", std::ios::binary);
    mp.LoadData(file);
    file.close();
}

void OutDataScreen() {
    HeaderTab(std::cout);
    mp.OutData(std::cout);
}

void OutDataFileTxt() {
    std::ofstream file("new.txt");
    HeaderTab(file);
    mp.OnTxt(file);
    file.close();
}


void Findstock() {
    res.clear();
    std::cout << "Input no stock: ";
    int no;
    std::cin >> no;
    res = std::move(mp.FindNoStock(no));
}

void Findcod() {
    res.clear();
    std::cout << "Input no code product: ";
    int no;
    std::cin >> no;
    res = std::move(mp.FindNoCod(no));
}

void Findoverd() {
    res.clear();
    std::cout << "Input true(1) or false(0) for check overdue: ";
    bool co;
    std::cin >> co;
    res = std::move(mp.Overdue(co));
}

void FindesOutRes() {
    HeaderTab2(std::cout);
    std::for_each(res.begin(), res.end(), [](Product& p) { std :: cout << p << std:: endl;});
}

int main() {
    Menu main;
    Menu find;
    main.PushLine("NewFile", nullptr, NewFile);
    main.PushLine("LoadDataoutFile", nullptr, LoadDataoutFile);
    main.PushLine("OutDataScreen", nullptr, OutDataScreen);
    main.PushLine("OutDataFileTxt", nullptr, OutDataFileTxt);
    main.PushLine("Findes", &find, nullptr);
    main.PushLine("Exit", nullptr, nullptr);
    find.PushLine("Findstock", nullptr, Findstock);
    find.PushLine("Findcod", nullptr, Findcod);
    find.PushLine("Findoverd", nullptr, Findoverd);
    find.PushLine("FindesOutRes", nullptr, FindesOutRes);
    find.PushLine("Exit", nullptr, nullptr);
    main.Run();
    return 0;
}