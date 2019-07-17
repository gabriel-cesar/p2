#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct binary_tree{
	int item;
	struct binary_tree *left;
	struct binary_tree *right;
}binary_tree;

void print_in_order(binary_tree *bt){
	if (bt != NULL) {
		print_in_order(bt->left);
		printf("%d\n", bt->item);
		print_in_order(bt->right);
	}
}

void print_pre_order(binary_tree *bt){
	if (bt != NULL) {
		printf("%d\n", bt->item);
		print_pre_order(bt->left);
		print_pre_order(bt->right);
	}
}

void print_post_order(binary_tree *bt){
	if (bt != NULL) {
		print_post_order(bt->left);
		print_post_order(bt->right);
		printf("%d\n", bt->item);
	}
}

binary_tree *create_empty_binary_tree(){
	return NULL;
}

binary_tree *create_binary_tree(int item, binary_tree *left, binary_tree *right){
	binary_tree *new_binary_tree = (binary_tree*) malloc(sizeof(binary_tree));

	new_binary_tree->item = item;
	new_binary_tree->left = left;
	new_binary_tree->right = right;

	return new_binary_tree;
}

binary_tree* add(binary_tree *bt, int item){
	if (bt == NULL) {
		bt = create_binary_tree(item, NULL, NULL);
	} else {
		if (bt->item > item) {
			bt->left = add(bt->left, item);
		} else {
			bt->right = add(bt->right, item);
		}
	}

	return bt;
	
}

int search_2(binary_tree *bt, int key){
	if(tree == NULL){
		return 0;
	} else {
		if(bt->item == key){
			return 1;
		} else if(bt->item < key){
			search_2(bt->right, key);
		} else {
			search_2(bt->left, key);
		}
	}
}

binary_tree* search(binary_tree *bt, int item){
	if ((bt == NULL) || (bt->item == item)) {
		return bt;
	} else { 
		if (bt->item > item) {
			return search(bt->left, item);
		} else {
			return search(bt->right, item);
		}
	}
}

binary_tree *makeBT(char string[], int *position) {
	BinaryTree *bt = NULL;
	
	int numT;
	int i = 0;

	while(string[*position] == ' ' || string[*position] == '(') {
		*position += 1;
	}

	if(string[*position] != ')') {
		char num[10];
		for(i=0;string[*position] != '(';i++) {
			num[i] = string[*position];
			*position += 1;
		}
		num[i] = '\0';
		numT = atoi(num);

		bt = createBT(numT, NULL, NULL);
		bt->left = makeBT(string, position);
		bt->right = makeBT(string, position);
	} else {
		*position += 1;
		return NULL;
	}

	*position += 1;

	return bt;
}

int main(){
	// binary_tree *bt = create_binary_tree(6,	
	// 					create_binary_tree(4, NULL, NULL), 
	// 						create_binary_tree(9, 
	// 							create_binary_tree(1, NULL, NULL), 
	// 								create_binary_tree(2, NULL, NULL)));

	binary_tree *bt;
	bt = add(bt, 6);
	bt = add(bt, 4);
	bt = add(bt, 9);
	bt = add(bt, 1);
	bt = add(bt, 2);

	// binary_tree *e = search(bt, 6);
	// printf("%d\n", e->item);

	// print_pre_order(bt);
	// printf("---------\n");
	// print_in_order(bt);
	// printf("---------\n");
	// print_post_order(bt);

	return 0;
}