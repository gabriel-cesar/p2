#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

typedef struct node{
    int item;
    struct node *next;
    struct node *prev;
} node_t;

typedef struct hash{
	int size;
    node_t **table;
} ht;

int is_empty(node_t *head){
	return head == NULL;
}

void printList(node_t *head){
	node_t *current = head;
	while(current != NULL){
		printf("%d ", current->item);
		current = current->next;
	}
	printf("\n");
	return;
}

void printHash(ht *hash){
	int i, a = 0;
	for(i=0;i<hash->size;i++){
		if(!is_empty(hash->table[i])){
			printList(hash->table[i]);
		}
	}
	return;
}

ht *create_hash(int size){
	int i;

	ht *new_hash = (ht*)malloc(sizeof(ht));
	new_hash->table = (node_t **)malloc(size * (sizeof(node_t*)));
	new_hash->size = size;
	
	for(i=0;i<size;i++) {
		new_hash->table[i] = NULL;
	}
	
	return new_hash;
}

node_t *remove_list (node_t *head){
    node_t *current = head;
    while(head != NULL) {
        current = head->next;
        free(head);
        head = current;
    }
}

ht *free_hash(ht *hash){
	int i;
	for(i=0;i<hash->size;i++){
		if(!is_empty(hash->table[i])){
			remove_list(hash->table[i]);
			hash->table[i] = NULL;
		}
	}
}

node_t *create_node(int new_item){
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->item = new_item;
    return new_node;
}

node_t *insert_end(node_t *head, int new_item){
	int a = 0;
	node_t *current = head;
	node_t *new_node = create_node(new_item);
	if(head == NULL){
		return new_node;
	}
	while(current->next != NULL){
		current = current->next;
	}
	current->next = new_node;
	new_node->prev = current;
	return head;
}

node_t *insert_beggining(node_t *head, int new_item){
	node_t *new_node = create_node(new_item);
	new_node->next = head;
	head->prev = new_node;
	head = new_node;
	return head;
}

int finding_key(int key, int size){
	return key % size;
}

ht *insert_hash(ht *hash, int new_item){
	int key = finding_key(new_item, hash->size);
	hash->table[key] = insert_end(hash->table[key],new_item);
	
	return hash;
}

ht *remove_from_hash(ht *hash, int item){
	int key = finding_key(item,hash->size);
	if(hash->table[key] == NULL){
		printf("No element found\n");
	} else {
		node_t *current = hash->table[key];
		while(current != NULL && current->item != item){
			current = current->next;
		}
		if(current->next == NULL && current->prev == NULL){
			hash->table[key] = NULL;
		} else if(current->next == NULL){
			current->prev->next = NULL;
		} else if(current->prev == NULL){
			hash->table[key] = current->next;
		} else{
			current->prev->next = current->next;
			current->next->prev = current->prev;
		}
		free(current);
	}

	return hash;
}

int main(){
	int a = 0;
	node_t *head = NULL;
	
	ht *hash = create_hash(10);
	
	hash = insert_hash(hash,1);
	hash = insert_hash(hash,12);
	// printf("%d\n", hash->table[1]->item);
	hash = insert_hash(hash,3);
	hash = insert_hash(hash,5);
	hash = insert_hash(hash,11);
	hash = insert_hash(hash,21);
	
	// hash = remove_from_hash(hash,1);
	// free_hash(hash);
	
	hash = insert_hash(hash,10);
	printHash(hash);
	
	return 0;
}