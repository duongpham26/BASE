#include <iostream>
#include <conio.h>

class point {
      int x, y;
   public:
      // point () {x = 0; y = 0;} // kh con error 
      
      point (int ox = 1, int oy = 0) {
         std::cout << "\nTạo đối tượng tại: " << this << "\n";
         x = ox; y =oy;
      }
      point(point &p) {
         std::cout << "\nTạo đối tượng sao chep tại: " << this << "\n";
         // std::cout << "\nTạo đối tượng sao chep tại: " << &p << "\n";
         x = p.x;
         y = p.y;
      }
      void move (int, int);
      void display();
};

void point::move (int dx, int dy) {
   std::cout << "\nMove doi tuong tai :"  << this << "\n";
   x += dx; y +=dy;
}

void point::display () {
   std::cout << "\nDisplay doi tuong tai:"  << this << "\n";
   std::cout << "Toa do: " << x << " " << y << "\n";
}

point fct(point a) {
   point b = a;
   b.move(2,3);
   return b;
}

int main () {
   point a(1,2);
   a.display();

   // std::cout << "1\n";
   // point b(a);
   // b.display();

   point b = fct(a);
   b.display();
   
   return 0;
}