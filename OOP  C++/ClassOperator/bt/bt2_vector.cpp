#include <iostream>
using namespace std;

class vector
{
	int n;
	int *v;
public:
	//vector();
	//vector(int n);
	//vector(int n, int *a);
	void display();
	friend ostream& operator<<(ostream &os, vector &a);
	friend istream& operator>>(istream &is, vector &a);
	~vector()
	{
		delete v;
	}
};

//vector::vector()
//{
//	cout << "Nhap so chieu n : "; cin >> n;
//	v = new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		cout << "Nhap phan tu thu " << i + 1 << " : "; cin >> v[i];
//	}
//}

void vector::display()
{
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << endl;
}

ostream& operator<<(ostream &os, vector &a)
{
	for (int i = 0; i < a.n; i++)
		os << a.v[i] << " ";
	os << endl;
	return os;
}


istream& operator>>(istream &is, vector &a)
{
	cout << "Nhap so chieu n : "; is >> a.n;
	a.v = new int[a.n];
	for (int i = 0; i < a.n; i++)
	{
		cout << "Nhap phan tu thu " << i + 1 << " : "; is >> a.v[i];
	}
	return is;
}

int main()
{
	vector v1;
	cin >> v1;
	cout << v1;
	return 0;
}