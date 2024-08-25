#include <iostream>
using namespace std;

class point
{
	float x, y;
public:
	point() { x = 0; y = 0; };
	point(float ox, float oy) { x = ox; y = oy; };
	point(point &p) { x = p.x; y = p.y; };

	virtual void Identifier()
	{
		cout << "Khong mau" << endl;
	}

	void display()
	{
		cout << "Goi ham point::display()" << endl;
		cout << "Toa do: " << x << " " << y << endl;
		Identifier();
		cout << endl;
	}

	void move(float dx, float dy)
	{
		x += dx;
		y += dy;
	}
	virtual ~point() 
	{
		cout << "~point()" << endl;
	}
};

class colorpoint :public point 
{
	unsigned int color;
public:
	colorpoint() { color = 0; };
	colorpoint(float ox, float oy, unsigned int c) :point(ox, oy) { color = c; };
	colorpoint(colorpoint &b) :point((point &)b) { color = b.color; };

	void Identifier()
	{
		cout << "Mau Identifier: " << color << endl;
	}

	~colorpoint()
	{
		cout << "~colorpoint" << endl;
	}
};

class threedimpoint : public point
{
	float z;
public:
	threedimpoint() { z = 0; };
	threedimpoint(float ox, float oy, float oz) : point(ox, oy) { z = oz; };
	threedimpoint(threedimpoint &p) : point(p) { z = p.z; };
	
	virtual void Identifier()
	{
		cout << "Toa do z: " << z << endl;
	}

	void display()
	{
		cout << "display cua threedimpoint" << endl;
		Identifier();
		cout << endl;
	}	
};

class colorthreedimpoint :public threedimpoint
{
	unsigned int color;
public:
	colorthreedimpoint() { color = 0; };
	colorthreedimpoint(float ox, float oy, float oz, unsigned c) : threedimpoint(ox, oy, oz)
	{
		color = c;
	}
	colorthreedimpoint(colorthreedimpoint &p) : threedimpoint(p)
	{
		color = p.color;
	}

	void Identifier()
	{
		cout << "Diem mau: " << color << endl;
	}
};

int main()
{
	//point p(1, 2);
	//p.display();

	/*colorpoint pc(4, 2, 3);
	pc.display();*/

	point *p = new point(1, 2);
	point *pc = new colorpoint(1, 2, 3);

	delete pc;

	return 0;
}