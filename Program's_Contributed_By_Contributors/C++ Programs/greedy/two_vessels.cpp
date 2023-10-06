/* You have two vessels with water. The first vessel contains a
 grams of water, and the second vessel contains b
 grams of water. Both vessels are very large and can hold any amount of water.

You also have an empty cup that can hold up to c
 grams of water.

In one move, you can scoop up to c
 grams of water from any vessel and pour it into the other vessel. Note that the mass of water poured in one move does not have to be an integer.

What is the minimum number of moves required to make the masses of water in the vessels equal? Note that you cannot perform any actions other than the described moves.
*/
#include <iostream>
#include <cmath>
using namespace std;

int moves(double a, double b, double c){
    double moves = (a-b)/(2*c);
    double abs_moves = ceil(moves);
    return (abs_moves);
}

int main()
{
  int t;
  double a, b, c;
  cin>>t;
  int i;
  for(i=0;i<t;i++){
      cin>>a>>b>>c;
      if(a>b){
          cout<<moves(a,b,c)<<endl;
      }
      else{
          cout<<moves(b,a,c)<<endl;
      }
  }
  return 0;
}