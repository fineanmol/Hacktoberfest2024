#include <bits/stdc++.h>
#define int long long
using namespace std ;
int n , answer1 , answer2 ;
int calcmin (vector < int > Q ) {
  if (Q.empty () ) return 1000000000000000000 ;
  int mn = Q[0] , mx =Q[0],mb = abs(Q[0]);
  for ( int i = 1 ; i < ( int ) Q.size ( ) ; ++ i ) {
    mn = min ( mn , Q [ i ] ) ;
    mx = max ( mx , Q [ i ] ) ;
    mb = min ( mb , abs ( Q [ i ] ) ) ;
 }
  return min ( mn*mx , mb*mb ) ;
}
int calcmax ( vector < int > Q ) {
  if (Q.empty()) return -1000000000000000000 ;
  int mb =abs(Q[0]) ;
for ( int i = 1 ; i < ( int ) Q.size ( ) ; ++ i ) {
  mb =max ( mb , abs ( Q [ i ] ) ) ;
}
return mb*mb ;
}
void solve() {
cin >> n ;
answer1 = 1000000000000000000 ;
answer2 = -1000000000000000000 ;
vector < int > Q ;
for ( int i = 1,x ; i<=n ; ++ i ) {
  cin >>x;
  Q.push_back(x) ;
  }
answer1 =min(answer1 ,calcmin(Q));
answer2 =max(answer2,calcmax(Q));
cout<<answer1<<" "<<answer2<< endl ;
}
signed main(){
int T ; cin >> T ;
while (T--)solve() ;
}