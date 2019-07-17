#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}NODE;

typedef struct hash{
	NODE **table;
	int size, numberOfElements;
}HASH;

void print(HASH *hash){
	int i;
	for(i = 0; i < hash->size; i++){
		NODE *current = hash->table[i];
		printf("Posicao %d: \n", i);
		while(current != NULL){
			printf("%d -> ", current->data);
			current = current->next;
		}
		printf("\\\n");
	}
}

HASH *create_hash(int size){
	HASH *new_hash = (HASH*)malloc(sizeof(HASH));
	new_hash->table = (NODE**)malloc(sizeof(NODE*) * size);
	new_hash->size = size;
	new_hash->numberOfElements = 0;
	int i;
	for(i = 0; i < size; i++){
		new_hash->table[i] = NULL;
	}
	return new_hash;
}

NODE *create_node(int new_data){
	NODE *new_node = (NODE*)malloc(sizeof(NODE));
	new_node->next = NULL;
	new_node->data = new_data;
	return new_node;
}

void put(HASH *hash, int new_data){
	int key = new_data % hash->size;
	NODE *new_node = create_node(new_data);
	new_node->next = hash->table[key];
	hash->table[key] = new_node;
}

int main(){
	HASH *hash = create_hash(5);

	put(hash, 13);
	put(hash, 10);
	put(hash, 11);
	put(hash, 4);
	put(hash, 12);
	put(hash, 1);

	print(hash);

	// printf("%d %d\n", hash->size, hash->numberOfElements);

	return 0;
}