#include <iostream>
using namespace std;

struct element
{
	element *next;
	void *content;
};

class mere
{
public:
	virtual void display() = 0;
};

class point: public mere
{
	int x, y;
public:
	point(int abs = 0, int ord = 0)
	{
		x = abs;
		y = ord;
	}
	void display()
	{
		cout << "Toa do: " << x << " " << y << endl;
	}
};

class complex: public mere
{
	double real, image;
public:

	complex(double r = 0, double i = 0) { real = r; image = i; }
	void display()
	{
		cout << "So phuc: " << real << (image < 0 ? "" : "+") << image << "j" << endl;
	}
};

class list
{
	element *head;
	element *current;
public:
	list()
	{
		head = NULL; current = head;
	};
	~list();
	void add(void *);
	void first() { current = head; }
	void *nextelement()
	{
		void *adel = NULL;
		if (current != NULL)
		{
			adel = current->content;
			current = current->next;
		}
		return adel;
	}
	void display_list();
	int last() { return (current == NULL); }
};

list::~list()
{
	element *suiv;
	current = head;
	while (current != NULL)
	{
		suiv = current->next;
		delete current;
		current = suiv;
	}
}

void list::add(void *chose)
{
	element *adel = new element;
	adel->next = head;
	adel->content = chose;
	head = adel;
}

void list::display_list()
{
	mere *prt;
	first();
	while (!last())
	{
		prt = (mere *)nextelement();
		prt->display();
	}
}




int main()
{
	list l;
	point p1(1, 1), p2(2, 2);
	complex c1(1, 1), c2(2, 2);

	l.add(&p1);
	l.add(&p2);

	l.add(&c1);
	l.add(&c2);
	l.display_list();

	return 0;
}