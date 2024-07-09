#include <iostream>
#include "string.h"
using namespace std;

struct SinhVien {
	char HoVaTen[20];
	char MSSV[10];
	float Diem5Mon[5];
};

struct node {
	SinhVien data;
	node *prev;
	node *next;
};

struct DList {
	node *first;
	node *last;
};

void Init(DList &l)
{
	l.first = l.last = NULL;
}

node * GetNode(SinhVien x) {
	node* p = new node;
	if (p == NULL) {
		printf("khong du bo nho!\n");
		return NULL;
	}
	p->data = x;
	p->prev = NULL;
	p->next = NULL;
	return p;
};

void AddLast(DList& l, node* new_ele) {
	if (l.first == NULL) {
		l.first = new_ele;
		l.last = new_ele;
	}
	else {
		l.last->next = new_ele;
		new_ele->prev = l.last;
		l.last = new_ele;
	}
};

void AddFirst(DList& l, node* new_ele) {
	if (l.first == NULL) {
		l.first = new_ele;
		l.last = new_ele;
	}
	else {
		new_ele->next = l.first;
		l.first->prev = new_ele;
		l.first = new_ele;
	}
}


node* InsertLast(DList& l, SinhVien x) {
	node * new_ele = GetNode(x);
	if (new_ele == NULL) return NULL;
	else {
		if (l.first == NULL) {
			l.first = new_ele;
			l.last = new_ele;
		}
		else {
			l.last->next = new_ele;
			new_ele->prev = l.last;
			l.last = new_ele;
		}
	}
	return new_ele;
}

void RemoveFirst(DList& l) {
	node* p;
	if (l.first != NULL) {
		p = l.first;
		l.first = l.first->next;
		delete p;
		if (l.first == NULL)
			l.last = NULL;
		else
			l.first->prev = NULL;
	}
}

node* SearchNode(DList list, const char* mssv)
{
	node *i = list.first;
	while (i && strcmp(mssv, i->data.MSSV))
		i = i->next;
	return i;
}

void CreateListLast(DList &l)
{
	int n;
	cout << "Nhap so phan tu:";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		SinhVien SV;
		cin.ignore();
		cout << "Nhap Ho Va Ten: ";
		fgets(SV.HoVaTen, sizeof(SV.HoVaTen), stdin);
		SV.HoVaTen[strcspn(SV.HoVaTen, "\n")] = '\0';
		cout << "Nhap MSSV: ";
		fgets(SV.MSSV, sizeof(SV.MSSV), stdin);
		SV.MSSV[strcspn(SV.MSSV, "\n")] = '\0';
		for (int i = 0; i < 5; i++) {
			cout << "Nhap diem mon " << i + 1 << ": "; cin >> SV.Diem5Mon[i];
		}
		InsertLast(l, SV);
	}
};

float TinhDiemTrungBinh(float *a) {
	float sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += a[i];
	}
	return sum / 5;
}

void QuickSort(DList &list) {
	DList l1, l2;
	node *x, *p;
	if (list.first == list.last) return;
	Init(l1); Init(l2);
	x = list.first;
	list.first = list.first->next;
	list.first->prev = NULL;

	x->next = NULL; x->prev = NULL;

	while (list.first != NULL) {
		p = list.first;
		list.first = list.first->next;

		//list.first->prev = NULL;
		p->next = NULL;
		p->prev = NULL;
		if (TinhDiemTrungBinh(p->data.Diem5Mon) <= TinhDiemTrungBinh(x->data.Diem5Mon)) AddFirst(l1, p);
		else AddFirst(l2, p);
	}
	QuickSort(l1);
	QuickSort(l2);
	if (l1.first != NULL) {
		list.first = l1.first;
		l1.last->next = x;
		x->prev = l1.last;
	}
	else list.first = x;
	x->next = l2.first;
	if (l2.first != NULL) {
		l2.first->prev = x;
		list.last = l2.last;
	}
	else list.last = x;
}

void XuatThongTinMotSV(SinhVien SV) {
	cout << "Ho Va Ten: " << SV.HoVaTen << "\n";
	cout << "MSSV: " << SV.MSSV << "\n";
	cout << "Diem trung binh: " << TinhDiemTrungBinh(SV.Diem5Mon) << "\n";
}

void Duyet(DList list)
{
	node *i = list.first;
	while (i != NULL) {
		XuatThongTinMotSV(i->data);
		i = i->next;
	}
}



int main() {
	node *SV;
	DList list;

	Init(list);
	CreateListLast(list);

	/*char x[10];
	cout << "Nhap MSSV can tim: ";
	cin >> x;*/
	/*SV = SearchNode(list, x);
	if (SV != NULL) {
		cout << "TIM DC:" << SV->data.HoVaTen;
	}*/

	QuickSort(list);
	Duyet(list);

	return 0;
}






