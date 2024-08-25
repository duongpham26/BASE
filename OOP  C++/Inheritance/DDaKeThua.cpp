#include <iostream>
using namespace std;

class O
{
	float z;
public:
	O(float oz) 
	{
		z = oz;
		cout << "Goi O" << endl;
	}
};

class A: public O
{
	float x, y;
public:
	A(float ox, float oy, float oz):O(oz) { x = ox; y = oy; cout << "Goi A" << endl; }
	float getx() { return x; }
	float gety() { return y; }
};

class B : virtual public A 
{
public:
	B(float ox, float oy, float oz) :A(ox, oy, oz) {
		cout << "Goi ham thiet lap B" << endl;
	}
};

class C : virtual public A
{
public:
	C(float ox, float oy, float oz) :A(ox, oy, oz) {
		cout << "Goi ham thiet lap C" << endl;
	}
};

class D :public B, public C
{
public:
	D(float ox, float oy, float oz) : A(ox, oy, oz), B(ox, oy, oz), C(ox, oy, oz)
	{
		cout << "Goi ham thiet lap D" << endl;
	}
};

int main()
{
	D d(5, 5, 6);
	return 0;
}