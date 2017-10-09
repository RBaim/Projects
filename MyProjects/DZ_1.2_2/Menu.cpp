#include "Menu.h"

int Menu::STACK::num = 0;

Menu::STACK *Menu::stack = nullptr;

void Menu::push(STACK *&stack, Menu *i) {
    STACK *last_stack = stack;
    stack = new STACK;
    STACK::num++;
    stack->elem = i;
    stack->last = last_stack;
}

Menu *Menu::pop(STACK *&stack) {
    Menu *pop_elem = stack->elem;
    STACK *temp = stack;
    stack = stack->last;
    delete temp;
    STACK::num--;
    return pop_elem;
}

void Menu::PushLine(std::string name, Menu *A, FN a) {
    line.resize(line.size() + 1);
    line[count_line].NameFunc = std::to_string(count_line + 1) + ". " + name;
    if (&A != nullptr)
        line[count_line].Next = A;
    if (a != nullptr)
        line[count_line].Func = *a;
    count_line++;
}

std::ostream &operator<<(std::ostream &stream, Menu &obj) {
    for (int i = 0; i < obj.count_line; i++)
        stream << obj.line[i].NameFunc << std::endl;
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
            if (key <= count_line && key > 0) {
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
                if (line[key - 1].Func != nullptr && line[key - 1].Next == nullptr) {
                    line[key - 1].Func();
                    std::cout << "Input Enter>";
                    fflush(stdin);
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                    '\n');//Ожидание действия пользователя после выполнения программы
                    //while (getchar() != '\n');
                    std::cin.get();//
                    system("cls");//Очистка экрана
                }
            }
        }
    }
}

