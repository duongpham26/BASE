#include <iostream>
#include <conio.h>

class counter{
   static int count;
public:
   counter();
   static void display();
   ~counter();
};

//init count
int counter::count = 0;

void counter::display() {
   std::cout << "Hien dang co " << count << " doi tuong.\n";
}

counter::counter() {
   std::cout << "++Tao, co " << ++count << " doi tuong.\n";
}

counter::~counter() {
   std::cout << "--Xoa, con " << --count << " doi tuong.\n";
}

void fct();

int main() {
   fct();
   counter::display();
   counter a, b, c;
   return 0;
}

void fct() {
   counter e, f;
}