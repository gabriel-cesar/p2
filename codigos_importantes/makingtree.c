#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct binary_tree{
	int item;
	struct binary_tree *left;
	struct binary_tree *right;
}binary_tree;

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

binary_tree* search(binary_tree *bt, int item){
	if ((bt == NULL) || (bt->item == item)) {
		return bt;
	} else if (bt->item > item) {
		return search(bt->left, item);
	} else {
		return search(bt->right, item);
	}
}

binary_tree* add(binary_tree *bt, int item){
	if (bt == NULL) {
		bt = create_binary_tree(item, NULL, NULL);
	} else if (bt->item > item) {
		bt->left = add(bt->left, item);
	} else {
		bt->right = add(bt->right, item);
	}

	return bt;
}

NODE *makingTREE(char input[], int *index){
    if(input[*index] == ')'){
        (*index)++;
        return NULL;
    }

    int value = 0;
    while(input[*index] >= '0' && input[*index] <= '9'){
        value *= 10;
        value += (input[(*index)++] - '0');
    }
    
    NODE *new_node = creating_node(value);
    (*index)++;
    
    new_node -> left = makingTREE(input, index);
    (*index)++;
    
    new_node -> right = makingTREE(input, index);
    (*index)++;
    
    while(input[(*index)] == ' ')(*index)++; // joga espaço fora
    
    return new_node;
}


int main(){
	binary_tree *bt;


	return 0;
}