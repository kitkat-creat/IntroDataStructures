
#include "avltree.h"
#include<iostream>

using namespace std; 

int avlTree::height(avl_node* temp)
{
	int h = 0;
	if (temp != NULL)
	{
		int l_height = height(temp->left);
		int r_height = height(temp->right);
		int max_height = max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

int avlTree::diff(avl_node* temp)
{
	int l_height = height(temp->left);
	int r_height = height(temp->right);
	int b_factor = l_height - r_height;
	return b_factor;
}


avl_node* avlTree::rotateRight(avl_node* parent)
{
	avl_node* temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}

avl_node* avlTree::rotateLeft(avl_node* parent)
{
	avl_node* temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}


avl_node* avlTree::lr_rotation(avl_node* parent)
{
	avl_node* temp;
	temp = parent->left;
	parent->left = rotateRight(temp);
	return rotateLeft(parent);
}


avl_node* avlTree::rl_rotation(avl_node* parent)
{
	avl_node* temp;
	temp = parent->right;
	parent->right = rotateLeft(temp);
	return rotateRight(parent);
}


avl_node* avlTree::balance(avl_node* temp)
{
	int bal_factor = diff(temp);
	if (bal_factor > 1)
	{
		if (diff(temp->left) > 0)
			temp = rotateLeft(temp);
		else
			temp = lr_rotation(temp);
	}
	else if (bal_factor < -1)
	{
		if (diff(temp->right) > 0)
			temp = rl_rotation(temp);
		else
			temp = rotateRight(temp);
	}
	return temp;
}


avl_node* avlTree::insert(avl_node* root, int value)
{
	if (root == NULL)
	{
		root = new avl_node;
		root->data = value;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else if (value < root->data)
	{
		root->left = insert(root->left, value);
		root = balance(root);
	}
	else if (value >= root->data)
	{
		root->right = insert(root->right, value);
		root = balance(root);
	}
	return root;
}


void avlTree::display(avl_node* ptr, int level)
{
	int i;
	if (ptr != NULL)
	{
		display(ptr->right, level + 1);
		printf("\n");
		if (ptr == root)
			cout << "Root -> ";
		for (i = 0; i < level && ptr != root; i++)
			cout << " ";
		cout << ptr->data;
		display(ptr->left, level + 1);
	}
}

void avlTree::inorder(avl_node* tree)
{
	if (tree == NULL)
		return;
	inorder(tree->left);
	cout << tree->data << " ";
	inorder(tree->right);
}

void avlTree::preorder(avl_node* tree)
{
	if (tree == NULL)
		return;
	cout << tree->data << " ";
	preorder(tree->left);
	preorder(tree->right);

}


void avlTree::postorder(avl_node* tree)
{
	if (tree == NULL)
		return;
	postorder(tree->left);
	postorder(tree->right);
	cout << tree->data << " ";
}
