#include <iostream>
using namespace std;

struct DLLNode 
{
	int data;
	DLLNode *next;
	DLLNode *prev;
};

int ListLength(DLLNode *head)
{
	if (head == NULL)
	{
		cout << "List Empty." << endl;
		return -1;
	}
	int count = 0;
	DLLNode *current = head;
	while (current != NULL)
	{
		count++;
		cout << current->data << " ";
		current = current->next;
	}
	return count;
}

void InsertInDoubleLinkedList(DLLNode *&head, int data,int position)
{
	DLLNode *newNode;
	newNode = new DLLNode;
	if (!newNode) 
	{
		cout << "Memory Error." << endl;
		return;
	}
	newNode->data = data;
	if (position == 1)
	{
		newNode->next = head;
		newNode->prev = NULL;
		if (head) head->prev = newNode;
		head = newNode;
	}
	else 
	{
		DLLNode *temp = head;
		int k = 1;
		while (k < position - 1 && temp->next != NULL)
		{
			k++;
			temp = temp->next;
		}
		newNode->next = temp->next;
		newNode->prev = temp;
		if (temp->next) temp->next->prev = newNode;
		temp->next = newNode;
	}
}

void DLLDelete(DLLNode *&head, int position)
{
	if (head == NULL)
	{
		cout << "List Empty." << endl;
		return;
	}
	DLLNode *temp = head;
	if (position == 1)
	{
		head = head->next;
		if(head != NULL) head->prev = NULL;
		delete temp;
	}
	else 
	{
		int k = 1;
		DLLNode *temp2;
		while (k < position && temp->next != NULL)
		{
			k++;
			temp = temp->next;
		}
		if (k != position)
		{
			cout << "Desired position dose not exist." << endl;
			return;
		}
		temp2 = temp->prev;
		temp2->next = temp->next;
		if (temp->next != NULL) temp->next->prev = temp2;
		delete temp;
	}
}

void DeleteDoubleLinkedList(DLLNode *&head)
{
	if (!head)
	{
		cout << "List Empty." << endl;
	}
	DLLNode *p = head;
	while (head != NULL)
	{
		p = head;
		head = head->next;
		delete p;
	}
}


int main()
{
	DLLNode *head = NULL;
	InsertInDoubleLinkedList(head, 5, 1);
	InsertInDoubleLinkedList(head, 4, 1);
	InsertInDoubleLinkedList(head, 3, 1);
	InsertInDoubleLinkedList(head, 2, 2);
	InsertInDoubleLinkedList(head, 1, 3);
	ListLength(head);
	DLLDelete(head, 5); cout << endl;
	ListLength(head);
	DeleteDoubleLinkedList(head);

	return 0;
}