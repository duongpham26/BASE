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
		return;
	}
	if (l.head == NULL)
	{
		l.head = newNode;
		l.tail = l.head;
	}
	else
	{
		l.tail->next = newNode;
		l.tail = newNode;
	}
	
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



int main()
{
	clock_t start, end;
	double duration;

	const int n = 100000;
	list l;
	init(l);
	randomList(l, n);
	start = clock();
	mergeSort(l);
	end = clock();
	duration = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << "Time: " << duration;
	remove(l);
	return 0;
}