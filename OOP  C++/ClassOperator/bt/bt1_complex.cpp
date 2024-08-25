#include <iostream>

using namespace std;

class complex 
{
	int real, image;
public:
	complex(int r = 0, int i = 0)
	{
		real = r;
		image = i;
	}
	complex &operator+(complex);
	void display();
};

complex &complex::operator+(complex c)
{
	complex result;
	result.real = real + c.real;
	result.image = image + c.image;
	cout << "address: " << &result << endl;
	return result;
}

void complex::display()
{

	cout << "Complex: " << real << (image < 0 ? "-" : "+") << abs(image) << "j" << endl;
}

int main() 
{
	complex c1(-1,-2), c2(1, -3);
	complex c3 = c1 + c2;

	cout << "address c3: " << &c3 << endl;

	c3.display();
	return 0;
}


