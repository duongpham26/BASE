#include <iostream>
#include <conio.h>

class point
{
private:
	int x, y;
	struct pointx
	{
		int a;
		char b;
	} pp;

public:
	void init(int ox, int oy);
	void move(int dx,  int dy);
	void stru() {
		pp.a = 2;
		pp.b = 'A';
	}
	void displaystr() {
		std::cout << "struct: " << pp.a << " " << int(pp.b);
	}
	void display();

};

void point::init(int ox, int oy) {
	std::cout << "Ham thanh phan init\n";
	x = ox; y = oy;
}

void point::move(int dx, int dy) {
	std::cout << "Ham thanh pham move\n";
	x += dx; y += dy;
}

void point::display() {
	std::cout << "Ham thanh phan display\n";
	std::cout << "Toa do: " << x << " " << y << "\n";
}

int main() {
	point p;
	/*p.init(2, 2);
	p.move(1, 2);
	p.display();*/

	p.stru();
	p.displaystr();
	_getch();

	return 0;
}