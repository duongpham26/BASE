#include <iostream>
using namespace std;

struct ListNode {
	int data;
	ListNode *next;
};

typedef ListNode Stack;

Stack *CreateStack() {
	return NULL;
}

void Push(Stack *&top, int data) {
	Stack *temp = new Stack;
	if (!temp) return;
	temp->data = data;
	temp->next = top;
	top = temp;
}

int IsEmptyStack(Stack *top) {
	return top == NULL;
}

int Pop(Stack *&top) {
	int data;
	Stack *temp;
	if (IsEmptyStack(top)) return INT_MIN;
	temp = top;
	data = temp->data;
	top = top->next;
	delete temp;
	return data;
}

int Top(Stack *top) {
	if (IsEmptyStack(top)) return INT_MIN;
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

// int main() {
// 	Stack *top = CreateStack();
// 	Push(top, 1);
// 	Push(top, 2);
// 	Push(top, 4);
// 	Push(top, 3);
// 	Push(top, 5);

// 	while (top) {
// 		cout << Pop(top) << endl;
// 	}

// 	DeleteStack(top);
// 	return 0;
// }