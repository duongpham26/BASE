#include <iostream>
using namespace std;

struct Node {
	char data;
	Node* next;
};

struct Queue {
	Node* front;
	Node* rear;
};

void Init(Queue &q)
{
	q.front = q.rear = NULL;
}


bool isEmpty(const Queue& queue) {
	return queue.front == nullptr;
}

void enqueue(Queue& q, char value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = NULL;

	if (q.front == NULL)
	{
		q.front = newNode;
		q.rear = q.front;
	}
	else
	{
		q.rear->next = newNode;
		q.rear = newNode;
	}
}

char dequeue(Queue& queue) {
	if (queue.front == nullptr) {
		cout << "Queue underflow" << endl;
		return '\0'; // Return null character if queue is empty
	}
	Node* temp = queue.front;
	queue.front = queue.front->next;

	if (queue.front == nullptr) {
		queue.rear = nullptr;
	}

	char dequeuedValue = temp->data;
	delete temp;
	return dequeuedValue;
}


bool isPalindrome(const string& str) {
	Queue queue1;
	Init(queue1);
	Queue queue2;
	Init(queue2);

	for (char ch : str) {
		enqueue(queue1, ch);
	}

	// Enqueue all characters into queue2 in reverse order
	for (int i = str.size() - 1; i >= 0; --i) {
		enqueue(queue2, str[i]);
	}

	// Compare characters from both queues
	while (!isEmpty(queue1)) {
		if (dequeue(queue1) != dequeue(queue2)) {
			return false;
		}
	}

	return true;
}

int main() {
	// Test queue implementation
	Queue queue;
	Init(queue);
	enqueue(queue, 'a');
	enqueue(queue, 'b');
	enqueue(queue, 'c');

	cout << "Queue elements:" << endl;
	while (!isEmpty(queue)) {
		cout << dequeue(queue) << " "; // Output: a b c
	}
	cout << endl;

	// Test palindrome checker
	string str1 = "radar";
	string str2 = "hello";
	string str3 = "level";

	cout << " is a palindrome: str1 " << (isPalindrome(str1) ? "Yes" : "No") << endl; // Output: Yes
	cout << " is a palindrome: str2 " << (isPalindrome(str2) ? "Yes" : "No") << endl; // Output: No
	cout << " is a palindrome: str3 " << (isPalindrome(str3) ? "Yes" : "No") << endl; // Output: Yes

	return 0;
}



