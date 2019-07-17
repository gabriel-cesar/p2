#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int linear_search(int *array, int size, int element){
	int i;

	for(i = 0; i < size; i++){
		if(array[i] == element){
			return i;
		}
	}

	return -1;
}

int main() {
	int n; scanf("%d", &n);
	int array[10] = {0,1,2,3,4,5,6,7,8,9};

	int element = linear_search(array, 10, n);

	printf("%d\n", element);

	return 0;
}