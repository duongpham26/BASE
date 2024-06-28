#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS

void Swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

void SelectionSort(int a[], int n)
{
   int min;
   for (int i = 0; i < n - 1; ++i)
   {
      min = i;
      for (int j = i + 1; j < n; ++j)
      {
         if (a[j] < a[min])
            min = j;
      }
      if (min != i)
         Swap(&a[min], &a[i]);
   }
}

void InsertionSort(int a[], int n, int index)
{
   int pos, x;
   int stop = index;
   index++;
   for (index; index < n; ++index)
   {
      x = a[index], pos = index - 1;
      while (pos >= stop && a[pos] > x)
      {
         a[pos + 1] = a[pos];
         pos--;
      }
      a[pos + 1] = x;
   }
}

int LinearSearch(int a[], int n, int k)
{
   int count = 0, viTri[1000];
   for (int i = 0; i < n; ++i)
   {
      if (a[i] == k)
      {
         viTri[count++] = i;
      }
   }
   if (count > 0)
   {
      printf("\nVi tri cua k la: ");
      for (int i = 0; i < count; ++i)
      {
         printf("%d; ", viTri[i]);
      }
   }
   else
      printf("\nKhong tim thay k trong mang.");
}

void binarySearch(int a[], int N, int k)
{
   int viTri[1000], count = 0;
   int low = 0, high = N - 1, mid;
   while (low <= high)
   {
      mid = (high + low) / 2;
      if (k == a[mid])
      {
         viTri[count++] = mid;
         low = mid - 1;
         high = mid + 1;
         while (k == a[low])
         {
            viTri[count++] = low;
            low--;
         }
         while (k == a[high])
         {
            viTri[count++] = high;
            high++;
         }
         break;
      }
      else
      {
         if (k < a[mid])
         {
            high = mid - 1;
         }
         else
         {
            low = mid + 1;
         }
      }
   }

   if (count > 0)
   {
      printf("\nTim kiem theo binary: ");
      for (int i = 0; i < count; ++i)
      {
         printf("%d; ", viTri[i]);
      }
   }
   else
      printf("\nKhong tim thay k.");
}

void ghiFile(int N)
{
   FILE *f;
   f = fopen("songuyen.txt", "w");
   if (f == NULL)
   {
      printf("Cannot open file !\n");
   }
   fprintf(f, "%d\n", N);
   for (int i = 0; i < N; ++i)
   {
      fprintf(f, "%d ", rand() % 1000 + 1);
   }
   fclose(f);
}

void docFile(int array[], int *N)
{
   int a;
   FILE *f;
   f = fopen("songuyen.txt", "r");
   if (f == NULL)
   {
      printf("\nLoi moi file de doc!");
      return;
   }
   fscanf(f, "%d\n", N);
   for (int i = 0; i < *N; ++i)
   {
      fscanf(f, "%d ", &a);
      array[i] = a;
   }
   fclose(f);
}

int main()
{
   clock_t start, end;
   double duration1, duration2;
   int N, k, a;
   int array[1000];

   // Câu 1
   do
   {
      printf("\nNhap N (N>=2 && N <=1000): ");
      scanf("%d", &N);
      if (!(N >= 2 && N <= 1000))
         printf("\nBan da nhap sai, N phai tu 2 den 1000!");
   } while (!(N >= 2 && N <= 1000));
   ghiFile(N);

   // Câu 2 va cau 5
   docFile(array, &N);
   printf("\nNhap k: ");
   scanf("%d", &k);
   printf("\n\n TIM TUYEN TINH");
   start = clock();
   LinearSearch(array, N, k);
   end = clock();
   duration1 = (double)(end - start) / CLOCKS_PER_SEC;
   printf("\nThoi gian xu li tim tuyen tinh: %f", duration1);

   // câu 3 va cau 5
   printf("\n\n TIM NHI PHAN");
   start = clock();
   SelectionSort(array, N);
   binarySearch(array, N, k);
   end = clock();
   duration2 = (double)(end - start) / CLOCKS_PER_SEC;
   printf("\nThoi gian xu li tim nhi phan: %f", duration2);

   // Câu 4
   int evenIndex = 0;
   int oddIndex = N - 1;
   while (evenIndex < oddIndex)
   {
      while (array[evenIndex] % 2 == 0 && evenIndex < oddIndex)
      {
         evenIndex++;
      }
      while (array[oddIndex] % 2 != 0 && evenIndex < oddIndex)
      {
         oddIndex--;
      }
      if (evenIndex < oddIndex)
         Swap(&array[evenIndex], &array[oddIndex]);
   }
   int NumberEven = evenIndex;
   InsertionSort(array, NumberEven, 0);
   InsertionSort(array, N, evenIndex);

   _getch();
   return 0;
}