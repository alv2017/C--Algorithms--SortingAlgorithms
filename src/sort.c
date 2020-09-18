#include <stdio.h>
#include <stdlib.h>

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

// Change int to size_t
int *bubble_sort(int *arr, size_t arr_size) {
	short isSorted;
	for (size_t i = 0; i < arr_size - 1; i++) {
		isSorted = 1;
		for (size_t j = 0; j < arr_size - i - 1; j++) {
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

int *insert_sort(int *arr, size_t arr_size) {
	int temp;
	size_t j;
	for (size_t i = 1; i < arr_size; i++) {
		temp = arr[i];
		j = i-1;
		while (temp < arr[j] && j < arr_size) {
			arr[j+1] = arr[j];
			if (j > 0)
			    j--;
			else {
				// j is of type size_t and can not be negative,
				// so we set it to be equal arr_size instead of -1
 				j=arr_size;
			}
		}
		if (j == arr_size) {
			arr[0] = temp;
		}
		else {
		    arr[j+1] = temp;
		}
	}
	return arr;
}

