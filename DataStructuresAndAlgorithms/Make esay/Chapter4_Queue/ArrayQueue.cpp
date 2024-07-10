#include <iostream>
using namespace std;

struct ArrayQueue {
	int front, rear;
	int capacity;
	int *array;
};

ArrayQueue *Queue(int size) {
	ArrayQueue *Q = new ArrayQueue;
	if (!Q) return NULL;
	Q->capacity = size;
	Q->front = Q->rear = -1;
	Q->array = new int[size];
	if (!(Q->array)) return NULL;
	return Q;
}

int IsEmptyQueue(ArrayQueue Q) {
	return Q.front == -1;
}

int IsFullQueue(ArrayQueue Q) {
	return ((Q.rear + 1) % (Q.capacity)) == Q.front;
}

int QueueSize(ArrayQueue Q) {
	if (Q.rear > Q.front) return (Q.rear - Q.front + 1);
	else return (Q.capacity - (Q.rear - Q.front + 1));
}

void EnQueue(ArrayQueue &Q, int data) {
	if (IsFullQueue(Q)) {
		cout << "Queue Overflow" << endl;
		return;
	}
	Q.rear = (Q.rear + 1) % Q.capacity;
	Q.array[Q.rear] = data;
	if (Q.front == -1) Q.front = Q.rear;
}

int DeQueue(ArrayQueue &Q) {
	if (IsEmptyQueue(Q)) {
		cout << "Queue Underflow." << endl;
		return NULL;
	}
	int data = Q.array[Q.front];
	if (Q.front == Q.rear) 
		Q.front = Q.rear = -1;
	else 
		Q.front = (Q.front + 1) % Q.capacity;
	return data;
}

void DeleteQueue(ArrayQueue *Q) {
	if (Q) {
		if (Q->array) {
			delete Q->array;
		}
		delete Q;
	}
}

int main() {
	ArrayQueue *Q = Queue(10);
	EnQueue(*Q, 1);
	EnQueue(*Q, 2);
	EnQueue(*Q, 3);
	EnQueue(*Q, 4);

	EnQueue(*Q, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << "dequeue: " << DeQueue(*Q) << endl;
	}
	DeleteQueue(Q);
	return 0;
}