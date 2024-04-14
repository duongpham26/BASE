
#include <iostream>
#include <conio.h>

// double text(u, v); //Khong cho phep
int u;
int v;

// Chuyen doi kieu du lieu
double typedata(int a, double b) {
	std::cout << sizeof(a) << "\n" << sizeof(b);
	return b;
};

int trave(int a, float b) {
	std::cout << a;
	return a;
}

void swap(int &a, int &b) {
	int tempt = a;
	a = b;
	b = tempt;
}

//tham chieu den bien con tro
void pointReference(int* &a) {

	*a = 2;
	std::cout << *a;
}
//bien tham chieu
int x = 1;
int &p = x;


int &fr(int d[], int i);
int &fr2(int &a);

// tham so co gia tri ngam dinh
void ngamdinh(int a = 1, int b = 2) {
   std::cout << a << " - " << b;
}
int main() {
	int a = 1;
	char c;
	float b;
	double res1, res2, res3;

	// typedata(res1, c);

	// std::cout << sizeof(trave(a, c));

	// std::cin >> a >> c >> b;
	// std::cout << a << c <<b;

	// swap(2,3); //error

	// int *p = &a;
	// // p = &a; hoac
	// std::cout << p << "\n";
	// std::cout << &p << "\n";
	// pointReference(p);
	// std::cout << a << "\n";
	/*int array[5];
	std::cout << "Nhap vao mang: \n";
	for (int i = 0; i < 5; ++i) {
		std::cin >> fr(array, i);
	}


	for (int i = 0; i < 5; ++i) {
		std::cout << "array[" << i << "] = " << array[i] << "\n";
	}*/
	// int x = 5;
	// std::cout << &x << "\n";
	// fr2(x) = 6;
	// std::cout << &fr2(x);

   ngamdinh(3);


	return 0;
}

int &fr(int d[], int i) {
	return d[i];
}

int &fr2(int &a) {
	return a;
}

