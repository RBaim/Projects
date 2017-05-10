#include <clocale>

#include <iostream>

using namespace std;


int Search_Binary(int arr[], int left, int right, int key, int &iter) {
    int midd = 0;
    iter = 0;
    while (1) {
        midd = (left + right) / 2;
        if (key < arr[midd]) {
            iter++;
            right = midd - 1;
        } else if (key > arr[midd]) {
            iter++;
            left = midd + 1;
        } else {
            return midd;
        }
        if (left > right) {
            return -1;
        }
    }
}

int SearchArray(int *array, int size, int search, int &count) {
    count = 0;
    for (int i = 0; i < size; i++) {
        count++;
        if (array[i] == search) {
            return i;
        }
    }
    return -1;
}

int main() {
    setlocale(0, "russian");
    const int SIZE = 12;
    int array[SIZE] = {};
    int key = 0;
    int iter = 0;
    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        array[i] = i + 1;
        cout << array[i] << " | ";
    }
    cout << "\n\nInput search element: ";
    cin >> key;
    cout << "Binary search in array" << endl;
    index = Search_Binary(array, 0, SIZE, key, iter);
    if (index >= 0)
        cout << "Search in position array: " << index << "\n";
    else
        cout << "Not found!\n\n";
    cout << "Iteration: " << iter << endl;
    cout << "Search bored in array" << endl;
    index = SearchArray(array, SIZE, key, iter);
    if (index >= 0)
        cout << "Search in position array: " << index << "\n";
    else
        cout << "Not found!\n\n";
    cout << "Iteration: " << iter << endl;
    return 0;
}