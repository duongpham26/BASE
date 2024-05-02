#include <iostream>
#include <conio.h>

class matrix;
class vector{
private:
   float v[3];
public:
   vector(float v1 = 0, float v2 = 0, float v3 = 0) {
      v[0] = v1; v[1] = v2; v[2] = v3;
   }
   void display();
   friend vector prop(matrix, vector);
};

void vector::display() {
   for(int i =0; i < 3; ++i) {
      std::cout << v[i] << " ";
   }
}

class matrix {
   float mat[3][3];
public:
   matrix(float matx[3][3]) {
      for(int i = 0; i < 3; i++) {
         for(int j = 0; j < 3; j++)  {
            mat[i][j] = matx[i][j];   
         }
      }
   }
   friend vector prop(matrix, vector);
};

vector prop(matrix m, vector x) {
   int i, j;
   float sum = 0;
   vector res;
   for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
         sum += m.mat[i][j] * x.v[j]; 
      }
         res.v[i] = sum;
   }
   return res;
}


int main() {
   vector v1(1,2,3);
   vector results;
   float matrix1[3][3] = {1,2,3,4,5,6,7,8,9};
   matrix m1(matrix1);
   results = prop(m1, v1);
   results.display();


   return 0;
}