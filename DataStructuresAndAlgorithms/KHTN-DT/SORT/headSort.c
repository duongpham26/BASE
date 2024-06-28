
#include <stdio.h>
#include <conio.h>
#include "./../library/lib.h"

void swap(int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

void headify(int *a, int n, int node) {
   int largest, left, right;
   largest = node;
   left = 2*node + 1;
   right = 2*node + 2;

   if(left < n && a[left] > a[largest]) {
      largest = left;
   }
   if(right < n && a[right] > a[largest]) {
      largest = right;
   }
   if(largest != node) {
      swap(&a[node], &a[largest]);
      headify(a, n, largest);
   }
}

void headSort(int *a, int n) {
   for(int i = n/2 - 1; i >= 0;--i) {
      headify(a, n, i);
   }
   for(int i = n - 1; i >= 0; i--) {
      swap(&a[0], &a[i]);
      headify(a, i, 0);
   }
}

void heapifyMin(int arr[], int n, int i)
{
    int smallest = i; // Initialize smallest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is smaller than root
    if (l < n && arr[l] < arr[smallest])
        smallest = l;
 
    // If right child is smaller than smallest so far
    if (r < n && arr[r] < arr[smallest])
        smallest = r;
 
    // If smallest is not root
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
 
        // Recursively heapifyMin the affected sub-tree
        heapifyMin(arr, n, smallest);
    }
}
 
// main function to do heap sort
void heapSortMin(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);
 
        // call min heapifyMin on the reduced heap
        heapifyMin(arr, i, 0);
    }
}

int main() {
   int arr[100];
   int n = sizeof(arr)/sizeof(arr[0]);
   randArray(arr, n, 0, 50);
   printArray(arr, n);
   headSort(arr, n);
   printArray(arr, n);
   heapSortMin(arr, n);
   printArray(arr, n);
   return 0;
}