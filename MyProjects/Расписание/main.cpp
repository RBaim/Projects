#include <string.h>
#include <iostream>
#include <functional>

using namespace std;

struct Unit {
    int num;
    int kab;
    char name[30];
    char type[4];
    Unit* next;
};

typedef struct TimeTable {
    Unit* lessons;
    char day[10];
} TimeTable;

void InputTimeTable(TimeTable** array) {
    cout << "Input Name day, lessons(name, type, kabinet)" << endl;
    Unit* head, *tmp, *tmp_p;
    for (int i = 0; i < 6; i++) {
        cout << "Day " << i + 1 << endl;
        cin >> array[0][i].day;
        tmp = new Unit;
        tmp_p = head = tmp;
        for (int j = 0; j < 6; j++) {
            if (tmp == NULL) tmp = new Unit;
            cin >> tmp[0].name;
            if (strcmp(tmp[0].name, "end") == 0) {
                delete tmp;
                if (j == 0) head = nullptr;
                tmp = nullptr;
                break;
            }
            cin >> tmp[0].type >> tmp[0].kab;
            tmp[0].num = j + 1;
            tmp[0].next = nullptr;
            if (j != 0) tmp_p->next = tmp;
            tmp_p = tmp;
            tmp = tmp->next;
        }
        array[0][i].lessons = head;
        head = nullptr;
    }
}

void PrintTimeTable(TimeTable* array) {
    Unit* tmp;
    for (int i = 0; i < 6; i++) {
        cout << array[i].day << endl;
        tmp = array[i].lessons;
        while (tmp != nullptr) {
            cout << tmp->num << ' ' << tmp->name << ' ' << tmp->type << ' ' << tmp->kab << endl;
            tmp = tmp->next;
        }
    }
}

void DelTimeTableList(TimeTable** array) {
    Unit* tmp1, *tmp2;
    for (int i = 0; i < 6; i++) {
        tmp1 = array[0][i].lessons;
        while (tmp1 != NULL) {
            tmp2 = tmp1->next;
            tmp1[0].next = nullptr;
            delete tmp1;
            tmp1 = tmp2;
        }
        array[0][i].lessons = nullptr;
    }
}

void CountTypeTimeTable(TimeTable* array) {
    Unit* tmp;
    int sem, lab, lek;
    for (int i = 0; i < 6; i++) {
        sem = lab = lek = 0;
        cout << array[i].day << endl;
        tmp = array[i].lessons;
        while (tmp != NULL) {
            if (strcmp(tmp->type, "sem") == 0) sem++;
            if (strcmp(tmp->type, "lab") == 0) lab++;
            if (strcmp(tmp->type, "lek") == 0) lek++;
            tmp = tmp->next;
        }
        cout << "sem: " << sem << " lab: " << lab << " lek: " << lek << endl;
    }
}

void DelsIf(TimeTable** array, function<bool(Unit*)> pred) {
    Unit *tmp1, *tmp2 = NULL;
    for (int i = 0; i < 6; i++) {
        tmp1 = array[0][i].lessons;
        while (pred(tmp1)) {
            array[0][i].lessons = tmp1->next;
            delete tmp1;
            tmp1 = array[0][i].lessons;
        }
        if (tmp1 != NULL) tmp2 = tmp1->next;
        while (tmp1 != NULL) {
            if (pred(tmp2)) {
                tmp1->next = tmp2->next;
                delete tmp2;
                tmp2 = tmp1->next;
            }
            tmp1 = tmp1->next;
            if (tmp2) tmp2 = tmp2->next;
        }
    }
}

bool predicate(Unit* u) {
    if (u == NULL) return false;
    if (u->kab / 500 == 0) return true;
    return false;
}

int main() {
    TimeTable *week = new TimeTable[6];
    InputTimeTable(&week);
    PrintTimeTable(week);
    cout << endl;
    CountTypeTimeTable(week);
    cout << endl;
    DelsIf(&week, function <bool(Unit*)>(predicate));
    PrintTimeTable(week);
    cout << endl;
    DelTimeTableList(&week);
    delete[] week;
    system("pause");
    return 0;
}