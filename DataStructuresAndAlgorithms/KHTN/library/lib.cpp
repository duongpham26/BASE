#include <iostream>
#include <conio.h>
#include <time.h>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <stdlib.h>
#include <iomanip>
using namespace std;

void swap(int &a, int &b);
void printArray(int *arr, int N);
void swap(int &a, int &b);
void CopyArray(int *a, int *b);

void swap(int &a, int &b) {
   int temp = a;
   a = b;
   b = temp;
}

void printArray(int *arr, int N) {
   for (int i = 0; i < N; i++)
      cout << arr[i] << " ";
   printf("\n");
}

void randArray(int *arr, int N, int min, int max) {
   srand ( time(NULL) );
   for(int i = 0; i < N; ++i) {
      arr[i] = rand() % (max - min + 1) + min;
   }
}

void CopyArray(int *a, int *b, const int n) {
   for(int i = 0; i < n; ++i) {
      b[i] = a[i];
   }
}

int checkSort(int *a, int n) {
   for(int i = 1; i < n; i++) {
      if(a[i] < a[i-1]) return i;
   }
   return -1;
}



