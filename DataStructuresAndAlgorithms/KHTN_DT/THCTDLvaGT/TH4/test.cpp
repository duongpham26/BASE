
#include <iostream>
using namespace std;

struct node
{
   int data;
   node *prev;
   node *next;
};

struct DList
{
   node *first;
   node *last;
};

void Init(DList &l)
{
   l.first = l.last = NULL;
}

node *GetNode(int x)
{
   node *p = (node *)malloc(sizeof(node));
   if (p == NULL)
   {
      printf("khong du bo nho!\n");
      return NULL;
   }
   p->data = x;
   p->prev = NULL;
   p->next = NULL;
   return p;
}

void AddLast(DList &l, node *new_ele)
{
   if (l.first == NULL)
   {
      l.first = new_ele;
      l.last = new_ele;
   }
   else
   {
      l.last->next = new_ele;
      new_ele->prev = l.last;
      l.last = new_ele;
   }
}

node *InsertLast(DList &l, int x)
{
   node *new_ele = GetNode(x);
   if (new_ele == NULL)
      return NULL;
   else
   {
      if (l.first == NULL)
      {
         l.first = new_ele;
         l.last = new_ele;
      }
      else
      {
         l.last->next = new_ele;
         new_ele->prev = l.last;
         l.last = new_ele;
      }
   }
   return new_ele;
}

void CreateListLast(DList &l, int x)
{
   node *p;
   int n;
   cout << "Nhap so phan tu:";
   cin >> n;
   for (int i = 1; i <= n; i++)
   {
      cout << "Nhap x: ";
      cin >> x;
      cin.clear();
      InsertLast(l, x);
   }
}

void ProcessList(DList &l)
{
   node *p;
   p = l.first;
   while (p != NULL)
   {
      cout << p->data << " ";
      p = p->next;
   }
}

void distributeList(DList &l, DList &list1, DList &list2) {
	node *p;
	while (l.first) {
		p = l.first;
		l.first = p->next;
		p->next = nullptr;
		p->prev = nullptr;
		AddLast(list1, p);

		if (l.first) {
			p = l.first;
			l.first = p->next;
			p->next = nullptr;
         p->prev = NULL;
			AddLast(list2, p);
		}
	}
	l.last = nullptr;
}

void merge(DList &l, DList &list1, DList &list2) {
	node *p;
	while (list1.first && list2.first) {
		if (list1.first->data <= list2.first->data) {
			p = list1.first;
			list1.first = p->next;
		}
		else {
			p = list2.first;
			list2.first = p->next;
		}
		p->next = NULL;
      p->prev = NULL;
		AddLast(l, p);
	}
	if (list1.first) {
		l.last->next = list1.first;
      list1.first->prev = l.last;
		l.last = list1.last;
	}
	else if (list2.first) {
		l.last->next = list2.first;
      list2.first->prev = l.last;
		l.last = list2.last;
	}
}

void mergeSort(DList &l) {
	DList list1, list2;
	if (l.first == l.last) return;
	Init(list1); Init(list2);

	distributeList(l, list1, list2);
	mergeSort(list1);
	mergeSort(list2);
	merge(l, list1, list2);
}

int main()
{
   int x;
   node *p;
   DList l;
   Init(l);

   InsertLast(l, 5);
   InsertLast(l, 1);
   InsertLast(l, 2);
   InsertLast(l, 4);
   InsertLast(l, 9);
   InsertLast(l, 6);
   ProcessList(l);


   mergeSort(l);

   cout << "\n";
   ProcessList(l);

   return 0;
}
