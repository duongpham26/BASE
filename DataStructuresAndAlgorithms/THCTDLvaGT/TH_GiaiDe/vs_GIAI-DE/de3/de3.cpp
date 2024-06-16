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

// A utility function to get maximum
// value in arr[]
SinhVien getMax(SinhVien arr[], int n)
{
	SinhVien mx = arr[0];
	for (int i = 1; i < n; i++)
		if (TinhDiemTrungBinh(arr[i].Diem5Mon) > TinhDiemTrungBinh(mx.Diem5Mon))
			mx = arr[i];
	return mx;
}

// A function to do counting sort of arr[]
// according to the digit
// represented by exp.
void countSort(SinhVien arr[], int n, int exp)
{

	// Output array
	SinhVien output[100];
	int i, count[10] = { 0 };

	for (i = 0; i < n; i++)
		count[((int)TinhDiemTrungBinh(arr[i].Diem5Mon) / exp) % 10]++;

	// Change count[i] so that count[i]
	// now contains actual position
	// of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[((int)TinhDiemTrungBinh(arr[i].Diem5Mon) / exp) % 10] - 1] = arr[i];
		count[((int)TinhDiemTrungBinh(arr[i].Diem5Mon) / exp) % 10]--;
	}

	// Copy the output array to arr[],
	// so that arr[] now contains sorted
	// numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// The main function to that sorts arr[]
// of size n using Radix Sort
void radixsort(SinhVien arr[], int n)
{

	// Find the maximum number to
	// know number of digits
	SinhVien m = getMax(arr, n);

	// Do counting sort for every digit.
	// Note that instead of passing digit
	// number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; TinhDiemTrungBinh(m.Diem5Mon) / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}




int main() {
	int n;
	SinhVien SV[100];
	cout << "Nhap so sinh vien: "; cin >> n;
	NhapDSSinhVien(n, SV);
	// CapNhatSV(SV, n);

	radixsort(SV, n);
	XuatThongTinMotSV(SV[0]);
	XuatThongTinMotSV(SV[1]);
	XuatThongTinMotSV(SV[2]);
	XuatThongTinMotSV(SV[3]);


	return 0;
}