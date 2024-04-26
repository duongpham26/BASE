#include <iostream>
#include <conio.h>

class point {
      int x, y;
   public:
      point (int ox, int oy) {
         x = ox; y =oy;
      }
      void move (int, int);
      void display();
};

void point::move (int dx, int dy) {
   x += dx; y +=dy;
}

void point::display () {
   std::cout << "Toa do: " << x << " " << y << "\n";
}

int main () {
   point  p1(1,2);
   p1.display();
   p1.move(1,2);
   p1.display();
   
   return 0;
}