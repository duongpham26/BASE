#include <iostream>
#include <conio.h>
#include <math.h>

int loaitg(int, int, int);

class tamgiac {
private:
	float a, b, c;
	int loaitg();
	float dientich();
public: 
	void nhap();
	void in();
};

void tamgiac::nhap() {
	do {
		std::cout << "Nhap a = "; std::cin >> a;
		std::cout << "Nhap b = "; std::cin >> b;
		std::cout << "Nhap c = "; std::cin >> c;
	} while (!(a + b >= c && a + c >= b && b + c >= a));
}

void tamgiac::in() {
	std::cout << "Do dai ba cach la: " << a << " " << b << " " << c << "\n";
	std::cout << "Dien tich tam giac: " << dientich() << "\n";
	switch (loaitg()) {
	case 1: 
		std::cout << "Day la tam giac deu\n";
		break;
	case 2: 
		std::cout << "Day la tam giac vuong can\n";
		break;
	case 3:
		std::cout << "Day la tam giac can\n";
		break;
	case 4: 
		std::cout << "Day la tam giac vuong\n";
		break;
	default: std::cout << "Day la tam giac thuong\n";
	
	}
}

int tamgiac::loaitg() {
	if (a == b || b == c || a == b) {
		if (a == b || c == b) return 1;
		else if (a*a == b * b + c * c|| b * b == a * a + c * c || c * c == b * b + a * a) return 2;
		else return 3;
	} 
	else if (a*a == b * b + c * c || b * b == a * a + c * c || c * c == b * b + a * a) return 4;
	else return 5;
}

float tamgiac::dientich() {
	float px;
	px = (a + b + c) / 2;
	return sqrt(px*(px - a)*(px - b)*(px - c));
}

int loaitg(int a, int b, int c) {
	if (a == b || b == c || a == b) {
		if (a == b || c == b) return 1;
		else if (a*a == b * b + c * c|| b * b == a * a + c * c || c * c == b * b + a * a) return 2;
		else return 3;
	} 
	else if (a*a == b * b + c * c || b * b == a * a + c * c || c * c == b * b + a * a) return 4;
	else return 5;
}

int main() {
	tamgiac tg;
	tg.nhap();
	tg.in();

	_getch();
	return 0;
}