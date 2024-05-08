#include "book.cpp"


void InsertFisrt(LIST &list, DATA data) {
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

// void InsertLast(LIST &list, DATA data) {
//    NODE *new_element;
//    new_element = CreateNode(data);
//    if(list.pHead == NULL) {
//       list.pHead = new_element;
//       list.pTail = list.pHead;
//    } else {
//       list. = new_element;
//    }
// }