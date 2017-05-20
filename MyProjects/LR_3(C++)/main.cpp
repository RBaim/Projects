#include <iostream>
#include <fstream>

#include "Vector.h"
#include "VectorIterator.h"
#include "Algorithm.h"
#include "Exc.h"
#include "List.h"
#include "Student.h"

using namespace std;

bool predicat(int i) {
    if (i % 2 == 0)
        return true;
    return false;
}

void Powin2(int& i) {
    i = i*i;
}

bool True(int i) {
    return true;
}

bool StudentBool(Student c) {
    if (c.num == 33)
        return true;
    return false;
}

template <typename T>
class Func {
public:
    std::ofstream out;
    std::string name;
    Func(std::string name_p) {
        out.open(name_p);
        name = name_p;
    }
    Func(const Func& p) {
        out.open(p.name);
    }
    ~Func() {
        out.close();
    }
    void operator()(typename Vector<T>::value_type i) {
        out << i << ' ';
    }
};

int main() {
    List<Vector<int>> test = { {1, 21, 21}, {6216, 21712, 122}, {0, 220, 228} };
    for (int i = 0; i < test.size(); i++) {
        for (int j = 0; j < test[i].Size(); j++) {
            cout << test[i][j] << ' ';
        }
        cout << endl;
    }
    Vector<Student> n_a = { Student("one", 21), Student("two", 123), Student("three", 33) };
    Sort(n_a.Begin(), n_a.End());
    for (int i = 0; i < n_a.Size(); i++)
        n_a[i].PrintStud();
    Student iffind = FindIf(n_a.Begin(), n_a.End(), [](Student i) {if (i.num == 33) return true; return false; });
    cout << iffind.num << endl;
    Vector<string> n_str = { "one_str", "two_str", "three_str" };
    Sort(n_str.Begin(), n_str.End());
    for (int i = 0; i < n_str.Size(); i++)
        cout << n_str[i].c_str() << endl;
    Vector<int> a = { 6, 4, 5, 3, 1 };
    cout << "Vector a" << endl;
    for (int i = 0; i < a.Size(); i++)
        cout << a[i] << ' ';
    cout << endl;
    std::ofstream fout("test1.txt");
    forEach(a.Begin(), a.End(), [&fout](int i) { fout << i << ' '; });
    fout.close();
    forEach(a.Begin(), a.End(), Func<int>("2.txt"));
    List<int> a_c(6, 0);
    a.Insert(a.Begin() + 1, 2);
    a.PushBack(9);
    a.Erase(a.End());
    Copy(a.Begin(), a.End(), a_c.begin());
    cout << "Copy in list a_c" << endl;
    for (int i = 0; i < a_c.size(); i++)
        cout << a_c[i] << ' ';
    cout << endl;
    cout << *MinElement(a_c.begin(), a_c.end()) << endl;
    Vector<int> a_c_v(6);
    Copy(a_c.begin(), a_c.end(), a_c_v.Begin());
    cout << "Copy in Vector a_c_v" << endl;
    for (int i = 0; i < a_c_v.Size(); i++)
        cout << a_c_v[i] << ' ';
    cout << endl;
    cout << "Vector a" << endl;
    for (int i = 0; i < a.Size(); i++)
        cout << a[i] << ' ';
    cout << endl;
    int min = MinElement(a.Begin(), a.End());
    int max = MaxElement(a.Begin(), a.End());
    cout << "min: " << min << endl;
    cout << "max: " << max << endl;
    int crt = FindIf(a.Begin(), a.End(), predicat);
    cout << "FindIf(%2): " << crt << endl;
    cout << "Vector" << endl;
    for (int i = 0; i < a.Size(); i++)
        cout << a[i] << ' ';
    cout << endl;
    Sort(a.Begin(), a.End());
    cout << "Sorted" << endl;
    for (int i = 0; i < a.Size(); i++)
        cout << a[i] << ' ';
    cout << endl;
    Vector<int> b(3, 0);
    CopyIf(a.Begin(), a.End(), b.Begin(), predicat);
    cout << "copyIf(%2)" << endl;
    for (int i = 0; i < b.Size(); i++)
        cout << b[i] << ' ';
    cout << endl;
    forEach(a.Begin(), a.End(), Powin2);
    cout << "ForEach(powIn2)" << endl;
    for (int i = 0; i < a.Size(); i++)
        cout << a[i] << ' ';
    cout << endl;
    system("pause");
    return 0;
}