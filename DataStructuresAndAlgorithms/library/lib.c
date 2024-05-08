#include "lib.h"

void printArray(int *arr, int N) {
   for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
   printf("\n");
}

void randArray(int *arr, int N, int min, int max) {
   for(int i = 0; i < N; ++i) {
      arr[i] = rand() % (max - min + 1) + min;
   }
}