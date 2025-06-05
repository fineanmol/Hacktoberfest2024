#include <iostream>
#include <vector>
using namespace std;

void spiral(vector<vector<int>> a){

  int k=0,l=0,i;
  int m=a.size();
  int n=a[0].size();
  // k is beginning of i
  // m is the end of i
  // l is beginning of j
  // n is the end of j
   while(k<m && l<n)
   {
    /* Print the first row from
               the remaining rows */
        for (int i = l; i < n; ++i) {
            cout << a[k][i] << " ";
        }
        k++;
 
        /* Print the last column
         from the remaining columns */
        for (int i = k; i < m; ++i) {
            cout << a[i][n - 1] << " ";
        }
        n--;
 
        /* Print the last row from
                the remaining rows */
        for (i = n - 1; i >= l; --i) {
            cout << a[m - 1][i] << " ";
        }
        m--;

        /* Print the first column from
                   the remaining columns */
    
        for (i = m - 1; i >= k; --i) {
            cout << a[i][l] << " ";
        }
        l++;
    
 
   }

}

int main(){
    vector<vector<int>> a={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    spiral(a);
  return 0;
}
