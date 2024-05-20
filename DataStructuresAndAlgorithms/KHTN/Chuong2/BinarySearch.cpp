// #include "../library/lib.cpp"
#include "./HeadSort.cpp"
#include <time.h>


int BinarySearch(int *a, int n, int x) {
   int left = 0;
   int right = n - 1;
   int mid;
   while(left < right) {
      mid = (left  + right) /2;
      if (x == a[mid]) {
         return mid;
      } else {
         if (x < a[mid]) right = mid - 1;
         else left = mid + 1;
      }
   }
   return -1;
}

int InterpolationSearch(int *a, int n, int x) {
   int left = 0;
   int right = n - 1;
   int mid;
   while(left < right) {
      mid = (((x-a[left]) * (right - left)) / (a[right] - a[left])) + left;
      if (x == a[mid]) {
         return mid;
      } else {
         if (x < a[mid]) right = mid - 1;
         else left = mid + 1;
      }
   }
   return -1;
}


int main() {
   clock_t start, end;
   double duration;
   

   const int n = 1000000;
   int array[n];
   int array2[n];
   randArray(array, n, 1, 1000000);
   

   start = clock();
   headSort(array, n);
   CopyArray(array, array2, n);
   int index = BinarySearch(array, n, 5);
   end = clock();

   duration = ((double) (end - start)) / CLOCKS_PER_SEC;
   cout << "Vi tri: " << duration << "\n";
   cout << 0.0000000000000001 << "\n";


   cout << "Vitri: " << InterpolationSearch(array, n, 5) << "\n";
   // printArray(array,n);
   return 0;
}