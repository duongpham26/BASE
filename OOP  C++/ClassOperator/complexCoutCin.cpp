#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

class complex  {
public:
   float real, image;
   friend ostream &operator<<(ostream &o, complex &b);
   friend istream &operator>>(istream &i, complex &b);
};

ostream &operator<<(ostream &o, complex &b) {
   o << b.real << (b.image >= 0 ? " + ":" - ") <<"j*"<<abs(b.image) << "\n";
   return o;
};

istream &operator>>(istream &i, complex &b) {
   cout << "Nhap phan thuc: ";
   i >> b.real;
   cout << "Nhap phan ao: ";
   i >> b.image;
   return i;
};

int main() {
   complex a;
   cin >> a;;
   cout << a;

   return 0;
}