#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void travel(vector<vector<int>> &m,vector<vector<int>> &check,vector<string> &ans,int n,int x,int y,string path)
    {
        
        
        if(x == n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        
        //right
        if(y+1<n && check[x][y+1]==0  && m[x][y+1]==1){
            check[x][y+1] = 1;
            travel(m,check,ans,n,x,y+1,path+'R');
            check[x][y+1] = 0;
        }
        //down
        if(x+1<n && check[x+1][y]==0  && m[x+1][y]==1){
            check[x+1][y] = 1;
            travel(m,check,ans,n,x+1,y,path+'D');
            check[x+1][y] = 0;
        }
        //left
        if(y-1>=0 && check[x][y-1]==0  && m[x][y-1]==1){
            check[x][y-1] = 1;
            travel(m,check,ans,n,x,y-1,path+'L');
            check[x][y-1] = 0;
        }
        //up
        if(x-1>=0 && check[x-1][y]==0  && m[x-1][y]==1){
            check[x-1][y] = 1;
            travel(m,check,ans,n,x-1,y,path+'U');
            check[x-1][y] = 0;
        }
        return;
    }
    
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
       
        vector<string> ans;
        vector<vector<int>> check(n,vector<int> (n,0));
        if(m[0][0]==0) return ans;
        check[0][0]=1;
        string path="";
        travel(m,check,ans,n,0,0,path);
        return ans;
    }
};

    


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
