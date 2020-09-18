#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search.h"

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_array(int *arr, int arr_size) {
	for (int i = 0; i < arr_size; i++) {
		printf("%d ", arr[i]);
	}
	puts("");
}

int *bubble_sort(int *arr, size_t arr_size) {
	short isSorted;
	for (int i = 0; i < arr_size - 1; i++) {
		isSorted = 1;
		for (int j = 0; j < arr_size - i - 1; j++) {
			if (arr[j] > arr[j+1]) {
			    swap(&arr[j], &arr[j+1]);
			    isSorted = 0;
			}
		}
		if (isSorted == 1)
			break;
	}
	return arr;
}


