#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct NODE{
	int item;
	struct NODE *next;
}NODE;

NODE *creating_node(int element){
	NODE *new_node = (NODE*) malloc(sizeof(NODE));
	new_node -> item = element; 
	new_node -> next = NULL;

	return new_node;
}

NODE *add_end(NODE *head, int element){
	NODE *new_node = (NODE*) malloc(sizeof(NODE));
	new_node -> item = element;
	new_node -> next = NULL;

	NODE *current_node = head;

	while(current_node -> next != NULL){
		current_node = current_node -> next; 
	}

	current_node -> next = new_node;

	return head;
}

void print_doubly_linked_list (NODE *head){
	NODE *aux = head;

	while (aux -> next != NULL){
		printf("%d ", aux -> item);
		aux = aux -> next;
	}

	printf("%d\n", aux -> item);

	return;
}

int main() {
	int element;
	scanf("%d", &element);

	get_elements(){
		
	}
 
	// NODE *head = creating_node(element);
	// print_doubly_linked_list(head);

	return 0;
}