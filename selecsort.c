#include <stdio.h>

void PrintArray(int* array, int size) {
	for (int i = 0; i < size; ++i)
		printf("%d ", array[i]);
	printf("\n");
}

void Swap(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void SelecSort(int* array, int size) {
	for (int i = 0; i < size-1; ++i) {
		int maxPos = 0;
		for (int j = 1; j < size - i; ++j) {
			if (array[j] > array[maxPos])
				maxPos = j;
		}
		if (maxPos != size - 1 - i)
			Swap(&array[maxPos], &array[size - 1 - i]);
	}
}

void SelecSortOP(int* array, int size) {
	int begin = 0, end = size - 1;
	while (begin < end) {
		int maxPos = begin;
		int minPos = begin;

		for (int i = begin; i <= end; ++i) {
			if (array[i] < array[minPos])
				minPos = i;
			if (array[i] > array[maxPos])
				maxPos = i;
		}
		if (minPos != begin)
			Swap(&array[begin], &array[minPos]);
		if (maxPos == begin)
			maxPos = minPos;
		if (maxPos != end)
			Swap(&array[end], &array[maxPos]);
		begin++;
		end--;
	}
}

int main() {
	int array[] = { 5,3,7,1,0,8,2,6,4,9 };
	SelecSortOP(array, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));

	return 0;
}