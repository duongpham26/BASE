#include <iostream>
using namespace std;

struct element
{
	element *next;
	void *content;
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

class point
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

class listpoint:public list, public point
{
public:
	listpoint() {};
	void display();
};

void listpoint::display()
{
	first();
	while (!last())
	{
		point *prt = (point *)nextelement();
		prt->display();
	}
}

int main()
{
	listpoint l;
	point p1(1, 1), p2(2, 2), p3(3,3);
	l.add(&p1);
	l.add(&p2);
	l.add(&p3);
	l.display();
	return 0;
}