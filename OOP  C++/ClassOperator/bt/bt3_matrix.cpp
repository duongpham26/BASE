#include <iostream>
using namespace std;
class matrix;
class vector 
{
	int n;
	float *a;
public:
	vector();
	vector(int);
	void display();
	float &operator[](int);
	friend class matrix;
	//~vector();
};

class matrix
{
	int n;
	vector *m;
public:
	matrix(int, int);
	void display();
	vector &operator[](int i);
	~matrix();
};

vector::vector()
{
	n = 0;
	a = nullptr;
}

vector::vector(int size)
{
	n = size;
	a = new float[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i + 1 << " : "; cin >> a[i];
	}
}

void vector::display()
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

float &vector::operator[](int i) 
{
	return a[i];
}

//
//vector::~vector()
//{ 
//	cout << "Goi ham huy" << endl;
//	delete[] a;
//}

matrix::matrix(int row, int col)
{
	n = row ;
	m = new vector[n];
	for (int i = 0; i < n; i++)
	{
		m[i] = vector(col);
	}
}

void matrix::display()
{
	for(int i = 0; i < n; i++)
	{
		m[i].display();
	}
}

vector &matrix::operator[](int i)
{
	return m[i];
}


matrix::~matrix()
{
	cout << "Goi ham huy bo matrix" << endl;
	delete[] m;
}

int main()
{
	matrix m1(2, 2);
	cout <<"m1: " << m1[1][0] << endl;
	m1.display();
	return 0;
}