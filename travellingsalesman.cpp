#include <bits/stdc++.h>
using namespace std;
#define vr 4
int TSP(int grph[][vr], int p) // implement traveling Salesman Problem. {
   vector<int> ver; //
   for (int i = 0; i < vr; i++)
      if (i != p)
         ver.push_back(i);
         int m_p = INT_MAX; // store minimum weight of a graph
   do {
      int cur_pth = 0;
      int k = p;
      for (int i = 0; i < ver.size(); i++) {
         cur_pth += grph[k][ver[i]];
         k = ver[i];
      }
      cur_pth += grph[k][p];
      m_p = min(m_p, cur_pth); // to update the value of minimum weight
   }
   while (next_permutation(ver.begin(), ver.end()));
   return m_p;
}
int main() {
   int grph[][vr] = { { 0, 5, 10, 15 }, //values of a graph in a form of matrix
      { 5, 0, 20, 30 },
      { 10, 20, 0, 35 },
      { 15, 30, 35, 0 }
   };
   int p = 0;
   cout<< "
 The result is: "<< TSP(grph, p) << endl;
   return 0;
}
