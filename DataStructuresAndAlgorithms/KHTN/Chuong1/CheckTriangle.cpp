#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

struct point {
   int x, y;
};

struct straight {
   point p1, p2;
   float lenght;
};

int main() {   
   straight s[3];
   for(int i = 0; i < 3; i++) {
      cout << "input triangle " << i + 1 <<" with point 1 has x coordinate: "; cin >> s[i].p1.x;
      cout << "input triangle " << i + 1 <<" with point 1 has y coordinate: "; cin >> s[i].p1.y;
      cout << "input triangle " << i + 1 <<" with point 2 has x coordinate: "; cin >> s[i].p2.x;
      cout << "input triangle " << i + 1 <<" with point 2 has y coordinate: "; cin >> s[i].p2.y;
      s[i].lenght = sqrt((s[i].p2.x-s[i].p1.x)^2 + (s[i].p2.y-s[i].p1.y)^2);
   }
   for(int i = 0; i < 3; i++) {
      if(s[i].lenght + s[(i+1)%3].lenght <= s[(i+2)%3].lenght) {
         cout << "Not a triangle.\n";
         break;
      }
   }
}