#include <iostream>
#include <conio.h>
using namespace std;

class matrix;
class vector{
private:
   static int n;
   float *v;
public:
   vector();
   vector(float *);
   vector(vector &);
   ~vector();
   static int &size(){return n;}
   void display();
   // friend vector prop(matrix &, vector &);
   friend vector operator*(matrix &, vector &);
   friend class matrix;
};

int vector::n = 0;

vector::vector() {
   v = new float [n];
   for(int i = 0; i < n; ++i) {
      std::cout << "Nhap v[" << i << "] = "; std::cin >> v[i];
   }
}

vector::vector(float *a) {
   v = new float [n];
   for(int i = 0; i < n; ++i) {
      v[i] = a[i];
   }
}

vector::vector(vector &b) {
   for(int i = 0; i < n; i++) {
      v[i] = b.v[i];
   }
}

void vector::display() {
   for(int i =0; i < 3; ++i) {
      std::cout << v[i] << " ";
   }
}

vector::~vector() {
   delete v;
}

class matrix {
   static int n;
   vector *m;
public:
   matrix();
   matrix(matrix &);
   ~matrix();
   void display();
   static int &size() {return n;}
   // friend vector prop(matrix &, vector &);
   friend vector operator*(matrix &, vector &);
};

int matrix::n = 0;

matrix::matrix() {
   m = new vector [n];
}

matrix::matrix(matrix &b) {
   m = new vector[n];
   for(int i = 0; i < n; i ++) {
      for(int j = 0; j < n; j++) {
         m[j].v[j] = b.m[i].v[i];
      }
   }
}

matrix::~matrix() {
   delete m;
}

void matrix::display() {
   for (int i = 0; i < n; i++) {
      m[i].display();

   }
}

// vector prop(matrix &m, vector &x) {
//    float *a = new float [vector::size()];
//    int i, j;
//    for(int i = 0; i < matrix::size(); i++) {
//       a[i] = 0;
//       for(int j = 0; i < vector::size(); j++) {
//          a[i] += m.m[i].v[j] * x.v[j]; 
//       }
//    }
//    return vector(a);
// }

vector operator*(matrix &m, vector &x) {
   float *a = new float [vector::size()];
   int i, j;
   for(int i = 0; i < matrix::size(); i++) {
      a[i] = 0;
      for(int j = 0; j < vector::size(); j++) {
         a[i] += m.m[i].v[j] * x.v[j]; 
      }
   }
   return vector(a);
}



int main() {
   int size;
   cout << "Kich thuoc cua vector: "; cin >> size;
   vector::size() = size;
   matrix::size() = size;
   vector a, c;
   a.display();
   matrix b;
   b.display();
   c = b*a;

   c.display();

   return 0;
}