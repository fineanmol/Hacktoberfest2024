/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).


    Time Complexity - O(4^m*n)
        We are going/checking 4 directions for each and every element on the Grid

    Space Complexity - O(m*n)
        We are traversing the whole grid of m*n
*/
#include<bits/stdc++.h>
using namespace std;

int dir_row[4] = {-1,1,0,0};
int dir_col[4] = {0,0,-1,1};
void rat_maze(int size, vector<vector<int>>&arr, vector<vector<int>>&vis, int row, int col){
    if(row==size-1 && col==size-1){
        //vis[0][0] = 1;
        for(auto rows:vis){
            for(auto it:rows){
                cout<<it<<" ";
            }
        }
        //cout<<"Yaha tak aya toh hun mein";
        //vis[0][0] = 0;
        cout<<endl;
        return;
    }
    
    for(int i = 0; i<4; i++){
        int nr = row + dir_row[i];
        int nc = col + dir_col[i];
        if(nr<size && nc<size && nr>=0 && nc>=0 && vis[nr][nc]==0 && arr[nr][nc]==1){
            vis[nr][nc] = 1;
            rat_maze(size,arr,vis,nr, nc);
            vis[nr][nc] = 0;
        }
       
        //return;
    }
    //return;
    
}

int main() {

	// Write your code here
    int n;
    cout<<"Enter the size of the Grid"<<endl;
    cin>>n;
    //int arr[n][n];
    cout<<"Begin entering the elements of the Grid"<<endl;
    vector<vector<int>>arr(n);
    for(int i = 0; i<n; i++){
        int temp;
        for(int j = 0; j<n; j++){
            cin>>temp;
            arr[i].push_back(temp);
        }
    }
    
    if(arr[0][0]==0){
        return 0;
    }
    
   
    vector<vector<int>>vis (n,vector<int>(n,0));
    vis[0][0] = 1;
    rat_maze(n,arr,vis,0,0);
    
	return 0;
}
