
#ifndef SORTING_H_
#define SORTING_H_

void swap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void bubbleSort(int* Array, const unsigned int size) {
	for(int i = 0; i < size-1; i++) {
		for(int j = 0; j < size-i-1; j++) {
			if(Array[j] > Array[j+1])
				swap(&Array[j], &Array[j+1]);
		}
	}
}

void selectionSort(int* Array, const unsigned int size) {
	int min;
	for(int i =0; i<size-1; i++) {
		min = i;
		for(int j = i+1; j < size; j++) {
			if(Array[j] < Array[min])
				min = j;
		}
		swap(&Array[min], &Array[i]);
	}
}

void insertionSort(int* Array, const unsigned int size) {
	for(int i = 1; i < size; i++) {
		int key = Array[i];
		int j = i-1;
		while(j >= 0 && Array[j] > key) {
			Array[j+1] = Array[j];
			j--;
		}
		Array[j+1] = key;
	}
}

void mergeSort(int* Array, const unsigned int size) {

}
void quickSort(int* Array, const unsigned int size) {

}

//Optional
void shellSort(int* Array, const unsigned int size);


#endif /* SORTING_H_ */
