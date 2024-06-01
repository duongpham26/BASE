#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS

void Swap(int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

void SelectionSort (int a[], int n) {
   int min;
   for (int i = 0; i < n-1; ++i) {
      min = i;
      for (int j = i + 1; j < n; ++j) {
         if (a[j] < a[min]) min = j;
      }
      if (min != i) Swap(&a[min], &a[i]);
   }
}

void binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
 
		if (arr[m] == x) {
			printf("%d ", m);
		}
 
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
}

void docFile(int array[], int *N) {
	int a;
	FILE *f;
	f = fopen("D:/VisualStudio/duongp375/songuyen.txt", "r");
	if (f == NULL) {
		printf("\nLoi moi file de doc!");
		return;
	}
	printf("\nBan doc tu file thanh cong!");
	fscanf(f, "%d\n", &N);
	printf("\n N = %d", *N);
	
	fclose(f);
} 

int main() {
	int N, a;
	int array[1000];
	FILE *f;
    f = fopen("D:/VisualStudio/duongp375/songuyen.txt", "w");
	if(f == NULL){
        printf("Cannot open file !\n");
    }
	
	printf("\nNhap N (N>=2 && N <=1000): ");
	scanf("%d", &N);
	fprintf(f, "%d\n", N);
	for (int i = 0; i < N; ++i) {
		a = rand() % 10 + 1;
		fprintf(f, "%d ", a);
	}
	printf("\nBan da ghi vao file thanh cong!");
	fclose(f);
	docFile(array, &N);

	int k;
	int co = 0;
	printf("\nNhap k: ");
	scanf("%d", &k);
	printf("\nVi tri k: ");
	for (int i = 0; i < N; ++i) {
		if (k == array[i]) {
			printf("%d ", i); 
			if (f == 0) co=1;
		}
	}
	
	printf("\nTim vi tri theo binarSearch: ");
	SelectionSort(array, N);
	binarySearch(array, 0, N-1, k);
	if (co == 1) printf("Khong tim thay k!");

	_getch();
	return 0;
}
