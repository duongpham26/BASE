#include "../library/lib.cpp"

void BubbleSort(int a[], int n ) {
   int count = 0;
   for (int i = 0; i < n; ++i) {
      for (int j = n - 1; j > i; --j) {
         if (a[j] < a[j - 1]) {
            swap(a[j], a[j - 1]);
         }
            count++;
      }
   }
   cout << "\nCount1" << count << "\n";
}

void BubbleSort2(int *a, int n) {
   int check = 1;
   int count = 0;
   for(int i = 0; i < n - 1; ++i) {
      if(check == 1) {
         check = 0;
         for(int j = n - 1; j > i; --j) {
            if (a[j] < a[j-1]) {
               swap(a[j], a[j-1]);
               check = 1; // co doi cho
            }
            count++;
         }
      } else break;
   }
   cout << "Count2" << count <<"\n";
}

void BubbleSort3(int *a, int n) {
   int check = 1;
   int m; // nhơ vi tri cuoi dc xep 
   int count = 0;
   for(int i = 0; i < n - 1; ++i) {
      if(check == 1) {
         check = 0;
         for(int j = n - 1; j > i; --j) {
            if (a[j] < a[j-1]) {
               swap(a[j], a[j-1]);
               check = 1; // co doi cho
               m = j;
            }
            count++;
         }
         i = m - 1;
      } else break;
   }
   cout << "Count3" << count <<"\n";
}



int main() {
   const int n = 10;
   int a[n] = {1,4,2,0,3,6,5,7,9,8};
   // randArray(a, n, 0, 100);
   BubbleSort2(a, n);

   int b[n] = {1,4,2,0,3,6,5,7,9,8};
   BubbleSort(b,n);

   int c[n] = {0,1,2,4,3,6,5,7,9,8};
   BubbleSort3(c,n);
   printArray(c,n);
   return 0;
}