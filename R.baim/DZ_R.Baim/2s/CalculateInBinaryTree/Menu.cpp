#include "Menu.h"

int Menu::STACK::num = 0;

Menu::STACK *Menu::stack = nullptr;

void Menu::push(STACK* &stack, Menu* i) {
    STACK *last_stack = stack;
    stack = new STACK;
    STACK::num++;
    stack->elem = i;
    stack->last = last_stack;
}

Menu* Menu::pop(STACK* &stack) {
    Menu *pop_elem = stack->elem;
    STACK *temp = stack;
    stack = stack->last;
    delete temp;
    STACK::num--;
    return pop_elem;
}

Menu::Menu(int n) {
    line = new Line[n];
    lines = n;
    for (int i = 0; i < n; i++) {
        *(line + i)->NameFunc = '\0';
        (*(line + i)).Next = nullptr;
        (*(line + i)).Func = nullptr;
    }
}

Menu::Menu() {
    lines = 0;
    line = nullptr;
}

Menu::~Menu() {
    if (lines != 0) {
        for (int i = 0; i < lines; i++) {
            (*(line + i)).Next = nullptr;
            (*(line + i)).Func = nullptr;
        }
        delete[] line;
        lines = 0;
    }
}

void Menu::PushLine(int i, char *name, Menu* A, FN a) {
    if (*(line + i)->NameFunc == '\0') {
        strcpy((*(line + i)).NameFunc, name);
        if (&A != nullptr) {
            (*(line + i)).Next = A;
        }
        if (a != nullptr) {
            (*(line + i)).Func = *a;
        }
    }
}

std::ostream& operator << (std::ostream &stream, Menu &obj) {
    for (int i = 0; i < obj.lines; i++)
        stream << (*(obj.line + i)).NameFunc << std::endl;
    stream << ">";
    return stream;
}

void Menu::Run() {
    if (this != nullptr) {
        int key;
        while (1) {
            std::cout << *this;//Отображение меню
            std::cin >> key;
            system("cls");//Очистка экрана
            if (key <= lines && key > 0) {
                if (line[key - 1].Next == nullptr && line[key - 1].Func == nullptr && STACK::num) {
                    pop(stack)->Run();//Выгрузка из стека, подъем
                    break;
                }
                if (line[key - 1].Func != nullptr && line[key - 1].Next != nullptr) {
                    line[key - 1].Func();
                    if (line[key - 1].Next != this) {
                        if (STACK::num && stack->elem == line[key - 1].Next) {
                            pop(stack)->Run();//Выгрузка из стека
                            break;
                        }
                        push(stack, this);//Загрузка в стек
                        line[key - 1].Next->Run();
                        break;
                    }
                }
                if (line[key - 1].Func == nullptr) {
                    if (line[key - 1].Next != this) {
                        if (STACK::num && stack->elem == line[key - 1].Next) {
                            pop(stack)->Run();//Выгрузка из стека
                            break;
                        }
                        push(stack, this);//Загрузка в стек
                        line[key - 1].Next->Run();
                        break;
                    }
                }
                if(line[key - 1].Func != nullptr && line[key - 1].Next == nullptr) {
                    line[key - 1].Func();
                    std::cout << "Input Enter>";
                    fflush(stdin);
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Ожидание действия пользователя после выполнения программы
                    //while (getchar() != '\n');
                    std::cin.get();//
                    system("cls");//Очистка экрана
                }
            }
        }
    }
}

