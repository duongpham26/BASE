#include <iostream>
using namespace std;

class point {
   int x, y;
public:
   point(int xvalue = 0, int yvalue = 0) {
      x = xvalue; y = yvalue;
   }
   friend int concide(point, point);
};

int concide(point a, point b) {
   if((a.x == b.x) && a.y == b.y) return 1;
   return 0;
}

int main() {   
   point a(1,0), b(1);
   if(concide(a,b)); cout << "trung nhau!";
   return 0;
}