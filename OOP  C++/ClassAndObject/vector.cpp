#include <iostream>
#include <conio.h>

class vector{
private:
   int n;
   float *v;
public:
   vector();
   vector(int size);
   vector(int size, float *a);
   vector(const vector &);
   void display();
   ~vector();
};

vector::vector() {
   std::cout << "Su dung ham thiet lap 0 tham so" << "\n";
   std::cout << "Nhap n = "; std::cin >> n;
   v = new float [n];
   for(int i = 0; i < n; ++i) {
      std::cout << "Nhap v[" << i << "] = "; std::cin >> v[i];
   }
}

vector::vector(int size) {
   std::cout << "Su dung ham thiet lap 1 tham so" << "\n";
   n = size;
   v = new float [n];
   for(int i = 0; i < n; ++i) {
      std::cout << "Nhap v[" << i << "] = "; std::cin >> v[i];
   }
}

vector::vector(int size, float *a) {
   std::cout << "Su dung ham thiet lap 2 tham so" << "\n";
   n = size;
   v = new float [n];
   for(int i = 0; i < n; ++i) {
      v[i] = a[i];
   }
}

vector::vector(const vector &b) {
   std::cout << "\nSu dung ham thiet lap sao chep\n";
   n = b.n;
   v = new float [n];
   for(int i = 0; i < n; ++i) {
      v[i] = b.v[i];
   }
}

void vector::display() {
   std::cout << "Doi tuong tai: " << this << "\n";
   std::cout << " n = " << n << " - ";
   for(int i =0; i < n; ++i) {
      std::cout << v[i] << " ";
   }
}

vector::~vector() {
   std::cout << "\nXoa bo doi tuong tai: " << this << "\n";
   delete v;
}

int main() {
   // vector v1;
   // v1.display();

   float b[] = {1,2,3,9};
   vector v1(4, b);
   v1.display();

   vector v2(v1);
   v2.display();
   return 0;
}