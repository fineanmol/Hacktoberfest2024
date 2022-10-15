//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


// } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& matrix)
{
    // 1st approach = transpose of a matrix
    
    int nrows = matrix.size();
    int ncols = matrix[0].size();
    
    for(int rows = 0; rows < nrows; rows++)
    {
        for(int cols = 0; cols < rows; cols++)
        {
            if(rows != cols)
                swap(matrix[rows][cols],matrix[cols][rows]);
        }
    }
    
    //2nd approach reverse
    
    for(int rows = 0; rows < (nrows/2); rows++)
    {
        for(int cols = 0; cols < ncols; cols++)
        {
            swap(matrix[rows][cols],matrix[nrows - 1 - rows][cols]);
        }
    }
    
}


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}


// } Driver Code Ends
