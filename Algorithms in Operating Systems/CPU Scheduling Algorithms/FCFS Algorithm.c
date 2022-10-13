#include <stdio.h>

void main(){
    //these lines of code are to input no. of process which we need to work with
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    
    //this line defines an 2D array with [n] rows for n process 
    //[4] columns for -> [0] = ID, [1] = Bust Time, and [2] = Arrival Time
    int time[n][3];
    
    //these lines take input for n process with necessary details like: ID, BT, and AT
    printf("Enter process details: \nID\tBust\tArrival\n");
    for(int x=0; x<n; x++){
        scanf("%d %d %d", &time[x][0], &time[x][1], &time[x][2]);
    }
    
    //these lines of code is for a for loop (pun intended) which carrries out a insertion sort on the 'time' array
    //It checks if the priority of process 1 is less than that of 2, is fo then it swaps all the details of proccess 1 with 2
    for(int x=0; x<n; x++){
        for(int y=x+1; y<n-1; y++){
            if(time[x][2]<time[y][2]){
                
                //these are for swapping the ID's of the two process
                int temp = time[x][0];
                time[x][0] = time[y][0];
                time[y][0] = temp;
                
                //these are for swapping the Bust Time of the two process
                temp = time[x][1];
                time[x][1] = time[y][1];
                time[y][1] = temp;
                
                //these are for swapping the Arrival Time of the two process
                temp = time[x][2];
                time[x][2] = time[y][2];
                time[y][2] = temp;
            }
        }
    }
    
    //finally, when the array is sorted based on the priorities of the processes,
    //these lines prints the now sorted array 'time'
    printf("Process Schedule:\nID\tCompletion Time\n");
    int ct=0;
    for(int x=0; x<n; x++){
        ct+=time[x][1];
        printf("%d\t\t%d\n",time[x][0] ,ct);
    }
    
}



