#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void bubble_sort(int *array, int size){
	int i, j, aux;

	for(i = 0; i < size - 1; i++){
		for(j = 0; j < size - 1; j++){
			if(array[j] >= array[j+1]){
				aux = array[j+1];
				array[j+1] = array[j];
				array[j] = aux;
			}
		}
	}
}

int binary_search(int *array, int size, int element){
	int start = 0, end = size - 1, middle;

	while(start <= end){
        middle = (start + end)/2;

        if(array[middle] < element) start = middle + 1;
        else if(array[middle] > element) end = middle - 1;
        else return middle;
    }

	return -1;
}

int main(){
	int i, n;
	int array[10];

	for(i = 0; i < 10; i++){
		scanf("%d", &array[i]);
	}

	scanf("%d", &n);

	bubble_sort(array, 10);
	int element = binary_search(array, 10, n);

	printf("%d\n", element);

	return 0;
}