#include <iostream>
using namespace std;

// recursion
int factorial(int n) {
	cout << n << endl;
	if (n == 1 || n == 0) return 1;
	return n * factorial(n - 1);
}

int fibonacci(int n) {
	if (n == 1 || n == 0) return n;
	return fibonacci(n - 2) + fibonacci(n - 1);
	
}

// backtracking
const int N_bit = 3;
int ar[100];
void binaryString(int bit) {
	for (int i = 0; i <= 1; i++) {
		ar[bit] = i;
		if (bit == N_bit) {
			for (int j = 1; j <= N_bit; j++) {
				cout << ar[j];
			}
			cout << endl;
		} else binaryString(bit + 1);
	}
}

void HoanVi(int bit) {
	for (int i = 1; i <= N_bit; i++) {
		ar[bit] = i;
		if (bit == N_bit) {
			for (int j = 1; j <= N_bit; j++) {
				cout << ar[j];
			}
			cout << endl;
		}
		else HoanVi(bit + 1);
	}
}


// problem 1
void towerOfHaNoi(int n, char source, char destination, char aux) {
	if (n == 1) {
		cout << "1 From " << source << " to " << destination << endl;
		return;
	}
	towerOfHaNoi(n - 1, source, aux, destination);
	cout << n <<" From " << source << " to " << destination << endl;
	towerOfHaNoi(n - 1, aux, destination, source);
}

// problem 2
int isArraySortedOrder(int *a, int n) {
	if (n == 1) return 1;
	if (a[n] > a[n - 1]) {
		isArraySortedOrder(a, n - 1);
	}
	else {
		return 0;
	}
}
int main() {
	// cout << factorial(3) << endl;
	//towerOfHaNoi(5, 'A', 'C', 'B');
	/*for (int i = 1; i <= 10; i++)
	{
		cout << fibonacci(i) << " ";
	}
	int a[] = { 2, 3, 4, 9, 6, 7, 8, 9 };*/
	//cout << isArraySortedOrder(a, 7) << endl;

	HoanVi(1);

	return 0;
}