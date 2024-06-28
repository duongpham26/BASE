
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

void insertionSort(DList &list)
{
   if (list.first == NULL || list.first->next == NULL)
   {
      return;
   }
   node *sortedEnd = list.first;
   while (sortedEnd->next != NULL)
   {
      node *curr = sortedEnd->next;
      if (curr->data >= sortedEnd->data)
      {
         sortedEnd = sortedEnd->next;
      }
      else
      {
         node *prevNode = sortedEnd;
         while (prevNode != NULL && curr->data < prevNode->data)
         {
            prevNode = prevNode->prev;
         }
         sortedEnd->next = curr->next;
         if (curr->next != NULL)
         {
            curr->next->prev = sortedEnd;
         }

         if (prevNode == NULL)
         {
            curr->prev = NULL;
            curr->next = list.first;
            list.first->prev = curr;
            list.first = curr;
         }
         else
         {
            curr->prev = prevNode;
            curr->next = prevNode->next;
            prevNode->next->prev = curr;
            prevNode->next = curr;
         }
      }
   }
   while (list.last->next != NULL)
   {
      list.last = list.last->next;
   }
}

node *split(node *head)
{
   node *fast = head, *slow = head;
   while (fast->next && fast->next->next)
   {
      fast = fast->next->next;
      slow = slow->next;
   }
   node *temp = slow->next;
   slow->next = NULL;
   return temp;
}

node *merge(node *first, node *second)
{
   if (!first)
      return second;

   if (!second)
      return first;

   if (first->data < second->data)
   {
      first->next = merge(first->next, second);
      first->next->prev = first;
      first->prev = NULL;
      return first;
   }
   else
   {
      second->next = merge(first, second->next);
      second->next->prev = second;
      second->prev = NULL;
      return second;
   }
}

node *mergeSort(node *head)
{
   if (!head || !head->next)
      return head;
   node *second = split(head);

   head = mergeSort(head);
   second = mergeSort(second);

   return merge(head, second);
}

void mergeSort(DList &dl)
{
   dl.first = mergeSort(dl.first);
   node *temp = dl.first;
   while (temp && temp->next)
   {
      temp = temp->next;
   }
   dl.last = temp;
}

int main()
{
   int x;
   node *p;
   DList l;
   Init(l);

   CreateListLast(l, x);
   ProcessList(l);
   mergeSort(l);

   // insertionSort(l);
   cout << "\n";
   ProcessList(l);

   return 0;
}

int main() {
   return 0;
}