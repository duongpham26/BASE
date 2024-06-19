#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> 
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

void countingSort(int *a, int size) {
	int *count = new int[size](); // mảng count có size phần tử 0
	int *b = new int[size];
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (a[j] < a[i]) count[i]++;
			else count[j]++;
		}
	}
	for (int i = 0; i < size; i++) {
		b[count[i]] = a[i];
	}
	for (int i = 0; i < size; i++) {
		a[i] = b[i];
	}
	delete count;
	delete b;
}

void countingSortUpgrade(int *a, int size) {
	int *f = new int[size]();
	int *b = new int[size];

	for (int i = 0; i < size; i++) {
		f[a[i]]++;
	}
	for (int i = 1; i < size; i++) {
		f[i] = f[i - 1] + f[i];
	}
	for (int i = size - 1; i >= 0; i--) {
		b[f[a[i]]- 1] = a[i];
		f[a[i]]--;
	}
	for (int i = 0; i < size; i++) {
		a[i] = b[i];
	}
	delete b;
	delete f;
}

int main() {
	//srand(time(0));
	clock_t start, end;
	double duration;
	const int n = 100000;
	int *a = new int[n];
	randomArray(a, n);
	start = clock();
	countingSort(a, n);
	//countingSortUpgrade(a, n);
	end = clock();

	//printArray(a, n);
	duration = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << "Time: " << duration;
	delete a;
	return 0;
}

