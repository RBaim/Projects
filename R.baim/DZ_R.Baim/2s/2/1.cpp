#include <iostream>

struct Trades{//Вспомогательная струтуры для работы с элементами в текстовом файле
    char ProductName[25];
    char Country[25];
    int Direction;
    int Year, DealV;
}trade;

void PrintFile(FILE *f) {//Функция вывода файла
    if (f != NULL) {
        int i = 1;
        rewind(f);
        printf("(№)Наименование товара | страна производитель | год сделки | ");
        printf("объём | направление\n");
        while (fscanf(f, "%s %s %d %d %d\n", trade.ProductName, trade.Country, &trade.Year, &trade.DealV, &trade.Direction) != EOF) {//Чтение происходит по такому формату, так как надо считать каждый элемент струтуры отдельно. Было решено отделять их в файле пробелами
            printf("%3d.%-25s %-20s %-4d %10d     ", i, trade.ProductName, trade.Country, trade.Year, trade.DealV);
            if (trade.Direction == 1) {
                printf(" %-7s\n", "импорт");
            } else {
                printf(" %-7s\n", "экспорт");
            }
            i++;
        }
        rewind(f);
        std::cin.ignore(); std::cin.get();
        system("cls");
    }
}


void NewFile(FILE *f, char *name) {//Функция создания нового файла
    printf("Введите название файла\n");
    std::cin >> name;
    fcloseall();
    f = fopen(name, "w+");
    system("cls");
}

int strlen(FILE *f) {//Процедура оперделения колличества элементов(струтурных) в файле
    if (f != NULL) {
        int i = 1;
        rewind(f);
        while (fscanf(f, "%s %s %d %d %d\n", trade.ProductName, trade.Country, &trade.Year, &trade.DealV, &trade.Direction) != EOF) {
            i++;
        }
        rewind(f);
        return i;
    }
    return 0;
}

void OpenFile(FILE *f, char *name) {//Функция открытия файла нового
    printf("Введите название файла\n");
    std::cin >> name;
    f = fopen(name, "r");
    PrintFile(f);
}

void RedactNewInfoFile(FILE *f) {//Добавление новой информации в файл
    if (f != NULL) {
        int count;
        printf("Введите количество вводимых элементов\n");
        std::cin >> count;
        printf("Формат ввода информации: ");
        printf("наименование товара, страна производитель,год сделки, ");
        printf("объём, направление(импорт-1, экспорт-0)\n");
        fseek(f, -2, SEEK_END);
        for (int i = 0; i < count; i++) {
            scanf("%s %s %d %d %d", &trade.ProductName, &trade.Country, &trade.Year, &trade.DealV, &trade.Direction);
            fprintf(f, "%s %s %d %d %d\n", trade.ProductName, trade.Country, trade.Year, trade.DealV, trade.Direction);
        }
        system("cls");
    }
}

void DelFileInfo(FILE *f, char *NameFile) {//Удаление информации по номерам элементов выводимых при чтении
    if (f != NULL) {
        FILE *out = fopen("tmp.txt", "w+");
        PrintFile(f);
        int num;
        bool res = false;
        printf("Введите номер удаляемого товара\n");
        std::cin >> num;
        if (num > 0 && num <=strlen(f)) {
            for (int i = 1; i < num && fscanf(f, "%s %s %d %d %d\n", trade.ProductName, trade.Country, &trade.Year, &trade.DealV, &trade.Direction) != EOF; i++) {
                fprintf(out, "%s %s %d %d %d\n", trade.ProductName, trade.Country, trade.Year, trade.DealV, trade.Direction);
                res = true;
            }
            if (fscanf(f, "%s %s %d %d %d\n", trade.ProductName, trade.Country, &trade.Year, &trade.DealV, &trade.Direction) != EOF) {
                res = true;
                while (fscanf(f, "%s %s %d %d %d\n", trade.ProductName, trade.Country, &trade.Year, &trade.DealV, &trade.Direction) != EOF) {
                    fprintf(out, "%s %s %d %d %d\n", trade.ProductName, trade.Country, trade.Year, trade.DealV, trade.Direction);
                }
            }
            else {
                res = false;
            }
            fclose(f); fclose(out);
            remove(NameFile);
            rename("tmp.txt", NameFile);
            f = fopen(NameFile, "r");
        } else {
            res = false;
        }
        if (res) {
            printf("Удаление прошло успешно!\n");
        } else {
            printf("Элемент не найден!\n");
        }
        std::cin.ignore(); std::cin.get(); system("cls");
    }
}

