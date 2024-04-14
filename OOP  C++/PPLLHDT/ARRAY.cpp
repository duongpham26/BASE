#include <iostream>

void NhapMang(int **a, int n);
void InMang(int **a, int n);

int main() {
   const int n = 2;
   int **a;
   a = new int *[n];
   for (int i = 0; i < n; ++i) {
      a[i] = new int [n];
   }
   std::cout << "Nhap mang: \n";
   NhapMang(a,n);
   InMang(a, n);
   for (int i = 0; i < n; ++i) {
      delete(a[i]);
   }
   delete(a);
   return 0;
}

void NhapMang(int **a, int n) {
   int i, j;
   for (i = 0; i < n; ++i) {
      for (j = 0; j < n; ++j) {
         std::cout << "Nhap [" << i << "][" << j << "] = ";
         std::cin >> a[i][j];
      }
   }
}

void InMang(int **a, int n) {
   int i, j;
   for (i = 0; i < n; ++i) {
      for (j = 0; j < n; ++j) {
         std::cout << "Nhap [" << i << "] = " << a[i][j] <<"\n";
      }
   }
}