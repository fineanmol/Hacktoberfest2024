#include <stdio.h>

void main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int ar[n][3];
    printf("Enter process details: \nID\tBurst\tArrival\n");
    for(int x=0; x<n; x++){
        scanf("%d %d %d", &ar[x][0], &ar[x][1], &ar[x][2]);
    }
    
    for(int x=0; x<n; x++){
        for(int y=x+1; y<n-1; y++){
            if(ar[x][1]<ar[y][1]){
                
                int temp = ar[x][0];
                ar[x][0] = ar[y][0];
                ar[y][0] = temp;
                
                temp = ar[x][1];
                ar[x][1] = ar[y][1];
                ar[y][1] = temp;
                
                temp = ar[x][2];
                ar[x][2] = ar[y][2];
                ar[y][2] = temp;
            }
        }
    }
    
    
    printf("Process Schedule:\nID\tWaiting Time\n");
    int wt=0;
    for(int x=0; x<n; x++){
        wt+=ar[x][2];
        printf("%d\t\t%d\n",ar[x][0] ,wt);
    }
}


