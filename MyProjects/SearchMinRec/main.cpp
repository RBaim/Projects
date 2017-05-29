#include <ctime>

#include <iostream>

#define MAX_ERR 999999

int min(int one, int two) {
    if (one > two) return two;
    else return one;
}

int SearchMin(int *arr, int size) {
    if (arr && size == 1) return *arr;
    if (size && arr) {
        int i = rand() % size;
        return min(SearchMin(arr, i), SearchMin(arr + i, size - i));
    } else {
        return MAX_ERR;
    }
}

int main() {
    srand(time(NULL));
    int arr[10];
    for (int i = 0; i < 10; i++) std::cin >> arr[i];
    std::cout << std::endl;
    for (int i = 0; i < 10; i++) std::cout << arr[i] << ' ';
    std::cout << std::endl;
    std::cout << SearchMin(arr, 10) << std::endl;
    return 0;
}