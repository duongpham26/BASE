
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

node* SearchNode(DList list, int key)
{
   node *i = list.first;
   while (i && i->data != key)
      i = i->next;
   return i;
}

void RemoveHead(DList &list)
{
   if (!list.first)
      cout << "List is empty!" << endl;
   else if (list.first == list.last)
   {
      delete list.first;
      list.first = list.last = NULL;
   }
   else
   {
      node *temp = list.first;
      list.first->next->prev = NULL;
      list.first = list.first->next;
      delete temp;
   }
}

void RemoveTail(DList &list)
{
   if (!list.first)
      cout << "List is empty!" << endl;
   else if (list.first == list.last)
   {
      delete list.first;
      list.first = list.last = NULL;
   }
   else
   {
      node* temp = list.first;
      list.last->prev->next = NULL;
      list.last = list.last->prev;
      delete temp;
   }
}

void RemoveKey(DList &list, node *result)
{
   // node* result = SearchNode(list, key);
   if (result)
   {
      if (result == list.first)
         RemoveHead(list);
      else if (result == list.last)
         RemoveTail(list);
      else
      {
         result->prev->next = result->next;
         result->next->prev = result->prev;
         // delete result;
      }
   }
   else
      cout << "Key is not found!";      
}

// void loaiBoTrung(DList &list)
// {
//    node *i = list.first;
//    node *p;
//    node *temp;
//    while (i != NULL) {
//       p = i;
//       while(p!=NULL && i->next!=NULL) {

//       }
      
//    }
// }

void RemoveDuplicates(DList& l) {
    node* ptr1, *ptr2, *duplicate;
    ptr1 = l.first;

    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        while (ptr2->next != NULL) {
            if (ptr1->data == ptr2->next->data) {
                duplicate = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(duplicate);
            } else {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}
void RemoveNodesGreaterThan(DList& l, int x) {
    node* current = l.first;
    node* next;
    while (current != NULL) {
        if (current->data > x) {
            if (current == l.first) {
                l.first = current->next;
                l.first->prev = NULL;
            } else if (current == l.last) {
                l.last = current->prev;
                l.last->next = NULL;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            next = current->next;
            free(current);
            current = next;
        } else {
            current = current->next;
        }
    }
}



int main()
{
   int x;
   node *p;
   DList l;
   Init(l);

   // CreateListLast(l, x);

   // 
   InsertLast(l, 1);
   InsertLast(l, 2);
   InsertLast(l, 3);
   InsertLast(l, 1);
   InsertLast(l, 9);
   InsertLast(l, 1);
   InsertLast(l, 5);
   InsertLast(l, 9);
   InsertLast(l, 5);
   ProcessList(l);
   cout << "\n";
   // RemoveDuplicates(l);
   // ProcessList(l);
   // cout << "\n";

   RemoveNodesGreaterThan(l, 3);

   ProcessList(l);

  

   return 0;
}

