#include <iostream>
using namespace std;

class vector
{
   int n;
   int *v;
public:
   vector();
   vector(int n);
   vector(int n, int *a);
   void display();
   ~vector()
   {
      delete v;
   }
};

vector::vector()
{
   cout << "Nhap so chieu n : "; cin >> n;
   v = new int[n];
   for(int i = 0; i < n; i++)
      cout << "Nhap phan tu thu " << i + 1 << " : "; cin >> v[i]; 
}

void vector::display() 
{
   for(int i = 0; i < n; i++)
      cout << v[i] << " ";
   cout << endl;
}

int main() 
{

   return 0;
}