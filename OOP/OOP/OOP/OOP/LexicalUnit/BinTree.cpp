#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
#include <memory>
#include "lexicalUnit.h"


struct node {
	lexicalUnit key_value;
	struct node* left;
	struct node* right;
};

class btree {
private:
	void destroy_node(node* leaf);
	void insert(node** tree, lexicalUnit item);
	node* search(lexicalUnit key, node* leaf);
	void print(node* leaf);
	int delete_node(node** tree, lexicalUnit key);
	node* root;
public:
	btree();
	~btree();
	void insert(lexicalUnit key);
	node* search(lexicalUnit key);
	int delete_node(lexicalUnit key);
	void destroy_node();
	void print();
};
btree::btree() {
	root = 0;
}
btree::~btree() {
	//destroy tree
}

void btree::insert(node** tree, lexicalUnit item) {


	if (!(*tree))
	{
		node* n = new node;
		n->left = NULL;
		n->right = NULL;
		n->key_value = item;
		return;
	}
	if (item.getIdentificator() < (*tree)->key_value.getIdentificator())
		insert(&(*tree)->left, item);
	else
		if (item.getIdentificator() > (*tree)->key_value.getIdentificator())
		{
			insert(&(*tree)->right, item);
		}
		else {
			return;
		}
}
void btree::insert(lexicalUnit key) {
	insert(&root, key);
}
node* btree::search(lexicalUnit key, node* leaf) {
	if (leaf == NULL)
	{
		return NULL;
	}
	if (leaf->key_value.getIdentificator() == key.getIdentificator())
	{
		return leaf;
	}
	if (leaf->key_value.getIdentificator() > key.getIdentificator())
	{
		return search(key, leaf->left);
	}
	else {
		return search(key, leaf->right);
	}
}
node* btree::search(lexicalUnit key) {
	return search(key, root);
}
void btree::print(node* leaf) {
	if (leaf->left)
	{
		print(leaf->left);
	}
	printf("%s\t", leaf->key_value.getIdentificator());
	if (leaf->right)
	{
		print(leaf->right);
	}
}
void btree::print() {
	print(root);
}

int btree::delete_node(node** tree, lexicalUnit key) {
	node* temp, * buff;

	if (*tree == NULL)
	{
		return 0;
	}
	if ((*tree)->key_value.getIdentificator() == key.getIdentificator())
	{
		if ((*tree)->left == NULL)
		{
			if ((*tree)->right == NULL)
			{
				free((*tree));
				(*tree) = NULL;
				return 1;
			}
			else
			{
				temp = (*tree);
				(*tree) = (*tree)->right;
				free(temp);
				return 1;
			}
		}
		else
		{
			if ((*tree)->right == NULL)
			{
				temp = (*tree);
				(*tree) = (*tree)->left;
				free(temp);
				return 1;
			}
			else
			{
				temp = (*tree)->right;
				buff = (*tree);
				while (temp->left)
				{
					temp = temp->left;
				}
				temp->left = (*tree)->left;
				(*tree) = (*tree)->right;
				free(buff);
				return 1;
			}
		}
	
	}
	else {
		if ((*tree)->key_value.getIdentificator()>key.getIdentificator())
		{
			return delete_node(&(*tree)->left, key);
		}
		else {
			return delete_node(&(*tree)->right, key);

		}
	}

}
int btree::delete_node(lexicalUnit key) {
	return delete_node(&root, key);
}

void btree:: destroy_node(node* leaf) {

}
