#include <iostream>
#include <conio.h>

class point {
      int x, y;
   public: 
      void init ();
      void init (int);
      void init (int, int);
      void display ();
      void display (char*);
};

void point::init () {
   x = y = 0;
}

void point::init(int a) {
   x = a; y = 0;
}

void point::init(int a, int b) {
   x = a ; y = b;
}

void point::display () {
   std::cout << "Toa do: " << x << " " << y << "\n";
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