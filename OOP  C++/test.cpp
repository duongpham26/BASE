#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

class complex {
   float image, real;
public:
   complex(float i = 0, float r = 0) {
      image = i;
      real = r;
   }
   complex add(complex r1, complex r2);
   complex sub(complex r1, complex r2);
   void display() {
      char c = '+';
      if(image < 0) c = '-';
      cout << "So phuc la: " << real << c << abs(image) << "i" << endl; 
   }
};

complex complex::sub(complex r1, complex r2) {
   complex result;
   result.real = r1.real - r2.real;
   result.image = r1.image - r2.image;
   return result;
}

int main () {
   complex a1(1,1), a2(2,2);
   complex result;
   result = a1.add(a1, a2);
   result.display();

   return 0;
}