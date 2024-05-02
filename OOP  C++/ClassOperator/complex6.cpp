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
   operator float() {
      return real;
   }
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
   complex a(1, 2);

   float x = a;
   cout << a;
   return 0;
}