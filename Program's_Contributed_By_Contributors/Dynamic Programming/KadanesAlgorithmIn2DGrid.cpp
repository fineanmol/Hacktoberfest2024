#include<iostream>
using namespace std;

#define ROW 10
#define COL 10

int kadanes(int *a,int n){
    int cs =0;
    int ms =0;

    for(int i=0;i<n;i++){

    cs += a[i];
    if(cs<0){
        cs =0;
    }

    ms =max(cs,ms);
    }
return ms;
}

//Time Complexity o(n^3) .Can be optimised to O(n^2) by storing the prefix sum in a separated 2d array.

int maxSumSubarray(int grid[ROW][COL],int rows,int cols){

int currentSum = 0;
int maxSum =0;
int finalLeft,finalRight;

//fix the columns, apply kadanes by shrinking the rows to single element.Row sum will be stored in a temp array.

for(int left=0;left<cols;left++){
    int temp[ROW]={0};
    for(int right = left ; right<cols;right++){



        for(int i=0;i<rows;i++){
            temp[i] += grid[i][right];
        }
        //run Kadane on temp

       int currentMaxSum = kadanes(temp,rows);
        if(currentMaxSum>maxSum){
            maxSum = currentMaxSum;
            finalLeft = left;
            finalRight =right;

        }
    }
}
//cout<<finalLeft<<endl;
//cout<<finalRight<<endl;
return maxSum;
}


int main(){


 int M[ROW][COL] = {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6}
                      };

cout<<maxSumSubarray(M,4,5);
return 0;
}
