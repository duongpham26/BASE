#include <iostream>
#include <vector>
using namespace std;


int main() {
   // vector<int> array;
   // array = {1,2,3,4,5};
   // cout << "size: " << array.size() << "\n";
   // for(int i = 0; i<array.size(); ++i) {
   //    cout << "array[" << i << "] = " << array[i] << "\n";
   // }
   // array.push_back(6);
   // cout << "newsize: " << array.size();

   int m, n;
   cout << "\nNhap n: "; cin >> n;
   cout << "\nNhap m: "; cin >> m;
   vector<vector<int>> v(n, vector<int>(m));
   for(int i  = 0 ; i < n; i++) {
      for(int j = 0; j < m; j++) {
         cout << "Nhap v[" << i << "][" << j << "] = "; cin >> v[i][j];
      }
   }
   for(int i  = 0 ; i < n; i++) {
      for(int j = 0; j < m; j++) {
         cout << v[i][j] << " ";
      }
      cout << "\n";
   }

   return 0;
}