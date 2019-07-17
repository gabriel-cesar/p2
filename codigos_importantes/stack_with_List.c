#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//LIFO = Last In, Firts Out
//PUSH = add a element to the stack top
//POP  = remove the element from the stack top
//PEEK = returns (wthiout removing) the top element

typedef struct NODE{
	int item;
	struct NODE *next;
}NODE;

typedef struct stack{
	NODE *top;
}stack;

stack *create_stack(){
	stack *new_stack = (stack*) malloc(sizeof(stack));
	new_stack->top = NULL;

	return new_stack;
}

stack *push(stack *stack, int item){
	NODE *new_top = (NODE*) malloc(sizeof(NODE));

	new_top->item = item;
	new_top->next = stack->top;

	stack->top = new_top;

	return stack;
}

int pop(stack *s){
	NODE *aux = s->top;

	if(s->top == NULL){
		return -1;
	} else{
		s->top = aux->next;
		free(aux);

		return 0;
	}
}

void *print_stack(stack *s){
	NODE *current = s->top;

	while(current != NULL){
		printf("%d\n", current->item);

		current = current->next;
	}

	// return s;
}

int peek(stack *s){
	if(s->top == NULL){
		printf("Stack Underflow\n");
		return -1;
	} else{
		return s->top->item;
	}
}

int main(){
	stack *stack = create_stack();

	int i;
	for(i = 1; i <= 10; i++){
		stack = push(stack, i);
	}

	printf("Stack before pop:\n");
	print_stack(stack);

	printf("Stack after pop:\n");
	int ret = pop(stack);

	print_stack(stack);

	ret = peek(stack);
	printf("PEEK: %d\n", ret);

	return 0;
}