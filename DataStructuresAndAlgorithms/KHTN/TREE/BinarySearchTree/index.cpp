#include "Header.h"

struct BinarySearchTree {
	int data;
	BinarySearchTree *right;
	BinarySearchTree *left;
};

BinarySearchTree *getNode(int data) {
	BinarySearchTree *newNode = new BinarySearchTree;
	if (!newNode)
		return NULL;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BinarySearchTree *Search(BinarySearchTree *root, int data) {
	while (root)
	{
		if (data == root->data) {
			return root;
		}
		else {
			if (data > root->data)
				root = root->right;
			else
				root = root->left;
		}
	}
	return NULL;
}

void SearchAdd(BinarySearchTree *&root, int data) {
	BinarySearchTree *newNode;
	if (root == NULL) {
		root = getNode(data);
		if (!root)
			return;
	}
	else {
		if (data < root->data)
			SearchAdd(root->left, data);
		else
		{
			if (data > root->data)
				SearchAdd(root->right, data);
			else
				return;
		}
	}
}

void SearchAddNonRecusive(BinarySearchTree *&root, int data) {
	BinarySearchTree *p, *q;
	p = q = root;
	int d;
	if (root == NULL) {
		root = getNode(data);
		if (!root) {
			cout << "Memory Error." << endl;
			return;
		}
	}
	else {
		while (p) {
			if (data == p->data) {
				return;
			}
			else {
				q = p;
				if (data < p->data) {
					p = p->left;
					d = -1;
				}
				else {
					p = p->right;
					d = 1;
				}
			}
		}
		p = getNode(data);
		if (!p) {
			cout << "Memory Error." << endl;
			return;
		}
		if (d == -1)
			q->left = p;
		else if(d == 1)
			q->right = p;
	}
}

void Delete2Child(BinarySearchTree *&root, BinarySearchTree *&temp) {
	if (root->right != NULL)
		Delete2Child(root->right, temp);
	else {
		temp->data = root->data;
		temp = root;
		root = root->left;
	}
}

void SearchDelete(BinarySearchTree *&root, int data) {
	if (root == NULL)
		return;
	BinarySearchTree *temp;
	if (data < root->data)
		SearchDelete(root->left, data);
	else if (data > root->data)
		SearchDelete(root->right, data);
	else {
		temp = root;
		if (root->left == NULL)
			root = root->right;
		else if (root->right == NULL)
			root = root->left;
		else {
			Delete2Child(root->left, temp);
		}
		delete temp;
	}
}

void LNR(BinarySearchTree *root) {
	if (root) {
		LNR(root->left);
		cout << root->data << " ";
		LNR(root->right);
	}
}

void RemoveTree(BinarySearchTree *&root) {
	if (root) {
		RemoveTree(root->left);
		RemoveTree(root->right);
		delete root;
	}
}


int main()
{
	BinarySearchTree *root = NULL;

	/*SearchAdd(root, 1);
	SearchAdd(root, 6);
	SearchAdd(root, 4);
	SearchAdd(root, 5);
	SearchAdd(root, 2);*/

	SearchAddNonRecusive(root, 1);
	SearchAddNonRecusive(root, 6);
	SearchAddNonRecusive(root, 4);
	SearchAddNonRecusive(root, 5);
	SearchAddNonRecusive(root, 2);
	SearchAddNonRecusive(root, 7);
	SearchAddNonRecusive(root, 10);
	SearchAddNonRecusive(root, 9);
	SearchAddNonRecusive(root, 8);
	SearchDelete(root, 6);

	LNR(root);

	RemoveTree(root);
	return 0;
}