#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

class phanso {
	int tu, mau;
public:
	phanso(int t = 0, int m = 1) {
		tu = t;
		mau = m;
		
	}
	void RutGon();
	phanso add(phanso);
	phanso sub(phanso);
	phanso prod(phanso);
	phanso div(phanso);
	void InPhanSo();
	void InThapPhap();
};

 void phanso::RutGon() {
	int temp;
	int a = abs(tu);
	int b = abs(mau);
	while (b != 0) {
		temp = b;
		b = a % b;
		a = temp;
	}
	mau /= a;
	tu /= a;
	if (mau < 0) {
		mau = -mau;
		tu = -tu;
	}
}

phanso phanso::add(phanso p) {
	phanso result;
	result.mau = mau * p.mau;
	result.tu = tu * p.mau + p.tu * mau;
	result.RutGon();
	return result;
}

phanso phanso::sub(phanso p) {
	phanso result;
	result.mau = mau * p.mau;
	result.tu = tu * p.mau - p.tu * mau;
	result.RutGon();
	return result;
}

phanso phanso::prod(phanso p) {
	phanso result;
	result.mau = mau * p.mau;
	result.tu = tu * p.tu;
	result.RutGon();
	return result;
}

phanso phanso::div(phanso p) {
	phanso result;
	result.mau = mau * p.tu;
	result.tu = tu * p.mau;
	result.RutGon();
	return result;
}

void phanso::InPhanSo() {
	cout << tu << "/" << mau << endl;
}

void phanso::InThapPhap() {
	cout << float(tu / mau) << endl;
}

int main() {
	phanso p1(-1, 2), p2(1, 2);
	phanso result = p1.add(p2);
	result.InPhanSo();
	result.InThapPhap();
	 result = p1.sub(p2);
	result.InPhanSo();
	result.InThapPhap();
	 result = p1.div(p2);
	result.InPhanSo();
	result.InThapPhap();
	 result = p1.prod(p2);
	result.InPhanSo();
	result.InThapPhap();
	return 0;
}