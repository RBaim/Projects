#include "sort.h"

void SortBubble(int *array, int size) {
	int temp = 0;
	bool exit = false;
	while (!exit) {
		exit = true;
		for (int i = 0; i < (size - 1); i++) {
			if (array[i] > array[i + 1]) {
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				exit = false;
			}
		}
	}
}
