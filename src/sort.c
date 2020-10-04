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

int *smallest_element(int *arr, size_t arr_size, size_t k) {
	int *smallest = &arr[k];

	for (int i = k + 1; i < arr_size; i++) {
		if (*smallest > arr[i]) {
			smallest = &arr[i];
		}
	}
	return smallest;
}

int *merge(int *arr, int beg, int mid, int end) {
	int i = beg;
	int j = mid + 1;
	int idx = 0;

	int temp_size = end - beg + 1;
	int *temp = calloc(temp_size, sizeof(int));

	while (i <= mid && j <= end) {
		if (arr[i] < arr[j]) {
			temp[idx] = arr[i];
			i++;
		}
		else {
			temp[idx] = arr[j];
			j++;
		}
		idx++;
	}

	if (i > mid) {
		while (j <= end) {
			temp[idx] = arr[j];
			j++;
			idx++;
		}
	}
	else {
		while (i <= mid) {
			temp[idx] = arr[i];
			i++;
			idx++;
		}
	}
	for (int k = beg; k <= end; k++) {
		arr[k] = temp[k-beg];
	}
	free(temp);
	return arr;
}

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

int *selection_sort(int *arr, size_t arr_size){
	int *smallest = NULL;
	for (int i= 0; i < arr_size - 1; i++) {
		smallest = smallest_element(arr, arr_size, i);
		swap(smallest, &arr[i]);
	}
	return arr;
}

int *merge_sort(int *arr, size_t arr_size) {
	int beg =0;
	int end = arr_size - 1;
	if (beg < end) {
		int mid = (beg + end) / 2;
		merge_sort(arr, mid + 1);
		merge_sort(&arr[mid+1], end - mid);
		merge(arr, beg, mid, end);
	}
	return arr;
}

int main() {
	int arr[12] = {23, 12, 3, 28, 4, 10, 7, 9, 15, 5, 100, 20};
	printf("Initial array:\n");
	print_array(arr, 10);

	printf("Sorted array:\n");
	merge_sort(arr, 10);
	print_array(arr, 10);
	return 0;
}







