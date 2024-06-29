// try.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


void pointer(int *&c)
{
	cout << "Adress " << &c << endl;
	int x = 3;
	int *p2 = &x;
	c = p2;
}

void array1(int *a) {
	cout << a << endl;
}

int fibonacci(int n) {
	if (n < 0) return -1;
	if (n == 1 || n == 0) return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
	int a[5];
	a[0] = 1;

	cout << a << endl;
	array1(a);
}


