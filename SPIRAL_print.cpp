#include<iostream>
using namespace std;

void print(int arr[][100], int n, int m){
    for(int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }

        cout<<endl;
    }
}
void spiral_print(int arr[][100], int n, int m){
    int startRow=0;
    int startCol=0;
    int endRow= n-1;
    int endCol= m-1;
    while(startCol<=endCol){
        
        //startRow
        for(int col=startCol; col<=endCol; col++){
            cout<<arr[startRow][col]<<"  ";
        }
        
        //endcol
        for(int row=startRow+1; row<=endRow; row++){
            if(startCol==endCol){break;}
            cout<<arr[row][endCol]<<"  ";
        }

        //endRow
        for(int col= endCol-1; col>=startCol; col--){
            if(startRow==endRow){break;}
            cout<<arr[endRow][col]<<"  ";
        }

        //startCol
        for(int row= endRow-1; row>=startRow+1; row--){
            cout<<arr[row][startCol]<<"  ";
        }

        startRow++;
        endRow--;
        startCol++;
        endCol--;
    }
}

int main(){
    int arr[100][100];
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j]; 
        }
    }
    print(arr,n,m);
    spiral_print(arr,n,m);

    return 0;
}
