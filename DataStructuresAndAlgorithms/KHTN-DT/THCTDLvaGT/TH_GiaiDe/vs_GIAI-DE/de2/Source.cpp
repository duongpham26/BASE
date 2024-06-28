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
	SV.HoVaTen[strcspn(SV.HoVaTen, "\n")] = '\0';
	cout << "Nhap MSSV: "; 
	fgets(SV.MSSV, sizeof(SV.MSSV), stdin);
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

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void merge(SinhVien arr[], int l, int m, int r)
{
	int i, j, k;
	const int n1 = m - l + 1;
	const int n2 = r - m;

	// Create temp arrays
	SinhVien L[50], R[50];

	// Copy data to temp arrays L[] and R[]
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Merge the temp arrays back into arr[l..r
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (TinhDiemTrungBinh(L[i].Diem5Mon) <= TinhDiemTrungBinh(R[j].Diem5Mon)) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of L[],
	// if there are any
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of R[],
	// if there are any
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergeSort(SinhVien arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

int main() {
	int n;
	SinhVien SV[100];
	cout << "Nhap so sinh vien: "; cin >> n;
	NhapDSSinhVien(n, SV);
	// CapNhatSV(SV, n);

	mergeSort(SV, 0, n-1);
	XuatThongTinMotSV(SV[0]);
	XuatThongTinMotSV(SV[1]);
	XuatThongTinMotSV(SV[2]);
	XuatThongTinMotSV(SV[3]);


	return 0;
}