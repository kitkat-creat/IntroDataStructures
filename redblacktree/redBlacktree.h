#pragma once
#include <iostream>

using namespace std;


static struct Node
{
	int data;
	Node* parent;
	Node* left;
	Node* right;
	int color;
};

class redBlacktree
{
private:
	Node* root;
	Node* TNULL;

	
public:
	redBlacktree() {
		TNULL = new Node;
		TNULL->color = 0;
		TNULL->left = nullptr;
		TNULL->right = nullptr;
		root = TNULL;
	}


	Node*minimum(Node*node) {
		while (node->left != TNULL) {
			node = node->left;
		}
		return node;
	}

	Node* maximum(Node* node) {
		while (node->right != TNULL) {
			node = node->right;
		}
		return node;
	}

	Node* successor(Node* x) {
		if (x->right != TNULL) {
			return minimum(x->right);
		}

		Node* y = x->parent;
		while (y != TNULL && x == y->right) {
			x = y;
			y = y->parent;
		}
		return y;
	}

	Node* predecessor(Node* x) {
		if (x->left != TNULL) {
			return maximum(x->left);
		}

		Node* y = x->parent;
		while (y != TNULL && x == y->left) {
			x = y;
			y = y->parent;
		}

		return y;
	}
	Node* getRoot() {
		return this->root;
	}
	void insertFix(Node* k);
	void printHelper(Node* root, string indent, bool last);
	void leftRotate(Node* x);
	void rightRotate(Node* x);
	void insert(int key);
	void printTree();
};

