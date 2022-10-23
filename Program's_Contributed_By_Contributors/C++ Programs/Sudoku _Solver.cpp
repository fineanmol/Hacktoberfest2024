class Solution {
public:
    int N;
     bool check(int i,int j,vector<vector<char>>& grid,char val){
        
        // check in ith row and jth coloumn
        for(int k=0;k<N;k++){
            if(grid[i][k] == val || grid[k][j] == val)return 0; // false;
        }
        
        // check for 3*3 matrix
        int x = 3*(i/3), y = 3*(j/3);
        
        for(int p=x;p<x+3;p++){
            for(int q=y;q<y+3;q++){
                if(grid[p][q]==val)
                return 0;
            }
        }
        return 1;
    }
    int rec(int i,int j, int N,vector<vector<char>>& grid){
       
       if(j==N){i++,j=0;}
       if(i==N){
          // cout<<"dd";
           return 1;
       }
     
       // i & j are valid
       if(grid[i][j]!='.') { 
             if(rec(i,j+1,N,grid))
                return 1;
           
        }
        
        for(int val = 1;val<=9;val++){
            
            // cout<<char(val+'0')<<" ";
          if(grid[i][j]=='.' && check(i,j,grid,char(val+'0'))){// grid[i][j] == 0,check can I place 'val' here
              
            grid[i][j] = char(val+'0');  
            
            if(rec(i,j+1,N,grid))return 1;
            grid[i][j] = '.';  // backtracting 
          }
        }
        
       return 0;
    }
    //Function to print grids of the Sudoku.
    void printGrid (vector<vector<char>>& grid) 
    {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
         cout<<endl;
    }
    void solveSudoku(vector<vector<char>>& grid) {
        
         N = grid.size();
         rec(0,0,N,grid);
    }
};