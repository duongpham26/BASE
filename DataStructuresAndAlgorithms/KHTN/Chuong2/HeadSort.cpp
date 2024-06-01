#include "../library/lib.cpp"


// nlog(n)
void sift(int *a, int left, int right) {
    int i = left;
    int j = 2*left + 1;
    int x = a[left];
    while(j <= right) {
        if(j < right) {
            if(a[j] > a[j+1]) j++;
        }
        if(x <= a[j]) break;
        a[i] = a[j];
        i = j;
        j = 2*i + 1;
    }
    a[i] = x;
}

void headSort(int *a, int n) {
    //tao head
    int left = n / 2 - 1;
    while(left >= 0) {
        sift(a, left, n - 1);
        left--;
    }

    // doi vi tri va dieu chinh head
    int right = n - 1;
    while(right > 0) {
        swap(a[0], a[right]);
        right --;
        sift(a, 0, right);
    }
}


void siftmax(int *a, int left, int right) {
    int i = left;
    int j = 2*left + 1;
    int x = a[left];
    while(j <= right) {
        if(j < right) {
            if(a[j] < a[j+1]) j++;
        }
        if(x >= a[j]) break;
        a[i] = a[j];
        i = j;
        j = 2*i + 1;
    }
    a[i] = x;
}

void headSortmax(int *a, int n) {
    //tao head
    int left = n / 2 - 1;
    while(left >= 0) {
        siftmax(a, left, n - 1);
        left--;
    }

    // doi vi tri va dieu chinh head
    int right = n - 1;
    while(right > 0) {
        swap(a[0], a[right]);
        right --;
        siftmax(a, 0, right);
    }
}

int main() {
    const int n = 3;
    int a[n] = {3,2,1};

    // randArray(a, n, 0, 100);
    printArray(a, n);

    headSortmax(a, n);
    printArray(a, n);

    return 0;
}