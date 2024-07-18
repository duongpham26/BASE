#include "Header.h"

struct AVLTree {
	int data;
	AVLTree *right;
	AVLTree *left;
	int height;
};

int Height(AVLTree *root) {
	if (!root)
		return -1;
	else
		return root->height;
}

int max(int a, int b) {
	return a > b ? a : b;
}

AVLTree *SingleRotateLeft(AVLTree *&p1) {
	AVLTree *p2 = p1->left;
	p1->left = p2->right;
	p2->right = p1;
	p1->height = max(Height(p1->left), Height(p1->right)) + 1;
	p2->height = max(Height(p2->right), Height(p2->left)) + 1;
	return p2; // new root
}

AVLTree *SingleRotateRight(AVLTree *&p1) {
	AVLTree *p2 = p1->right;
	p1->right = p2->left;
	p2->left = p1;
	p1->height = max(Height(p1->left), Height(p1->right)) + 1;
	p2->height = max(Height(p2->right), Height(p2->left)) + 1;
	return p2; // new root
}

AVLTree *DoubleRotateLeft(AVLTree *&p3) {
	p3->left = SingleRotateRight(p3->left);
	return SingleRotateLeft(p3);
}

AVLTree *DoubleRotateRight(AVLTree *&p3) {
	p3->right = SingleRotateLeft(p3->right);
	return SingleRotateRight(p3);
}

void Insert(AVLTree *&root, int data) {
	if (!root) { // tim vi tri null chen vao
		root = new AVLTree;
		root->data = data;
		root->height = 0;
		root->left = root->right = NULL;
	}
	else { // neu khong null thi tim vi tri de chen
		if (data < root->data) {
			Insert(root->left, data);
			if (Height(root->left) - Height(root->right) == 2) {
				if (data < root->left->data)
					root = SingleRotateLeft(root);
				else
					root = DoubleRotateLeft(root);
			}
		}
		else if (data > root->data) {
			Insert(root->right, data);
			if (Height(root->right) - Height(root->left) == 2) {
				if (data > root->right->data)
					root = SingleRotateRight(root);
				else
					root = DoubleRotateRight(root);
			}
		}
	}
	root->height = max(Height(root->right), Height(root->left)) + 1;
}



void LNR(AVLTree *root) {
	if (root) {
		LNR(root->left);
		cout << root->data << " ";
		LNR(root->right);
	}
}


void RemoveTree(AVLTree *&root) {
	if (root) {
		RemoveTree(root->left);
		RemoveTree(root->right);
		delete root;
	}
}


int main()
{
	AVLTree *root = NULL;

	Insert(root, 10);
	Insert(root, 5);
	Insert(root, 19);
	Insert(root, 3);
	Insert(root, 16);
	Insert(root, 30);
	Insert(root, 28);
	Insert(root, 39);
	Insert(root, 29);
	
	LNR(root);
	RemoveTree(root);

	return 0;
}