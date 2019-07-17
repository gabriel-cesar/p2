#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void print(int *array, int *n){
	int i;

	for(i = 0; i < *n; i++){
		printf("%d\n", array[i]);
	}
}

void filter(int (*f)(int x), int *y, int *n){
	int i, j;

	for(i = 0; i < *n; i++){
		if((*f)(y[i]) == -1){
			for(j = i; j < *n; j++){
				y[j] = y[j+1];
			}

			y = realloc(y, (*n - 1) * sizeof(int));
			*n = *n - 1;
		}
	}

	print(y, n);
}

int even(int x){
	if(x % 2 == 0){
		return x;
	}
	
	return -1;
}

int odd(int x){
	if(x % 2 == 0){
		return -1;
	}
	
	return x;
}

int main() {
	int *array, n, i;
	char type[4];

	printf("Type the size: ");
	scanf("%d", &n);

	array = malloc(n * sizeof(int));

	for(i = 0; i < n; i++){
		scanf("%d", &array[i]);
	}

	printf("Choose the type of filter (even / odd): ");
	scanf("%s", type);

	if(strcmp(type, "even") == 0){
		filter(even, array, &n); //par
	}

	else if(strcmp(type, "odd") == 0){
		filter(odd, array, &n); //impar
	}

	else{
		printf("Invalid operation\n");
	}



	return 0;
}