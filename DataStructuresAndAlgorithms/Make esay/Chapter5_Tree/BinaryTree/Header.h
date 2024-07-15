#include <iostream>
using namespace std;

struct BinaryTree
{
	int data;
	BinaryTree *left;
	BinaryTree *right;
};

struct ListNode {
	BinaryTree *data;
	ListNode *next;
};

typedef ListNode Stack;

Stack *CreateStack() {
	return NULL;
}

void Push(Stack *&top, BinaryTree *data) {
	Stack *temp = new Stack;
	if (!temp) return;
	temp->data = data;
	temp->next = top;
	top = temp;
}

int IsEmptyStack(Stack *top) {
	return top == NULL;
}

BinaryTree* Pop(Stack *&top) {
	BinaryTree *data;
	Stack *temp;
	if (IsEmptyStack(top)) return NULL;
	temp = top;
	data = temp->data;
	top = top->next;
	delete temp;
	return data;
}

BinaryTree* Top(Stack *top) {
	if (IsEmptyStack(top)) return NULL;
	return top->data;
}

void DeleteStack(Stack *&top) {
	Stack *temp = top;
	int count = 0;
	while (top != NULL) {
		top = top->next;
		delete temp;
		temp = top;
	}
}
