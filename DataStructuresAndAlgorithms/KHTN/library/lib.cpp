#include <iostream>
#include <conio.h>
using namespace std;



void swap(int &a, int &b);

void swap(int &a, int &b) {
   int temp = a;
   a = b;
   b = temp;
}