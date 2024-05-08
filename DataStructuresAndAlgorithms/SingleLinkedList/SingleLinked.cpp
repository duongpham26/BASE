#include <iostream>
#include <iomanip>
using namespace std;

struct SINHVIEN
{
   int ID;
   char Ten[25];
};

typedef struct Node 
{
	SINHVIEN  SV;  	
	Node *link; 	
}NODE;	

typedef struct List 	// kiểu danh sách liên kết
{
	NODE* first;
	NODE* last; 	
}LIST;

void Init(LIST &l)
{
	l.first = l.last = NULL;
}

NODE* GetNode(SINHVIEN x) {
   NODE *p;
   p = new NODE;
   if(p == NULL) cout << "Khong du bo nho\n";
   p->SV = x;
   p->link = NULL;
   return p;
}

void AddFirst(LIST &l, NODE* new_ele){
	if (l.first == NULL) { //Xâu rỗng
		l.first = new_ele;
		l.last  = l.first;
	} else {	
		new_ele->link = l.first;  
		l.first = new_ele; 	
	}
}

NODE* InsertFirst(LIST &l, SINHVIEN x){	
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
		return NULL;
	AddFirst(l, new_ele);
	return new_ele;
}

void Create_List_First(LIST &l, SINHVIEN x) {
	NODE *p;
	int n;
	// cout<<"Nhap so phan tu: ";
	// cin>>n;
	for (int i=1;i<=n;i++) { 
        InsertFirst(l, x);
	}
}  



void AddLast(LIST &l, NODE *new_ele) {
	if (l.first==NULL) {
		l.first = new_ele;
		 l.last = l.first;
	} else {
		l.last->link = new_ele;
		l.last = new_ele ;
	}	
}

NODE* InsertLast(LIST &l, SINHVIEN x){	
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
		return NULL;
	AddLast(l, new_ele);
	return new_ele;
}

void CreateListLast(LIST &l, SINHVIEN x){
   NODE *p;
   int n;
   cout<<"Nhap so phan tu:";
   cin>>n;
   for (int i=1;i<=n;i++) {
      cout << "Nhap ID: "; cin >> x.ID;
      cout << "Nhap ten: "; 
      cin.clear();
      fflush(stdin);
      cin >> x.Ten;
      cin.clear();

      InsertLast(l,x);
   }
}

void InsertAfter(LIST &l,NODE *q,NODE* new_ele){
	if (q!=NULL && new_ele !=NULL) {
		new_ele->link = q->link;
		q->link = new_ele; 	
		if(q == l.last)
				l.last = new_ele; 
	}
}

void Xuat(NODE *p) {
   cout << "\n";
   cout << setw(20) << left << p->SV.ID;
   cout << setw(50) << left << p->SV.Ten;
}

void ProcessList (LIST &l) {	
	NODE *p;	
	p = l.first;
   cout << setw(20) << left <<  "ID";
   cout << setw(50) << left << "HO TEN";
	while (p!= NULL) { 
     Xuat(p); // xử lý cụ thể tùy ứng dụng
     p = p->link;
	}
}

int main() {
   NODE *p;
   LIST list;
   Init(list);
   SINHVIEN SV;

   CreateListLast(list, SV);
   ProcessList(list);


   
}