#include <iostream>
#include <conio.h>

class point {
      int x, y;
   public: 
      void init (int=0, int=0);
      void display (char* = " ");
};

void point::init(int a, int b) {
   x = a ; y = b;
}

void point::display(char *message) {
   std::cout << message;
   display();
}

int main() {
   point p;
   p.init(2, 4);
   p.display("Point p-");
   return 0;
}