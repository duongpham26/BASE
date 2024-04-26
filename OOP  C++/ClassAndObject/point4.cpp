#include <iostream>
#include <conio.h>

class point {
      int x, y;
      int *a;
   public: 
      void init (int=0, int=0);
      void display ();
      void display (char*);
      void concide (point pt);
      void concide (point *pt);
      // void concide (point &pt);
      point symetry ();
};

void point::init (int a, int b) {
   x = a ; y = b;
}

void point::display () {
   std:: cout << "Dia chi: " << this <<"\n";
   std::cout << "Toa do: " << x << " " << y << "\n";
}

void point::display (char *message) {
   std::cout << message;
   display();
}

void point::concide(point pt) {
   std:: cout << "Dia chi pt: " << this <<"\n";
   std::cout << "Toa do pt: " << pt.x << " " << pt.y << "\n";
}

void point::concide(point *pt) {
   std::cout << "Toa do pt: " << pt->x << " " << pt->y << "\n";
}

// void point::concide(point &pt) {
//    std::cout << "Toa do pt: " << pt.x << " " << pt.y << "\n";
// }

point point::symetry () {
   point res;
   res.x = -x;
   res.y = -y;
   return res;
}

int main() {
   // point p;
   // p.init(2, 4);
   // point p3;
   // p3.init(3, 4);

   // point p2;
   // p2.init(9, 2);
   // p2.display();
   // p2.concide(p);
   // p2.concide(&p3);

   // point p4;
   // p4 = p2.symetry();
   // p4.display();

   return 0;
}