#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

class complex{
private: 
   float real, image;
public: 
   complex(float=0, float=0);
   complex(complex &);
   void display();
   operator float() {
      cout << "goi float\n";
      return real;
   }
};

complex::complex(float realx, float imagex) {
      real = realx; image = imagex;
};

complex::complex(complex &b) {
   cout << "Ham thiet lap sao chep\n";
   real = b.real; image = b.image;
}

void fct(float n) {
   cout <<"Chuyen doi: " << n << "\n";
}

void complex::display() {
   cout << real << (image >= 0 ? " + " : " - ") << abs(image) << "*j\n";
}




int main() {
   complex a(1, 2), b(2,4);
   float n1, n2;
   n1 = a + b; cout << "n1 = " << n1 << "\n";
   n2 = a + 1; cout << "n2 = " << n2 << "\n";
   return 0;
}