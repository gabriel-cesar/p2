#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//struct padrao
typedef struct NODE{
	int item;
	struct NODE *next;
}NODE;

NODE *creating_node(int e){
	NODE *new_node = (NODE*) malloc(sizeof(NODE)); //armazene um espaço pra o tipo NODE (desse tamanho) //(NODE*) cash dizendo q vai retornar tipo NODE
	new_node -> item = e; //entrando na struct new node e acessanto o item q eh um inteiro (criando a cabeça)
	new_node -> next = NULL;

	return new_node;
}

NODE *add_begining(int e, NODE *head){
	NODE *new_node = creating_node(e);
	new_node -> next = head; //aponta p cabeça

	return new_node;
}

void *add_end (int e, NODE *head){
	NODE *new_node = creating_node(e);
	NODE *aux = head;

	while (aux -> next != NULL) {
		aux = aux -> next;
	}

	aux -> next = new_node;
}

void print_linked_list(NODE *head){
	NODE *aux = head;

	while(aux -> next != NULL){
		printf("%d -> ", aux -> item);

		aux = aux -> next;
	}

	printf("%d\n", aux -> item);

	return;
}

void get_list(NODE *(*f)(int e, NODE *head), int n){
	int e, i;
	scanf("%d", &e);

	NODE *head = creating_node(e);

	for(i = 0; i < n - 1; i++){
		scanf("%d", &e);

		head = (*f)(e, head);
	}

	print_linked_list(head);
	return;
}

int main(){
	int n; scanf("%d", &n);

	get_list(add_begining, n);
	get_list(add_end, n);

	// int n; //tamanho da lista
	// int e; //primeiro elemento da lista

	// scanf("%d%d", &n, &e);

	// NODE *head = creating_node(e);

	// int i;
	// for(i = 0; i < n - 1; i++){ //recebendo outros elementos da lista
	// 	scanf("%d", &e);
		
	// 	// head = add_begining(e, head); //adiciona no começo e eh do tipo NODE
	// 	add_end(e, head); //adiciona no final e função VOID
	// }
	
	// print_linked_list(head);
	
	return 0;
}