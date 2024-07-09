
#include <iostream>
#include <string.h>
#include <conio.h>
#include <iomanip>
using namespace std;


struct person {
   int ID;
   char name[20];
   int yearofBirth;
};

struct node
{
   person data;
   node *parent;
   node *chilren;
   node *siblings;
};

node *greatPersonNode(person data)
{
   node *personNode = new node;

   if (personNode == NULL)
   {
      printf("khong du bo nho!\n");
      return NULL;
   }
   personNode->data = data;
   personNode->parent = NULL;
   personNode->chilren = NULL;
   personNode->siblings = NULL;
   return personNode;
}

void addChild(node *parentNode, person data) {
   node *childNode = greatPersonNode(data);
   if(parentNode->chilren == NULL) {// chua co con
      parentNode->chilren = childNode;
      childNode->parent = parentNode;
   } else {
      node *indexNode = parentNode->chilren;
      while(indexNode->siblings != NULL) {
         indexNode = indexNode->siblings;
      }
      indexNode->siblings = childNode;
      childNode->parent = parentNode;
   }
}

person inputPerson() {
   person data;
   cin.clear();
   fflush(stdin);
   cout << "Enter ID: "; cin >> data.ID;
   cin.clear();
   fflush(stdin);
   cout << "Enter Name: "; gets(data.name);

   cin.clear();
   fflush(stdin); 
   cout << "Enter Year Of Birth: "; cin >> data.yearofBirth;
   return data;
}

void printPerSon(node *personNode) {
   cout << "\n";
   cout << setw(10) << left << personNode->data.ID;
   cout << setw(25) << left << personNode->data.name;
   cout << setw(25) << left << personNode->data.yearofBirth;
}

void printParentAndChilren(node *parentNode) {
   cout <<"-------------------------------------------------\n";
   cout <<"---parent-----\n";
   cout << setw(10) << left <<  "ID";
   cout << setw(25) << left << "Name";
   cout << setw(25) << left << "Year Of Birth";
   printPerSon(parentNode);
   cout <<"\n\n---CHILDREN-----\n";
   cout << setw(10) << left <<  "ID";
   cout << setw(25) << left << "Nam";
   cout << setw(25) << left << "Year Of Birth";
   node *indexNode = parentNode->chilren;
   while(indexNode != NULL) {
      printPerSon(indexNode);
      indexNode = indexNode->siblings;
   }
   cout <<"\n-------------------------------------------------\n\n";
}

node *search(node *rootNode, int ID) {
   if(rootNode != NULL) {
      if(rootNode->data.ID == ID)
			return rootNode;
		else if (rootNode->data.ID > ID)
			return search(rootNode->chilren, ID);
		else return search(rootNode->siblings, ID);
   }
   return NULL;
}

void addChildForParent(node *rootNode) {
   int ID;
   node *searchNodeParent;
   do {
      cout << "Enter the ID of the parent who wants to add the child: "; cin >> ID;
      searchNodeParent = search(rootNode, ID);
      if(searchNodeParent == NULL) cout << "Not found, please re-enter ID!\n";
   } while(search(rootNode, ID) == NULL);
   addChild(searchNodeParent, inputPerson());
}

void searchPrintParentAndChilren(node *rootNode) {
   int ID;
   node *searchNodeParent;
   do {
      cout << "Enter the ID of the parent who wants to print information: "; cin >> ID;
      searchNodeParent = search(rootNode, ID);
      if(searchNodeParent == NULL) cout << "Not found, please re-enter ID!\n";
   } while(search(rootNode, ID) == NULL);
   printParentAndChilren(searchNodeParent);
}



int main()
{
   node *root; //nut goc

   //tao thanh vien moi ID = 10
   cout << "Enter information for root.\n";
   root = greatPersonNode(inputPerson());

   //them con cho node cha ID = 10
   addChildForParent(root); //ID = 7
   addChildForParent(root); //ID = 8
   addChildForParent(root); //ID = 9

   //them con cho node cha ID = 7
   addChildForParent(root); // ID = 5
   addChildForParent(root); // ID = 6

   cout <<"\n";
   // in ra node ID = 10 va cac con cua no
   searchPrintParentAndChilren(root);

   // in ra node ID = 7 va cac con cua no
   searchPrintParentAndChilren(root);

   return 0;
}