void SearchCountry(FILE *f) {//Поиск страны и импортируемых ее товаров
    if (f != NULL) {
        char nameC[25];
        int sumV = 0;
        rewind(f);
        printf("Введите название страны\n");
        std::cin >> nameC;
        printf("Найденные товары:\n");
        while (fscanf(f, "%s %s %d %d %d\n", trade.ProductName, trade.Country, &trade.Year, &trade.DealV, &trade.Direction) != EOF) {
            if (strcmp(nameC, trade.Country) == 0 && trade.Direction == 1) {
                printf("%s\n", trade.ProductName);
                sumV += trade.DealV;
            }
        }
        printf("Суммарный объем сделок импорта:%d\n", sumV);
        rewind(f);
    }
}

void MaxExport(FILE *f) {//Поиск страны с максимальным экспортом
    char TmpC[25], CountryMax[25];
    int sum = 0, sumk = 0;
    for (int i = 1; i <= strlen(f); i++) {
        sum = 0;
        rewind(f);
        for (int j = 0; j <= i; j++) {
            fscanf(f, "%s %s %d %d %d\n", trade.ProductName, trade.Country, &trade.Year, &trade.DealV, &trade.Direction);
        }
        strcpy(TmpC, trade.Country);
        rewind(f);
        while (fscanf(f, "%s %s %d %d %d\n", trade.ProductName, trade.Country, &trade.Year, &trade.DealV, &trade.Direction) != EOF) {
            if (strcmp(trade.Country, TmpC) == 0 && trade.Direction == 0) {
                sum += trade.DealV;
            }
        }
        if (sum > sumk) {
            sumk = sum;
            strcpy(CountryMax, TmpC);
        }
    }
    printf("Страна с максимальным экспортом - %s \nСуммарный объём - %d", CountryMax, sumk);
}

void SearchProduct(FILE *f) {//Поиск стран с импортируемым данным продуктом
    if (f != NULL) {
        char Product[25];
        printf("Введите имя товара\n");
        std::cin >> Product;
        printf("Найденные страны с импортируемым данным товаром и объёмом:\n");
        rewind(f);
        while (fscanf(f, "%s %s %d %d %d\n", trade.ProductName, trade.Country, &trade.Year, &trade.DealV, &trade.Direction) != EOF) {
            if (strcmp(trade.ProductName, Product) == 0 && trade.Direction == 1) {
                printf("%-25s %5d\n", trade.Country, trade.DealV);
            }
        }
        rewind(f);
    }
}

void sms1() {//Меню главное
    printf("1.Создать файл\n");
    printf("2.Отрыть файл\n");
    printf("3.Просмотреть файл\n");
    printf("4.Редактировать файл\n");
    printf("5.Запросы\n");
    printf("6.Выход\n");
}

void sms2() {//Меню редактирования
    printf("1.Добавить элемент(ы)\n");
    printf("2.Удалить элемент\n");
}

void sms3() {//Меню запросов
    printf("1.Определить все товары, импортируемые из данной страны и суммарный объем сделок\n");
    printf("2.Определить страну, экспорт в которую имеет наибольший объем\n");
    printf("3.Определить все страны, из которых импортируется данный товар, и объем сделок в каждом случае\n");
}

int main() {
    system("chcp 1251");
    system("color f0");
    system("cls");
    char name[25];
    strcpy(name, "base.txt");
    int n;
    printf("Стандартное имя базы данных base.txt\n");
    FILE *f = fopen("base.txt", "a+");//Файл по умолчанию с базой данных
    do {//Реализация меню
        sms1();
        std::cin >> n; system("cls");
        switch (n) {
        case 1:NewFile(f, name); break;
        case 2:OpenFile(f, name); break;
        case 3:PrintFile(f); break;
        case 4:sms2(); std::cin >> n; system("cls");
            switch (n) {
            case 1:RedactNewInfoFile(f); break;
            case 2:DelFileInfo(f, name);
            }
            break;
        case 5:sms3(); std::cin >> n; system("cls");
            switch (n) {
            case 1:SearchCountry(f); break;
            case 2:MaxExport(f); break;
            case 3:SearchProduct(f);
            }
            std::cin.ignore(); std::cin.get(); system("cls");
        }
    } while (n != 6);
    fcloseall();
    return 0;
}
