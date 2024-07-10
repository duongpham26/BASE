#include <iostream>
using namespace std;

struct Node {
	char data;
	Node* next;
};

struct Stack {
	Node* top;
};

void Init(Stack &stack)
{
	stack.top = NULL;
}


bool isEmpty(const Stack& stack) {
	return stack.top == nullptr;
}

void push(Stack& stack, char value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = stack.top;
	stack.top = newNode;
}

char pop(Stack& stack) {
	if (stack.top == nullptr) {
		cout << "Stack underflow" << endl;
		return '\0'; // Return null character if stack is empty
	}
	Node* temp = stack.top;
	stack.top = stack.top->next;
	char poppedValue = temp->data;
	delete temp;
	return poppedValue;
}

char peek(const Stack& stack) {
	if (stack.top == nullptr) {
		return '\0';
	}
	return stack.top->data;
}

bool isMatchingPair(char left, char right) {
	return (left == '(' && right == ')') ||
		(left == '{' && right == '}') ||
		(left == '[' && right == ']');
}

bool isBalanced(const string& str) {
	Stack stack;

	for (char ch : str) {
		if (ch == '(' || ch == '{' || ch == '[') {
			push(stack, ch);
		}
		else if (ch == ')' || ch == '}' || ch == ']') {
			if (isEmpty(stack)) {
				return false; // Unmatched closing bracket
			}
			char top = pop(stack);
			if (!isMatchingPair(top, ch)) {
				return false; // Mismatched pair
			}
		}
	}

	return isEmpty(stack); // True if no unmatched opening brackets left
}

int main() {
	// Test stack implementation
	Stack stack;
	push(stack, 'a');
	push(stack, 'b');
	push(stack, 'c');

	cout << "Top element is: " << peek(stack) << endl; // Output: c

	cout << "Stack elements:" << endl;
	while (!isEmpty(stack)) {
		cout << pop(stack) << " "; // Output: c b a
	}
	cout << endl;

	// Test balanced parentheses checker
	string str1 = "{[()]}";
	string str2 = "{[(])}";
	cout << " is balanced: str1 " << (isBalanced(str1) ? "Yes" : "No") << endl; // Output: Yes
	cout << " is balanced: str2 " << (isBalanced(str2) ? "Yes" : "No") << endl; // Output: No
	return 0;
}




