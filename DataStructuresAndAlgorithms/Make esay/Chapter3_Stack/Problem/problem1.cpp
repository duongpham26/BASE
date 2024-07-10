#include <iostream>
#include <string>
using namespace std;


//======================================================
struct ListNode {
	char data;
	ListNode *next;
};

typedef ListNode Stack;

Stack *CreateStack() {
	return NULL;
}

void Push(Stack *&top, char data) {
	Stack *temp = new Stack;
	if (!temp) return;
	temp->data = data;
	temp->next = top;
	top = temp;
}

char IsEmptyStack(Stack *top) {
	return top == NULL;
}

char Pop(Stack *&top) {
	char data;
	Stack *temp;
	if (IsEmptyStack(top)) return NULL;
	temp = top;
	data = temp->data;
	top = top->next;
	delete temp;
	return data;
}

char Top(Stack *top) {
	if (IsEmptyStack(top)) return NULL;
	return top->data;
}

void DeleteStack(Stack *&top) {
	Stack *temp = top;
	while (top != NULL) {
		top = top->next;
		delete temp;
		temp = top;
	}
}
// =========================================================

int isMatchingPair(char a, char b) {
	if (a == '[' && b == ']') return 1;
	if (a == '{' && b == '}') return 1;
	if (a == '(' && b == ')') return 1;
	return 0;
}

int PushElementIntoStack(Stack *&top, string element) {
	for (int i = 0; i < element.length(); i++) {
		char x = element[i];
		if (x == '[' || x == '{' || x == '(') {
			Push(top, element[i]);
		}
		else if (x == ']' || x == '}' || x == ')') {
			if (IsEmptyStack(top)) return 0;
			char ch = Pop(top);
			if (!isMatchingPair(ch, x)) return 0;
		}
	}
	return IsEmptyStack(top);
}

int main() {
	Stack *top = CreateStack();
	string str = "{{}}[(a+b)*c";
	cout << PushElementIntoStack(top, str) << endl;
	DeleteStack(top);
	return 0;
}