

#include <iostream>
using namespace std;
#define MAXSIZE 5

struct ArrayStack {
	int top;
	int capacity;
	int *array;
};

ArrayStack *CreateStack(){
	ArrayStack *S = new ArrayStack;
	if (!S) return NULL;
	S->capacity = MAXSIZE;
	S->top = -1;
	S->array = new int[10];
	if (!S->array) return NULL;
	return S;
}

int isEmptyStack(ArrayStack &S) {
	return (S.top == -1);
}

int isFullStack(ArrayStack &S) {
	return (S.top == S.capacity - 1);
}

void Push(ArrayStack &S, int data) {
	if (isFullStack(S)) 
		cout << "Stack Overflow" << endl;
	else
		S.array[++S.top] = data;
}

int Pop(ArrayStack &S) {
	if (isEmptyStack(S)) {
		cout << "Stack Underflow" << endl;
		return INT_MIN;
	}
	else
		return S.array[S.top--];
}
void DeleteStack(ArrayStack *S) {
	if (S) {
		if (S->array)
			delete S->array;
		delete S;
	}
}

int main() {
	ArrayStack *S = CreateStack();
	Push(*S, 1);
	Push(*S, 2);
	Push(*S, 3);
	Push(*S, 4);
	Push(*S, 5);
	Push(*S, 6);
	d
	for (int i = 0; i < 6; i++) {
		cout << Pop(*S) << endl;
	}

	DeleteStack(S);
	return 0;
}
