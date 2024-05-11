
#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;


struct person {
   int ID;
   char name[20];
   int yearofBirth;
};

struct node
{
   person data;
   node *father;
   node *chilren;
   node *siblings;
};


// struct DList
// {
//    node *first;
//    node *last;
// };

// void Init(DList &l)
// {
//    l.first = l.last = NULL;
// }

node *greatPersonNode(person data)
{
   // node *p = (node *)malloc(sizeof(node));
   node *personNode = new node;

   if (personNode == NULL)
   {
      printf("khong du bo nho!\n");
      return NULL;
   }
   personNode->data = data;
   personNode->father = NULL;
   personNode->chilren = NULL;
   personNode->siblings = NULL;
   return personNode;
}

void addChild(node *fatherNode, person data) {
   node *childNode = greatPersonNode(data);
   if(fatherNode->chilren == NULL) {// chua co con
      fatherNode->chilren = childNode;
      childNode->father = fatherNode;
   } else {
      node *indexNode = fatherNode->chilren;
      while(indexNode->siblings != NULL) {
         indexNode = indexNode->siblings;
      }
      indexNode->siblings = childNode;
      childNode->father = fatherNode;
   }
}

person inputPerson() {
   person data;
   cout << "Nhap ID: "; cin >> data.ID;
   cin.clear();
   fflush(stdin);
   cout << "Nhap Name: "; cin >> data.name; 
   cin.clear();
   fflush(stdin); 
   cout << "Nhap Tuoi: "; cin >> data.yearofBirth;
   return data;
}

// node addRootNode() {
//    root = greatPersonNode(inputPerson());
//    return root;
//    cout << "test " <<root->data.ID;
// }

void printPerSon(node *personNode) {
   cout << "ID: " << personNode->data.ID << "\n";
   cout << "Name: " << personNode->data.name << "\n";
   cout << "Year Of Birth: " << personNode->data.yearofBirth << "\n";
}



int main()
{
   node *root;
   root = greatPersonNode(inputPerson());

   printPerSon(root);

   addChild(root, inputPerson());
   printPerSon(root->chilren);

   cout << "\nthem 1 con nua--------------";
   addChild(root, inputPerson());
   printPerSon(root->chilren->siblings);



   

   return 0;
}

