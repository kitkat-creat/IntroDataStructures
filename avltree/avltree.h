#pragma once
#ifndef AVLTREE_H
#define AVLTREE_H


#include <iostream>

using namespace std;


static struct avl_node
{
	int data;
	struct avl_node* left;
	struct avl_node* right;

}*root;

class avlTree
{

public:
	int height(avl_node* temp);
	int diff(avl_node* temp);
	avl_node* rotateRight(avl_node*);
	avl_node* rotateLeft(avl_node*);
	avl_node* lr_rotation(avl_node*);
	avl_node* rl_rotation(avl_node*);
	avl_node* balance(avl_node*);
	avl_node* insert(avl_node*, int);
	void display(avl_node*, int);
	void inorder(avl_node*);
	void preorder(avl_node*);
	void postorder(avl_node*);
	avlTree()
	{
		root = NULL;
	}
};

#endif