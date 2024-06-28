#include <stdio.h>
#include <conio.h>

struct MaHang
{
   unsigned int ID;
   unsigned int SoLuong;
   float DonGia;
};

void swap(struct MaHang *a, struct MaHang *b)
{
   struct MaHang temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

void heapify(struct MaHang arr[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l].DonGia < arr[smallest].DonGia)
        smallest = l;
    if (r < n && arr[r].DonGia < arr[smallest].DonGia)
        smallest = r;
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}
void heapSort(struct MaHang arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void ShellSort(struct MaHang * mh, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
           struct MaHang temp = mh[i];
            int j;
            for (j = i; j >= gap && mh[j - gap].ID > temp.ID; j -= gap)
                mh[j] = mh[j - gap];
            mh[j] = temp;
        }
    }
}





void XuatMaHang (struct MaHang MH[], int n) {
   printf("\n");
   for (int i = 0; i < n; i++)
   {
      printf("\n%d\t%d\t%f", MH[i].ID, MH[i].SoLuong, MH[i].DonGia);
   }
}


int main () {
   int n = 4;
   
   struct MaHang MH[50];

   MH[0].ID = 2;
   MH[0].SoLuong = 7;
   MH[0].DonGia = 500;

   MH[1].ID = 3;
   MH[1].SoLuong = 4;
   MH[1].DonGia = 400;

   MH[2].ID = 4;
   MH[2].SoLuong = 3;
   MH[2].DonGia = 600;

   MH[3].ID = 5;
   MH[3].SoLuong = 9;
   MH[3].DonGia = 100;

   XuatMaHang(MH, n);

   heapSort(MH, 4);
   XuatMaHang(MH, n);

   ShellSort(MH, n);
   XuatMaHang(MH, n);



   return 0; 
}