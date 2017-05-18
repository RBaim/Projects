#include <cstring>
#include <clocale>
#include <conio.h>

#include <iostream>

struct element {
    int num;
    element *next;
};

void sort(element **first) {
    element *a, *b, *c;
    a = *first;
    bool flag = false;
    if (a->next != NULL) {
        while (flag == false) {
            flag = true;
            a = *first;
            b = a->next;
            c = b->next;
            if (a->num > b->num && a == *first) {
                flag = false;
                a->next = b->next;
                b->next = a;
                std::swap(a, b);
                *first = a;
            }
            while (c != NULL) {
                if (a->num > b->num && a == *first) {
                    flag = false;
                    a->next = b->next;
                    b->next = a;
                    std::swap(a, b);
                    *first = a;
                }
                if (b->num > c->num) {
                    flag = false;
                    a->next = c;
                    b->next = c->next;
                    c->next = b;
                    std::swap(b, c);
                }
                a = a->next;
                b = b->next;
                c = c->next;
            }
        }
    }
}

void prinst(struct element *p) {
    element *y = p;
    while (y != NULL) {
        printf("%d\n", y->num);
        y = y->next;
    }
}

void form(FILE* f, element **first) {
    element *one = NULL, *two = NULL;
    int form;
    while(fscanf(f, "%d ", &form) != EOF) {
        one = new element;
        one->num = form;
        one->next = NULL;
        if(two) {
            two->next = one;
        } else {
            *first = one;
        }
        two = one;
    }

}

void shetsummcrat3(element *first) {
    int sum = 0;
    bool key = false;
    printf("Числа кратные 3:\n");
    while (first) {
        if (first->num % 3 == 0) {
            key = true;
            sum+=first->num;
            printf("%d\n", first->num);
        }
        first = first->next;
    }
    if(key) {
        printf("Сумма: %d\n", sum);
    } else {
        printf("Нет чисел кратных 3!\n");
    }
}

void delstr(struct element **q) {
    element *a = *q, *b = *q;
    q = NULL;
    while (a->next != NULL) {
        b = a;
        a = a->next;
        delete b;
    }
    delete a;
}

int main() {
    setlocale(0, "Russian");
    element *first = NULL;
    FILE *f = fopen("test.txt", "r");
    if(f) {
        form(f, &first);
        printf("Сформированный список\n\n");
        prinst(first);
        printf("\nОтсортированный список\n\n");
        sort(&first);
        prinst(first);
        shetsummcrat3(first);
        delstr(&first);
    } else {
        printf("Not found file test.txt\n");
    }
    getch();
    return 0;
}