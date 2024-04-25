#include <iostream>
#include <conio.h>

class point {
      int x, y;
   public: 
      void init (int=0, int=0);
      void display ();
      void display (char*);
      void concide (point pt);
      void concide (point *pt);
      // void concide (point &pt);
};

void point::init (int a, int b) {
   x = a ; y = b;
}

void point::display () {
   std::cout << "Toa do: " << x << " " << y << "\n";
}

void point::display (char *message) {
   std::cout << message;
   display();
}

void point::concide(point pt) {
   std::cout << "Toa do pt: " << pt.x << " " << pt.y << "\n";
}

void point::concide(point *pt) {
   std::cout << "Toa do pt: " << pt->x << " " << pt->y << "\n";
}

// void point::concide(point &pt) {
//    std::cout << "Toa do pt: " << pt.x << " " << pt.y << "\n";
// }

int main() {
   point p;
   p.init(2, 4);
   point p3;
   p3.init(3, 4);

   point p2;
   p2.init(9, 2);
   p2.display();
   p2.concide(p);
   p2.concide(&p3);

   return 0;
}