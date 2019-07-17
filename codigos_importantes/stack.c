#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10

//LIFO = Last In, Firts Out
//PUSH = add a element to the stack top
//POP  = remove the element from the stack top
//PEEK = returns (wthiout removing) the top element

//int peek (stack *stack);
//int is_empty (stack *stack);

typedef struct stack{
	int current_size;
	int items[MAX_STACK_SIZE];
}stack;

stack *creat_stack(){
	stack *new_stack = (stack*) malloc(sizeof(stack));
	new_stack->current_size = 0;

	return new_stack;
}

void push(stack *stack, int item){
	if(stack->current_size == MAX_STACK_SIZE){
		printf("Stack overflow\n");
	} else{
		stack->items[stack->current_size++] = item;
	}
}

int pop(stack *stack){
	if(stack->current_size == 0){
		printf("Stack Underflow\n");
		return -1;
	} else{
		return stack->items[--stack->current_size];
	}
}

int peek(stack *stack){
	if(stack->current_size == 0){
		printf("Stack Underflow\n");
		return -1;
	} else{
		return stack->items[stack->current_size - 1];
	}
}

int main(){
	int i;

	stack *stack = creat_stack();
	
	push(stack, 5);
	push(stack, 6);

	printf("CURRENT SIZE: %d\n", stack->current_size);
	for(i = 0; i < stack->current_size; i++){
		printf("%d\n", stack->items[i]);
	}

	// int ret = pop(stack);
	// if(ret == 0) printf("The item was removed\n");

	int ret = peek(stack);
	printf("ret: %d\n", ret); //valor retornado

	return 0;
}