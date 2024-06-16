#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void randArray(int *arr, int N, int min, int max) {
	for (int i = 0; i < N; ++i) {
		arr[i] = rand() % (max - min + 1) + min;
	}
}

void writeArrayToFile(const int size, const string& fileName) {
	ofstream outfile(fileName);
	if (!outfile.is_open()) {
		cerr << "Failed to open file for writing.\n";
		return;
	}
	for (int i = 0; i < size; ++i) {
		outfile << rand() % size << " ";
	}
	outfile.close();
}

// Hàm đọc mảng từ file
void readArrayFromFile(int* arr, int size, const string& fileName) {
	ifstream infile(fileName);
	if (!infile.is_open()) {
		cerr << "Failed to open file for reading.\n";
		return;
	}
	for (int i = 0; i < size; ++i) {
		infile >> arr[i];
	}
	infile.close();
}


void printArray(int *arr, int N) {
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void shellsort(int a[], int n, int h[], int k)
{
	int step, i, j;
	int x, len;
	for (step = 0; step < k; step++)
	{
		len = h[step];
		for (i = len; i < n; i++)
		{
			x = a[i];
			j = i - len;
			while ((x < a[j]) && (j >= 0))
			{
				a[j + len] = a[j];
				j = j - len;
			}
			a[j + len] = x;
		}
	}
}

int main() {
	srand(time(NULL));
	const int n = 10000;
	int a[n];

	writeArrayToFile(n, "file.txt");

	readArrayFromFile(a, n, "file.txt");
	const int k = 12;
	int h[k];
	h[0] = 1;
	for (int i = 1; i < k; i++) {
		h[i] = (h[i - 1] - 1) / 2;
	}

	shellsort(a, n, h, k);

	printArray(a, n);

	
	return 0;
}