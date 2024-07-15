#include "Header.h"

BinaryTree *getNode(int data) {
	BinaryTree *newNode = new BinaryTree;
	if (!newNode)
		return NULL;
	newNode->data = data;
	newNode->right = newNode->left = NULL;
	return newNode;
}

BinaryTree* CreateTree(int n) {
	if (n == 0)
		return NULL;
	int data, nl, nr;
	BinaryTree *newNode;
	cin >> data;
	newNode = getNode(data);
	nl = n / 2;
	nr = n - nl - 1;
	newNode->left = CreateTree(nl);
	newNode->right = CreateTree(nr);
	return newNode;
}
void PreOrder(BinaryTree *root) {
	if (root) {
		cout << root->data << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void PreOrderNonRecusive(BinaryTree *root) {
	Stack *top = CreateStack();
	while(1) {
		while(root) {
			cout << root->data << " ";
			Push(top, root);
			root = root->left;
		} // in tất cả nut đang duyệt và nhanh trai

		// kiểm tra trước khi pop và xử lí nhánh phải.
		if(IsEmptyStack(top))
			return;
		root = Pop(top);

		root = root->right;
	}
	DeleteStack(top);
}

void InOrder(BinaryTree *root) {
	if (root) {
		InOrder(root->left);
		cout << root->data << " ";
		InOrder(root->right);
	}
}

void InOrderNonRecusive(BinaryTree *root) {
	Stack *top = CreateStack();
	while(1) {
		while(root != NULL) {
			Push(top, root);
			root = root->left;
		} // in tất cả nut đang duyệt và nhanh trai

		// kiểm tra trước khi pop và xử lí nhánh phải.
		if(IsEmptyStack(top)) {
			return;
		}
		root = Pop(top);
		cout << root->data << " ";
		root = root->right;
	}
	DeleteStack(top);
}

void PostOrder(BinaryTree *root) {
	if (root) {
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->data << " ";
	}
}

void PostOrderNonRecusive(BinaryTree *root) {
	Stack *top = CreateStack();
	BinaryTree *pre = NULL; // temp dung nghi nho node vua duoc xu li.
	do {
		while(root) { // push tat ca left cho toi khi null
			Push(top, root);
			root = root->left;
		}

		while(root == NULL && !IsEmptyStack(top)) {
			root = Top(top);
			if(root->right == NULL || root->right == pre) {
				root = Pop(top);
				cout << root->data << " "; 
				pre = root;
				root = NULL;
			} else {
				root = root->right;
			}
		}
	} while(!IsEmptyStack(top));
	DeleteStack(top);
}


void RemoveTree(BinaryTree *&root) {
	if (root) {
		RemoveTree(root->left);
		RemoveTree(root->right);
		delete root; // xóa sau khi trái phải node đó là null
	}
}
int main()
{
	BinaryTree *root = CreateTree(5);

	PostOrder(root); cout << endl;
	PostOrderNonRecusive(root);

	RemoveTree(root);
	return 0;
}