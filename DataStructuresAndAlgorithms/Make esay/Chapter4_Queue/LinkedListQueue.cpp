#include <iostream> 
using namespace std;

struct ListNode {
	int data;
	ListNode *next;
};

struct Queue {
	ListNode *front;
	ListNode *rear;
};

Queue &CreateQueu() {
	Queue Q;
	Q.front = Q.rear = NULL;
	return Q;
}

int IsEmptyQueue(Queue Q) {
	return Q.front == NULL;
}

void EnQueue(Queue &Q, int data) {
	ListNode *newNode = new ListNode;
	if (!newNode) {
		cout << "Error Memory!" << endl;
		return;
	}
	newNode->data = data;
	newNode->next = NULL;
	if (Q.rear) Q.rear->next = newNode;
	Q.rear = newNode;
	if (Q.front == NULL) Q.front = Q.rear = newNode;
}

int DeQueue(Queue &Q) {
	if (IsEmptyQueue(Q)) {
		cout << "Queue is empty." << endl;
		return NULL;
	}
	ListNode *temp;
	int data;
	temp = Q.front;
	data = Q.front->data;
	Q.front = temp->next;
	delete temp;
	return data;
}

void DeleteQueue(Queue &Q) {
	ListNode *temp;
	while (Q.front != NULL) {
		temp = Q.front;
		Q.front = Q.front->next;
		delete temp;
	}
	Q.front = Q.rear = NULL;
}

int main() {
	Queue Q = CreateQueu();
	EnQueue(Q, 1);
	EnQueue(Q, 2);
	EnQueue(Q, 3);
	EnQueue(Q, 5);
	EnQueue(Q, 4);

	while (Q.front)
	{
		cout << DeQueue(Q) << endl;
	}

	DeleteQueue(Q);
	return 0;
}