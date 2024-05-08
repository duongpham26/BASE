#include <iostream>
#include <conio.h>
// #include "Insert.cpp"

using namespace std;

struct DATA{
   int x;
};

typedef struct tagNode{
   DATA data;
   tagNode *pNext;
} NODE;

typedef struct tageList{
   NODE *pHead;
   NODE *pTail;
}LIST;

void init(LIST &list) {
   list.pHead = list.pTail = NULL;
}

NODE *CreateNode(DATA data) {
   NODE *p = new NODE;
   if(p==NULL) {
      cout << "Khong du bo nho\n"; exit(1);
   }
   p->data = data;
   p->pNext = NULL;
   return p;
}

void InsertFirst(LIST &list, DATA data) {
   NODE *new_element;
   new_element = CreateNode(data);
   if(list.pHead == NULL) {
      list.pHead = new_element;
      list.pTail = list.pHead;
   } else {
      new_element->pNext = list.pHead;
      list.pHead = new_element;
   }
}

void DeleteFirst(LIST &list) {
   NODE *p = list.pHead;
   if(p!=NULL) { // danh sach kh rong
      list.pHead = p->pNext;
      delete p;
   }
}

void InsertLast(LIST &list, DATA data) {
   NODE *new_element;
   new_element = CreateNode(data);
   if(list.pHead == NULL) {
      list.pHead = new_element;
      list.pTail = list.pHead;
   } else {
      list.pTail->pNext = new_element;
      list.pTail = new_element;
   }
}

void InsertAfter(LIST &list, DATA data, NODE *q) {
   NODE *new_element;
   new_element = CreateNode(data);
   if(q != NULL && q != list.pTail) {
      new_element->pNext = q->pNext;
      q->pNext = new_element;
   } else {
      InsertLast(list, data);
   }
}


void CreateList(LIST &list) {
   int n;
   DATA data;
   cout <<"Nhap vao so phan tu n = "; cin >> n;
   for(int i = 0; i < n; ++i) {
      cout << "Nhap x = "; cin >> data.x;
      InsertLast(list, data);
   }
}

void Process(LIST list) {
   NODE *indexNODE;
   indexNODE = list.pHead;
   while(indexNODE != NULL) {
      cout << indexNODE->data.x << " ";
      indexNODE = indexNODE->pNext;
   }
}

NODE* Search(LIST list, int ID) {
   NODE *indexNODE = list.pHead;
   while(indexNODE != NULL && indexNODE->data.x != ID) {
      indexNODE = indexNODE->pNext;
   }
   if(indexNODE->data.x =! ID ) return NULL;
   return indexNODE;
}

void DeleteNode(LIST &list, int ID) {
   NODE *deleteNode = list.pHead;
   NODE *prevNode = NULL;
   while(deleteNode != NULL && deleteNode->data.x != ID) {
      prevNode = deleteNode;
      deleteNode = deleteNode->pNext;
   } 
   if(deleteNode != NULL) {
      if(prevNode != NULL) {
         if(deleteNode == list.pTail) list.pTail = prevNode;
         prevNode->pNext = deleteNode->pNext;
         delete prevNode;
      } else {
         
      }
   }
}






int main() {
   DATA da;
   LIST list;
   init(list);

   int d = 1;
   da.x = d;
   CreateList(list);
   Process(list);

   NODE *p = Search(list, 2);
   cout << "Search node = " << p->data.x;

   return 0;
}