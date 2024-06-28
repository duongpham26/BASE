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


void ListSelectionSort(list &l)
{
   list lRes;
   node *min, *p, *q, *minprev;
   lRes.head = lRes.tail = NULL;
   while (l.tail != NULL)
   {
      p = l.head;
      q = p->next;
      min = p;
      minprev = NULL;
      while (q != NULL)
      {
         if (q->data < min->data)
         {
            min = q;
            minprev = p;
         }
         p = q;
         q = q->next;
      }
      if (minprev != NULL)
         minprev->next = min->next;
      else
         l.head = min->next;
      min->next = NULL;
      addLast(lRes, min);
   }
   l = lRes;
}


int main() 
{
	clock_t start, end;
	double duration;

	const int n = 1000;
	list l;
	init(l);
	randomList(l, n);
	start = clock();
   ListSelectionSort(l);
	end = clock();

	//printList(l);
	duration = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << "Time: " << duration;
	remove(l);
	return 0;
}