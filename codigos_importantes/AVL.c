#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct binary_tree {
	int item;
	int h;
	struct binary_tree* left;
	struct binary_tree* right;
}binary_tree;

binary_tree *create_binary_tree(int item, binary_tree *left, binary_tree *right){
	binary_tree *new_binary_tree = (binary_tree*) malloc(sizeof(binary_tree));

	new_binary_tree->item = item;
	new_binary_tree->left = left;
	new_binary_tree->right = right;

	return new_binary_tree;
}

int max(int a, int b){
	return (a > b) ? a : b;
}

int h(binary_tree *bt){
	if (bt == NULL) {
		return -1;
	} else {
		return 1 + max(h(bt->left), h(bt->right));
	}
}

int is_balanced(binary_tree *bt){
	int bf = h(bt->left) - h(bt->right);
	return ((-1 <= bf) && (bf <= 1));
}

int balance_factor(binary_tree *bt){
	if (bt == NULL) {
		return 0;
	} else if ((bt->left != NULL) && (bt->right != NULL)) {
		return (bt->left->h - bt->right->h);
	} else if ((bt->left != NULL) && (bt->right == NULL)) {
		return (1 + bt->left->h);
	} else {
		return (-bt->right->h - 1);
	}
}

void print_in_order(binary_tree *bt){
	if (bt != NULL) {
		print_in_order(bt->left);
		printf("%d\n", bt->item);
		print_in_order(bt->right);
	}
}

binary_tree* rotate_left(binary_tree *bt){
	binary_tree *subtree_root = NULL;
	
	if (bt != NULL && bt->right != NULL) {
		subtree_root = bt->right;
		bt->right = subtree_root->left;
		subtree_root->left = bt;
	}
	
	subtree_root->h = h(subtree_root);
	bt->h = h(bt);
	
	return subtree_root;
}

binary_tree* rotate_right(binary_tree *bt){
	binary_tree *subtree_root = NULL;
	
	if (bt != NULL && bt->left != NULL) {
		subtree_root = bt->left;
		bt->left = subtree_root->right;
		subtree_root->right = bt;
	}

	subtree_root->h = h(subtree_root);
	bt->h = h(bt);
	
	return subtree_root;
}

binary_tree* add(binary_tree *bt, int item){
	if (bt == NULL) {
		return create_binary_tree(item, NULL, NULL);
	} else if (bt->item > item) {
		bt->left = add(bt->left, item);
	} else {
		bt->right = add(bt->right, item);
	}
	
	bt->h = h(bt);
	binary_tree *child;

	if (balance_factor(bt) == 2 || balance_factor(bt) == -2) {
		if (balance_factor(bt) == 2) {
			child = bt->left;
			
			if (balance_factor(child) == -1) {
				bt->left = rotate_left(child);
			}
			
			bt = rotate_right(bt);
		} else if (balance_factor(bt) == -2) {
			child = bt->right;
			
			if (balance_factor(child) == 1) {
				bt->right = rotate_right(child);
			}
			
			bt = rotate_left(bt);
		}
	}
	
	return bt;
}

int main(){
	binary_tree *bt;
	bt = add(bt, 2);
	bt = add(bt, 1);
	bt = add(bt, 3);

	print_in_order(bt);

	return 0;
}