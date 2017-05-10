#include <Windows.h>

#include <time.h>

#include <iostream>

using namespace std;

void(*SortBubble)(int *, int);

int main() {
	HINSTANCE dll;
	system("chcp 1251");
	system("cls");
	dll = LoadLibrary(L"DllSortBubble.dll");
	if (dll != NULL) {
		SortBubble = (void(*)(int *, int))GetProcAddress(dll, "SortBubble");
		if (SortBubble == NULL) {
			FreeLibrary(dll);
			return -1;
		}
	}
	else {
		return -1;
	}
	system("color f0");
	srand(time(NULL));
    int *array;
    int size;
    cout << "Введите количество элементов массива\n";
    cin >> size;
    array = new int[size];
    for (int i = 0; i < size; i++) 
        array[i] = rand() % 10 - rand() % 10;
    cout << "Случайные элементы массива\n";
    for (int i = 0; i < size; i++) 
        cout << array[i] << " ";
    cout << endl;
    SortBubble(array, size);
    cout << "Отсортированный массив\n";
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
    delete[] array;
    FreeLibrary(dll);
    return 0;
}
