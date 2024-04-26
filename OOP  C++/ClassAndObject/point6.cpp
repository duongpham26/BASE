#include <iostream>
#include <conio.h>

class point {
      int x, y;
   public:
      point () {x = 0; y = 0;} // kh con error
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
   // point b[10] -> error
   
   point b[10];
   return 0;
}