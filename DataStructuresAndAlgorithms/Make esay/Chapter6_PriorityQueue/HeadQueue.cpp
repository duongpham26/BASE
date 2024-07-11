#include <iostream>
using namespace std;

struct Head {
	int *array;
	int capacity;
	int count;
	int headType; // 0 min head, 1 max head
};

Head *CreateHead(int headType, int capacity) {
	Head *h = new Head;
	if (!h) {
		cout << "Memory Error." << endl;
		return NULL;
	}
	h->headType = headType;
	h->capacity = capacity;
	h->count = 0;
	h->array = new int[capacity];
	if (!(h->array)) {
		cout << "Memory Error." << endl;
		return NULL;
	}
	return h;
}

// parent of a node
int Parent(Head *h, int i) {
	if (i <= 0 || i >= h->count)
		return -1;
	return (i - 1) / 2;
}

// children of a node
int LeftChild(Head *h, int i) {
	int left = 2 * i + 1;
	if (left >= h->count)
		return -1;
	return left;
}

int RightChild(Head *h, int i) {
	int right = 2 * i + 2;
	if (right >= h->count)
		return -1;
	return right;
}

// get maximun
int GetMaximun(Head *h) {
	if (h->count == 0)
		return 1;
	return h->array[0];
}

void Swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void PercolateDown(Head *h, int i) {
	int r, l, max;
	r = RightChild(h, i);
	l = LeftChild(h, i);
	if ((l != -1) && h->array[l] > h->array[i]) {
		max = l;
	}
	else {
		max = i;
	}

	if ((r != -1) && h->array[r] > h->array[max]) {
		max = r;
	}

	if (max != i) {
		Swap(h->array[i], h->array[max]);
		PercolateDown(h, max);
	}
}

//resize head
void ResizeHead(Head *h) {
	int *oldArray = h->array;
	h->array = new int[h->capacity * 2];
	if (h->array == NULL) {
		cout << "Error Memory." << endl;
		return;
	}
	for (int i = 0; i < h->capacity; i++) {
		h->array[i] = oldArray[i];
	}
	h->capacity = 2 * h->capacity;
	delete oldArray;
}

// insert data into head
void Insert(Head *h, int data) {
	if (h->count == h->capacity) {
		ResizeHead(h);
	}
	(h->count)++;
	int i = h->count - 1;
	while (i > 0 && data > h->array[(i - 1) / 2]) {
		h->array[i] = h->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	h->array[i] = data;
}

int DeleteMax(Head *h) {
	int data;
	if (h->count == 0)
		return -1;
	data = h->array[0];
	h->array[0] = h->array[h->count - 1];
	h->count--;
	PercolateDown(h, 0);
	return data;
}

//destroy head
void DestroyHead(Head *h) {
	if (h == NULL) 
		return;
	delete h->array;
	delete h;

	h = NULL;
}

void BuildHead(Head *h, int a[], int n) {
	if (h == NULL)
		return;
	while (n > h->capacity)
		ResizeHead(h);
	for (int i = 0; i < n; i++) {
		h->array[i] = a[i];
	}
	h->count = n;
	for (int i = (n - 2) / 2; i >= 0; i--) {
		PercolateDown(h, i);
	}
}

void HeadSort(Head *&h, int a[], int n) {
	h = CreateHead(1, n); 
	int oldSize = h->count;
	BuildHead(h, a, n);
	for (int i = n - 1; i > 0; i--) {
		Swap(h->array[0], h->array[i]);
		h->count--;
		PercolateDown(h, 0);
	}
	h->count = oldSize;
}


int main() {
	Head *h = CreateHead(1, 7);

	Insert(h, 1);
	Insert(h, 9);
	Insert(h, 7);
	Insert(h, 2);
	Insert(h, 1);
	Insert(h, 0);
	
	cout << DeleteMax(h) << endl;
	cout << DeleteMax(h) << endl;
	cout << DeleteMax(h) << endl;
	cout << DeleteMax(h) << endl;
	cout << DeleteMax(h) << endl;
	cout << DeleteMax(h) << endl;

	
	DestroyHead(h);
	return 0;
}