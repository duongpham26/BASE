#include <iostream>
using namespace std;

struct ListNode
{
	int data;
	ListNode *next;
};

int ListLength(ListNode *head)
{
	if (head == NULL) 
	{
		cout << "List empty." << endl;
		return -1;
	}
	ListNode *current = head;
	int count = 0;
	while (current != NULL)
	{
		count++;
		cout << current->data << " ";
		current = current->next;
	}
	return count;
}

void InsertInLinkedList(ListNode **head, int data, int position)
{
	int k = 1;
	ListNode *p, *newNode;
	newNode = new ListNode;
	if (!newNode)
	{
		cout << "Memory Error" << endl;
			return;
	}
	newNode->data = data;
	p = *head;
	if (position == 1)
	{
		newNode->next = p;
		*head = newNode;
	} 
	else
	{
		int k = 1;
		ListNode *q = NULL;
		while (p != NULL && k < position)
		{
			k++;
			q = p;
			p = p->next;
		}
		q->next = newNode;
		newNode->next = p;
	}
}

void DeleteNodeFromLinkedList(ListNode *&head, int position)
{
	int k = 1;
	ListNode *p, *q;
	if (head == NULL) 
	{ 
		cout << "List Empty";
		return;
	}
	p = head;
	if (position == 1)
	{
		head = head->next;
		delete p;
	}
	else 
	{
		ListNode *q = NULL;
		while (p != NULL && k < position)
		{
			k++;
			q = p;
			p = p->next;
		}
		if (p == NULL)
		{
			cout << "Position dose not exist." << endl;
		}
		q->next = p->next;
		delete p;
	}
}

void DeleteLinkedList(ListNode *&head)
{
	if (head == NULL)
	{
		cout << "List Empty." << endl;
		return;
	}
	ListNode *p, *q;
	p = head;
	while (p != NULL)
	{
		q = p->next;
		delete(p);
		p = q;
	}
	head = NULL;
}


int main()
{

	ListNode *head = NULL;

	InsertInLinkedList(&head, 9, 1);
	InsertInLinkedList(&head, 8, 1);
	InsertInLinkedList(&head, 7, 1);
	InsertInLinkedList(&head, 6, 1);
	InsertInLinkedList(&head, 2, 1);
	InsertInLinkedList(&head, 3, 1);
	DeleteNodeFromLinkedList(head, 1);
	cout << ListLength(head) << endl;
	DeleteLinkedList(head);
	cout << ListLength(head) << endl;

	cout << "dd";

	return 0;
}