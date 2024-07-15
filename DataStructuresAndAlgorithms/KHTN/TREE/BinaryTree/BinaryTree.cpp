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
	if (root)
		Push(top, root);
	while (!IsEmptyStack(top))
	{
		root = Pop(top);
		cout << root->data << " ";
		if (root->right) Push(top, root->right);
		if (root->left) Push(top, root->left);
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
	while (root || !IsEmptyStack(top)) { // dừng khi stack rỗng và root = NULL
		if (root) { // nếu root left khác null thì push
			Push(top, root);
			root = root->left;
		}
		else { // null thì in node đó ra và xử lí node phải 
			root = Pop(top);
			cout << root->data << " "; // xu li
			root = root->right;
		}
	}
	DeleteStack(top);
}

void PostOrder(BinaryTree *root) {
	if (root) {
		InOrder(root->left);
		InOrder(root->right);
		cout << root->data << " ";
	}
}

void PostOrderNonRecusive(BinaryTree *root) {
	Stack *top = CreateStack();
	BinaryTree *temp = root; // temp dung nghi nho node vua duoc xu li.
	while (root) {

		// push nhánh trái tới khi nào node->left bằng null thì dừng.
		while (root->left) {
			Push(top, root);
			root = root->left;
		}

		// nếu nếu không có right hoặc right xử lí rồi thì in ra.
		while (root->right == NULL || root->right == temp) {
			cout << root->data << " ";
			temp = root; // lưu node vừa xử lí.
			if (IsEmptyStack(top)) 
				return;
			root = Pop(top);
		}

		// xư lí nhánh phải khi chưa được xử lí 
		Push(top, root);
		root = root->right;
	}
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