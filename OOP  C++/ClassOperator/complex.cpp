#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

class complex{
private: 
   float real, image;
public: 
   complex(float=0, float=0);
   void display();
   complex operator+(complex);
   friend complex operator+(float,complex);
};

complex::complex(float realx, float imagex) {
      real = realx; image = imagex;
   };

void complex::display() {
   cout << real << (image >= 0 ? " + " : " - ") << abs(image) << "*j\n";
}

complex complex::operator+(complex b) {
   complex c;
   c.real = real + b.real; 
   c.image = image + b.image; 
   return c;
}

complex operator+(float a, complex b) {
   complex c;
   c.real = a + b.real;
   c.image = b.image;
   return c;
}

int main() {
   complex c1(1,-1), c2(1, 1), c3;
   c3 = c1 + c2;
   c3.display();

   c3 = 3 + c2 + c1;
   c3.display();
   return 0;
}