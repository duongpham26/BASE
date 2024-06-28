#include <iostream>
#include "string.h"
using namespace std;

struct SinhVien {
	char HoVaTen[20];
	char MSSV[10];
	float Diem5Mon[5];
};

void NhapMotSinhVien(SinhVien &SV) {
	cin.ignore();
	cout << "Nhap Ho Va Ten: ";
	fgets(SV.HoVaTen, sizeof(SV.HoVaTen), stdin);
	cout << "Nhap MSSV: "; fgets(SV.MSSV, sizeof(SV.MSSV), stdin);
	SV.MSSV[strcspn(SV.MSSV, "\n")] = '\0';
	for (int i = 0; i < 5; i++) {
		cout << "Nhap diem mon " << i + 1 << ": "; cin >> SV.Diem5Mon[i];
	}
}

void NhapDSSinhVien(int n, SinhVien *SV) {
	for (int i = 0; i < n; i++) {
		cout << "\nNhap Sinh Vien Thu " << i + 1 << "\n";
		NhapMotSinhVien(SV[i]);
	}
}

float TinhDiemTrungBinh(float *a) {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += a[i];
	}
	return sum / 5;
}

void XuatThongTinMotSV(SinhVien SV) {
	cout << "Ho Va Ten: " << SV.HoVaTen << "\n";
	cout << "MSSV: " << SV.MSSV << "\n";
	cout << "Diem trung binh: " << TinhDiemTrungBinh(SV.Diem5Mon) << "\n";
}

int TimSinhVien(int n, SinhVien *SV) {
	char id[10];
	cin.ignore();
	cout << "Nhap MSSV can tim: ";
	fgets(id, sizeof(id), stdin);
	for (int i = 0; i < n; i++) {
		if (!strcmp(id, SV[i].MSSV)) {
			return i;
		}
	}
	return 0;
}

void CapNhatSV(SinhVien *SV, int n) {
	cout << "\nCap nhat sinh vien\n";
	int vitri = TimSinhVien(n, SV);
	NhapMotSinhVien(SV[vitri]);
	XuatThongTinMotSV(SV[vitri]);
}

// thuan toan head sort
void sift(SinhVien *a, int left, int right) {
	int i = left;
	int j = 2 * left + 1;
	SinhVien x = a[left];
	while (j <= right) {
		if (j < right) {
			float diemNhanhTrai = TinhDiemTrungBinh(a[j].Diem5Mon);
			float diemNhanhPhai = TinhDiemTrungBinh(a[j + 1].Diem5Mon);
			if (diemNhanhTrai < diemNhanhPhai) j++;
		}
		if (TinhDiemTrungBinh(x.Diem5Mon) >= TinhDiemTrungBinh(a[j].Diem5Mon)) break;
		a[i] = a[j];
		i = j;
		j = 2 * i + 1;
	}
	a[i] = x;
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void headSort(SinhVien *a, int n) {
	//tao head
	int left = n / 2 - 1;
	while (left >= 0) {
		sift(a, left, n - 1);
		left--;
	}

	// doi vi tri va dieu chinh head
	int right = n - 1;
	while (right > 0) {
		swap(a[0], a[right]);
		right--;
		sift(a, 0, right);
	}
}



int main() {
	int n;
	SinhVien SV[100];
	cout << "Nhap so sinh vien: "; cin >> n;
	NhapDSSinhVien(n, SV);
	// CapNhatSV(SV, n);

	headSort(SV, n);
	XuatThongTinMotSV(SV[0]);
	XuatThongTinMotSV(SV[1]);
	XuatThongTinMotSV(SV[2]);
	XuatThongTinMotSV(SV[3]);
	return 0;
}