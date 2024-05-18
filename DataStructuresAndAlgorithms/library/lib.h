#ifndef lib_h
#define iib_h

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printArray(int *arr, int N);
void randArray(int *arr, int N, int min, int max);

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


#endif