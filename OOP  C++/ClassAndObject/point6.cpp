#include <iostream>
#include <conio.h>

class point {
      int x, y;
   public:
      // point () {x = 0; y = 0;} // kh con error 
   

      point (int ox = 0, int oy = 0) {
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

   point p1(9,2);
   std::cout << "p1 ";
   p1.display();
   point *p2 = &p1;
   std::cout << "p2 ";
   p2->display();
   p2->move(-4,8);
   std::cout << "p1 ";
   p1.display();

   point *ptr;
   ptr = new point;
   std::cout << "prt ";
   ptr->display();
   delete ptr;



   return 0;
}