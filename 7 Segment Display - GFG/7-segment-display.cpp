// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
 public:
   string sevenSegments(string S, int N) {
       string str="";
       unordered_map <char,int> umap;
       S=S.substr(0,N);
       umap['0']=6;
       umap['1']=2;
       umap['2']=5;
       umap['3']=5;
       umap['4']=4;
       umap['5']=5;
       umap['6']=6;
       umap['7']=3;
       umap['8']=7;
       umap['9']=5;
       int count=0,k;
       for(auto c:S)
        count+=umap[c];
       int n=S.length();
       char c;
       while(n>0)
       {
         c='0';
         while(c<='8')
         {
          if(n==1)
          {
             if(umap[c]==count)
             {str+=c;n--;count=0;break;}
          }
          else
          {
          k=count-umap[c];
          if(k/(n-1)>1)
          {
              str+=c;
              n--;
              count-=umap[c];
              break;
          }
          }
          c++;
          }
       }
       return str;
   }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        string S;
        cin>>S;

        Solution ob;
        cout << ob.sevenSegments(S,N) << endl;
    }
    return 0;
}  // } Driver Code Ends