#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>
#include <math.h>
using namespace std;

void randomArray(int *a, int size) {
	for (int i = 0; i < size; i++) {
		a[i] = rand() % size;
	}
}

void printArray(int *a, int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}

int getMax(int *a, int size) {
	int max = a[0];
	for (int i = 1; i < size; i++) {
		if (a[i] > max) max = a[i];
	}
	return max;
}

int digit(int a, int k) {
	int i = 0;
	int d;
	while (i <= k) {
		d = a % 10;
		a /= 10;
		i++;
	}
	return d;
}

void sort(int *a, int k, int size) {
	const int RADIX = 10;
	int j;
	int *f = new int[RADIX]();
	int *b = new int[size];
	for (int i = 0; i < size; i++) f[digit(a[i], k)]++;
	for (int i = 1; i < RADIX; i++) f[i] += f[i - 1];
	for (int i = size - 1; i >= 0; i--) {
		j = digit(a[i], k);
		b[f[j] - 1] = a[i];
		f[j]--;
	}
	for (int i = 0; i < size; i++) a[i] = b[i];
	delete f;
	delete b;
}

void LSDRadixSort(int *a, int size) {
	int max = getMax(a, size);
	int d = log10(double(max)) + 1;
	for (int k = 0; k < d; k++) {
		sort(a, k, size);
	}
}

int main() {
	//srand(time(0));
	clock_t start, end;
	double duration;
	const int n = 10000000;
	int *a = new int[n];
	randomArray(a, n);
	start = clock();
	LSDRadixSort(a, n);
	end = clock();

	duration = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << "Time: " << duration;
	delete a;
	return 0;
}
