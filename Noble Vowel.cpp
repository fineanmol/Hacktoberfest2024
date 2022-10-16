#include <bits/stdc++.h>
  using namespace std;
  
  bool is_vowel(char c)
  {
    
    return ((c=='a')||(c=='e')||(c=='i')||(c=='o')||(c=='u')) ;
  }
  int main()
  {
    //write your code here
    int t ;
    cin >> t ;
    while(t--)
    {
        char c ;
        cin >> c ;
        cout << is_vowel(c)<<"\n";
    }
    return 0;
  }