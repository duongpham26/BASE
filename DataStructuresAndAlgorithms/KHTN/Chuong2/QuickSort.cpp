#include "./../library/lib.cpp"

// int partition(int arr[], int low, int high)
// {
//    int pivot = arr[high];
//    int i = (low - 1);

//    for (int j = low; j <= high; j++)
//    {
//       if (arr[j] < pivot)
//       {
//          i++;
//          swap(arr[i], arr[j]);
//       }
//    }
//    swap(arr[i + 1], arr[high]);
//    return (i + 1);
// }

int partition(int arr[], int low, int high) {
   int i = low;
   int j = high + 1;
   int p = arr[low];
   do {
      do i++; while(arr[i] < p);
      do j--; while(arr[i] > p);
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
   int arr[] = {10, 7, 8, 9, 1, 5};
   int n = sizeof(arr) / sizeof(arr[0]);
   // Function call
   quickSort(arr, 0, n - 1);
   // Print the sorted array
   cout << "Sorted Array\n";
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
   return 0;
}
// This Code is Contributed By Diwakar Jha
