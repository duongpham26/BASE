#include <iostream>
#include <iomanip>
#include <fstream>
#include <Windows.h>
#include <conio.h>
using namespace std;

struct Sach {
	char TenSach[20];
	char MaSoSach[12];
	int GiaTien;
	int SoLuongConLai;
};

struct node {
	Sach data;
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

node * GetNode(Sach x) {
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


node* InsertFirst(DList& l, Sach x) {
	node* new_ele = GetNode(x);
	if (new_ele == NULL) return NULL;
	else {
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
}

node* InsertLast(DList& l, Sach x) {
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

void RemoveLast(DList& l) {
	node* p;
	if (l.last != NULL) {
		p = l.last;
		l.last = l.last->prev;
		l.last->next = NULL;
		free(p);
		if (l.first == NULL) l.last = NULL;
		else l.first->prev = NULL;
	}
}

void removeList(DList &l) {
	node *p = l.first;
	while (l.first != NULL) {
		p = l.first;
		l.first = l.first->next;
		delete p;
	}
	l.first = l.last = NULL;
}

void nhapMotSach(Sach &sach) {

	cin.ignore();
	cout << "Nhap ma so sach: ";
	fgets(sach.MaSoSach, sizeof(sach.MaSoSach), stdin);
	sach.MaSoSach[strcspn(sach.MaSoSach, "\n")] = '\0';

	//cin.ignore();
	cout << "Nhap ten sach: ";
	fgets(sach.TenSach, sizeof(sach.TenSach), stdin);
	sach.TenSach[strcspn(sach.TenSach, "\n")] = '\0';

	cout << "Nhap gia tien: ";
	cin >> sach.GiaTien;

	cout << "Nhap so luong: ";
	cin >> sach.SoLuongConLai;
}

void TaoListSach(DList &l)
{
	int n;
	cout << "Nhap so phan tu:";
	cin >> n;
	Sach sach;
	for (int i = 1; i <= n; i++)
	{
		cout << "\n";
		cout << "Sach thu " << i << endl;
		nhapMotSach(sach);
		InsertLast(l, sach);
	}
};


void XuatThongTinMotSach(Sach sach) {
	cout << setw(20) << left << sach.MaSoSach;
	cout << setw(50) << left << sach.TenSach;
	cout << setw(25) << left << sach.GiaTien;
	cout << setw(25) << left << sach.SoLuongConLai;
}

void XuatDanhSach(DList list)
{
	cout << setw(20) << left << "MA SO";
	cout << setw(50) << left << "TEN SACH";
	cout << setw(25) << left << "GIA TIEN";
	cout << setw(25) << left << "SO LUONG";
	cout << "\n";
	node *i = list.first;
	while (i != NULL) {
		XuatThongTinMotSach(i->data);
		i = i->next;
	}
}

node* SearchNode(DList list, const char* mssv)
{
	node *i = list.first;
	while (i && strcmp(mssv, i->data.MaSoSach))
		i = i->next;
	return i;
}

void XuatMotSach(Sach sach) {
	cout << setw(20) << left << "MA SO";
	cout << setw(50) << left << "TEN SACH";
	cout << setw(25) << left << "GIA TIEN";
	cout << setw(25) << left << "SO LUONG";
	cout << "\n";
	XuatThongTinMotSach(sach);
}

void TimSach(DList list) {
	char ms[12];
	cout << "Nhap ma so sach can tim: ";
	fgets(ms, sizeof(ms), stdin);
	ms[strcspn(ms, "\n")] = '\0';
	node *sach = SearchNode(list, ms);
	XuatMotSach(sach->data);
}

void SuaThongTinSach(DList list) {
	char ms[12];
	cout << "Nhap ma so sach can sua: ";
	fgets(ms, sizeof(ms), stdin);
	ms[strcspn(ms, "\n")] = '\0';
	node *sachNode = SearchNode(list, ms);

	int option;
	do
	{
		system("cls");
		cout << "1. Ma so." << endl;
		cout << "2. Ten sach." << endl;
		cout << "3. So luong." << endl;
		cout << "4. Gia tien." << endl;
		cout << "5. Sua tat ca thong tin." << endl;
		cout << "0. Thoat." << endl;
		cout << "Ban muon sua gi: "; cin >> option; cin.ignore();
		switch (option)
		{
		case 1: 
			cout << "Nhap ma so sach: ";
			fgets(sachNode->data.MaSoSach, sizeof(sachNode->data.MaSoSach), stdin);
			sachNode->data.MaSoSach[strcspn(sachNode->data.MaSoSach, "\n")] = '\0';
			cout << "Nhap phim bat ki de tiep tuc." << endl;
			_getch();
			break;
		case 2:
			cout << "Nhap ten sach: ";
			fgets(sachNode->data.TenSach, sizeof(sachNode->data.TenSach), stdin);
			sachNode->data.TenSach[strcspn(sachNode->data.TenSach, "\n")] = '\0';
			cout << "Nhap phim bat ki de tiep tuc." << endl;
			_getch();
			break;
		case 3:
			cout << "Nhap gia tien: ";
			cin >> sachNode->data.GiaTien;
			cout << "Nhap phim bat ki de tiep tuc." << endl;
			_getch();
			break;
		case 4:
			cout << "Nhap so luong: ";
			cin >> sachNode->data.SoLuongConLai;
			cout << "Nhap phim bat ki de tiep tuc." << endl;
			_getch();
			break;
		case 5:
			nhapMotSach(sachNode->data);
		default:
			break;
		}
	} while (option != 0);
}

void GhiFile(DList list) {
	ofstream file("sach.dat", std::ios::binary);
	if (!file) {
		cout << "Can not open file." << endl;
		return;
	}

	node *index = list.first;
	while (index != NULL)
	{
		file.write(reinterpret_cast<const char*>(&(index->data)), sizeof(index->data));	
		index = index->next;
	}
	file.close();
}


void DocFile(DList &list) {
	removeList(list);
	ifstream file("sach.dat", std::ios::binary); // Mở file ở chế độ đọc nhị phân
	if (!file) {
		cout << "Cannot open file." << endl;
		return;
	}
	Sach sach;
	while (true) {
		file.read(reinterpret_cast<char*>(&sach), sizeof(Sach));
		if (file.eof()) {
			break;
		}
		InsertLast(list, sach);
		if (file.fail()) {
			cout << "Error reading file." << std::endl;
			break;
		}
	}
	file.close();
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
		if (list1.first->data.GiaTien <= list2.first->data.GiaTien) {
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

void InDSdaSapXep(DList list) {
	ofstream fileOut("sorted.txt");
	if (!fileOut) {
		cout << "Không thể mở file để ghi dữ liệu!" << endl;
		return;
	}
	fileOut << setw(20) << left << "MA SO";
	fileOut << setw(50) << left << "TEN SACH";
	fileOut << setw(25) << left << "GIA TIEN";
	fileOut << setw(25) << left << "SO LUONG";
	fileOut << "\n";
	node *index = list.first;
	while (index != NULL) {
		fileOut << setw(20) << left << index->data.MaSoSach;
		fileOut << setw(50) << left << index->data.TenSach;
		fileOut << setw(25) << left << index->data.GiaTien;
		fileOut << setw(25) << left << index->data.SoLuongConLai;
		fileOut << "\n";
		index = index->next;
	}

	fileOut.close();
}

int main() {
	node *sach;
	DList list;
	Init(list);
	int option;
	do
	{
		system("cls");
		cout << "1. Nhap danh sach sach trong thu vien." << endl;
		cout << "2. Ghi danh sach vao file." << endl;
		cout << "3. Doc danh sach ra tu file." << endl;
		cout << "4. Tim kiem danh sach theo ma so." << endl;
		cout << "5. Tao ma vach bang ma so sach." << endl;
		cout << "6. Sua thong tin sach." << endl;
		cout << "7. Sap xep tang dan theo don gia Merge Sort." << endl;
		cout << "8. Xuat danh sach sach." << endl;
		cout << "0. Thoat." << endl;
		cout << "Ban chon gi: "; cin >> option;
		cin.ignore();
		switch (option)
		{
		case 1: 
			TaoListSach(list);
			cout << "Nhap phim bat ki de tiep tuc." << endl;
			_getch();
			break;
		case 2:
			GhiFile(list);
			cout << "Nhap phim bat ki de tiep tuc." << endl;
			_getch();
			break; 
		case 3:
			DocFile(list);
			cout << "Nhap phim bat ki de tiep tuc." << endl;
			getchar();
			break;
		case 4:
			TimSach(list);
			cout << "Nhap phim bat ki de tiep tuc." << endl;
			getchar();
			break;
		case 5:
			break;
		case 6:
			SuaThongTinSach(list);
			cout << "Nhap phim bat ki de tiep tuc." << endl;
			getchar();
			break;
		case 7:
			mergeSort(list);
			InDSdaSapXep(list);
			cout << "Nhap phim bat ki de tiep tuc." << endl;
			getchar();
			break;
		case 8:
			XuatDanhSach(list);
			cout << "Nhap phim bat ki de tiep tuc." << endl;
			getchar();
			break;
		default:
			break;
		}
	} while (option != 0);
	removeList(list);
	return 0;
}






