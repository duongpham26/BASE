#include "./../library/lib.cpp"

int partition(int arr[], int low, int high) {
   int i = low;
   int j = high + 1;
   int p = arr[low];
   do {
      do i++; while(arr[i] < p);
      do j--; while(arr[j] > p);
      swap(arr[i], arr[j]);
   } while (i < j);
   swap(arr[i], arr[j]);
   swap(arr[low], arr[j]);
   return j;
}

void quickSort(int arr[], int low, int high)
{
   if (low < high)
   {
      int pi = partition(arr, low, high);
      quickSort(arr, low, pi - 1);
      quickSort(arr, pi + 1, high);
   }
}

int main()
{
   const int n = 100000;
   int arr[n];
   randArray(arr, n, 0, 1000000);
   // Function call
   quickSort(arr, 0, n-1);
   // Print the sorted array
   cout << "Sorted Array\n";
   printArray(arr, n);
   cout << "Check: " << checkSort(arr, n) << "\n";
  
}
