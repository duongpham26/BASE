#include <iostream>
#include <math.h>


void sort(int a[], int n, int h[], int k)
{
	int step, i, j;
	int x, len;
	for (step = 0; step < k; step++)
	{
		len = h[step];
		for (i = len; i < n; i++)
		{
			x = a[i];
			j = i - len;
			while ((x < a[j]) && (j >= 0))
			{
				a[j + len] = a[j];
				j = j - len;
			}
			a[j + len] = x;
		}
	}
}

void shellSort(int *a, int n) {
	const int k = (int)log2(double(n)) + 1;
	int *h = new int[k];
	h[0] = 1;
	for (int i = 1; i < k; i++) {
		h[i] = (h[i - 1] - 1) / 2;
	}
	sort(a, n, h, k);
	delete h;
}