#include <iostream>
#include <conio.h>

class test{
public:
   int num;
   test(int);
   ~test();
};

test::test(int i) {
   num = i;
   std::cout << "++ Goi ham thiet lao coi num = " << num << "\n";
}

test::~test() {
   std::cout << "--Huy ham thiet lap voi num = " << num << "\n";
}



int main() {
   void fct(int);
   test t1(1);
   for (int i = 0; i < 2; ++i) {
      fct(i);
   }
   return 0;
}

void fct(int p) {
   test t(2*p);

}