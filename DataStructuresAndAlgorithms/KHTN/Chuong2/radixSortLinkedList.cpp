#include <iostream>
#include <conio.h>
#include <cstdlib> // for rand() and srand()
#include <ctime>
#include <math.h>
using namespace std;

struct node
{
	int data;
	node* next;
};

struct list
{
	node *head;
	node *tail;
};

void init(list &l)
{
	l.head = l.tail = NULL;
}

node *generateNode(int data) 
{
	node *newNode = new node;
	if (newNode == NULL) 
	{
		cout << "Khong du bo nho" << endl;
		return NULL;
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}


void addLast(list &l, node *newNode) 
{
	if (newNode == NULL) {
		cout << "Node null" << endl;
	}
	else 
	{
		if (l.head == NULL) 
		{	
			l.head = l.tail = newNode;
		} 
		else 
		{
			l.tail->next = newNode;
			l.tail = newNode;
		}
	}
}

node *cutFirst(list &l) {
	if (l.head != NULL) 
	{
		node *p = l.head;
		if (l.head == l.tail) l.head = l.tail = NULL;
		else l.head = l.head->next;
		p->next = NULL;
		return p;
	}
	return NULL;
}

void remove(list &l) 
{
	if (l.head != NULL) 
	{
		node *index = l.head;
		node *temp;
		while (index != NULL) 
		{
			temp = index->next;
			delete index;
			index = temp;
		}
	}
}

void randomList(list &l, int size) 
{
	for (int i = 0; i < size; i++) 
	{
		addLast(l, generateNode(rand() % size));
	}
}

void printList(list l) 
{
	node *i = l.head;
	while (i != NULL) 
	{
		cout << i->data << " ";
		i = i->next;
	}
	cout << "\n";
}


// radix sort
int getMax(list l) 
{
	node *index = l.head->next;
	int max = l.head->data;
	while (index != NULL) 
	{
		if (index->data > max) max = index->data;
		index = index->next;
	}
	return max;
}

int digit(int a, int k) 
{
	int d;
	int i = 0;
	while (i <= k) 
	{
		d = a % 10;
		a /= 10;
		i++;
	}
	return d;
}

void sortLinkedList(list &l, int k)
{
	list L[10];
	for (int i = 0; i < 10; i++) init(L[i]);
	int d;
	while (l.head != NULL) 
	{	
		node *p = l.head;
		l.head = l.head->next;
		p->next = NULL;
		d = digit(p->data, k);
		addLast(L[d], p);
	}
	l.head = l.tail = NULL;
	int i = 0, j = 9;
	while (i < 10 && (L[i].head == NULL)) i++;
	l.head = L[i].head;
	while (j >= 0 && (L[j].tail == NULL)) j--;
	l.tail = L[j].tail;
	int temp;
	while(i < j)
	{
		temp = i + 1;
		while (temp <= j && L[temp].head == NULL) temp++;
		L[i].tail->next = L[temp].head;
		i = temp;
	}
	for (int i = 0; i < 10; i++) init(L[i]);
}

void radixSortLinkedList(list &l) 
{
	int max = getMax(l);
	int d = log10(double(max)) + 1;// so chu so
	for (int k = 0; k < d; k++) sortLinkedList(l, k);
}

int main() 
{
	clock_t start, end;
	double duration;

	const int n = 100000;
	list l;
	init(l);
	randomList(l, n);
	start = clock();
	radixSortLinkedList(l);
	end = clock();

	//printList(l);
	duration = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << "Time: " << duration;
	remove(l);
	return 0;
}