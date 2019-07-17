#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void filter(int (*f)(int x), int *y){
	int i;

	for(i = 0 ; i < 10 ; i++){
		printf("%d\n", (*f)(y[i]) );
	}
}

int square(int x){
	return x * x;
}

int factorial(int x){
	if (x == 0){
		return 1;
	}
	
	else{
		return x * factorial(x - 1);;
	}
}

int main() {
	int array[10];
	int i;

	for(i = 0; i < 10; i++){
		scanf("%d", &array[i]);
	}

	filter(square, array);
	printf("--------------------\n");
	filter(factorial, array);

	return 0;
}