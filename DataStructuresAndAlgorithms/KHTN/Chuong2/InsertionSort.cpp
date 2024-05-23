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

void insertionSort2_sentinel(int *a, int n) {
   int i, j , v;
   for(i = 1; i <= n; ++i) {
      v = a[i]; j = i - 1;
      a[-1] = v;
      while(v < a[j]) {
         a[j+1] = a[j];
         j--;
      }
      a[j+1] = v;
   }
}

void BinaryInsertionSort3(int *a, int n) {
   int i, j, v;
   int mid, left, right;
   for(i = 1; i < n; ++i) {
      v = a[i]; 
      a[-1] = v;
      left = 0; right = i - 1;
      while(left <= right) {
         mid = (left + right) / 2;
         cout << "Mid: "  << mid << "\n";
         if(v < a[mid]) right = mid - 1;
         else left = mid + 1;
      }
      for(j = i - 1; j >= left; j--) {
         a[j+1] = a[j];
      }
      a[left] = v;
   }
}

int main() {
   const int n = 5;
   int a[n] = {1,19,20,21,18};

   // randArray(a, n, 1, 10);

   BinaryInsertionSort3(a,n);
   printArray(a,n);
   return 0;
}