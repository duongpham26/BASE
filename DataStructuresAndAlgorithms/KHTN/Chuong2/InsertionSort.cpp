#include "../library/lib.cpp"

void InsertionSort1(int *a, int n) {
   int i, j, v;
   for(i = 1; i <= n; ++i) {
      v = a[i]; j = i - 1;
      while(j >= 0 && v < a[j]) {
         a[j+1] = a[j];
         j--;
      }
      a[j+1] = v;
   }
}

int main() {
   const int n = 10;
   int a[n];
   randArray(a, n, 1, 50);

   InsertionSort1(a,n);
   printArray(a,n);
   return 0;
}