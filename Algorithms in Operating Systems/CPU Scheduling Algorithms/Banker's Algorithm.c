#include <stdio.h>

int main()
{
    int n, r; 
    printf("Enter Number of Processes and Resources: ");
    scanf("%d %d", &n, &r);
    int use[n][r];
    printf("Enter Memory of Resources in use: \n");
    for(int x=0; x<n; x++){
        for(int y=0; y<r; y++){
            scanf("%d", &use[x][y]);
        }
    }
    int total[r];
    printf("Enter total available resource: ");
    for(int x=0; x<r; x++){
        scanf("%d", &total[x]);
    }
    int max[n][r];
    printf("Enter Max Resource in demand: \n");
    for(int x=0; x<n; x++){
        for(int y=0; y<r; y++){
            scanf("%d", &max[x][y]);
        }
    }
    int need[n][r];
    printf("Memory resources in need:\n");
    for(int x=0; x<n; x++){
        for(int y=0; y<r; y++){
            need[x][y] = max[x][y] - use[x][y];
            printf("%d\t",need[x][y]);
        }
        printf("\n");
    }
    int avail[r];
    printf("Available resources: ");
    for(int x=0; x<r; x++){
        int sum = 0;
        for(int y=0; y<n; y++){
            sum += use[y][x];
        }
        avail[x] = total[x] - sum;
        printf("%d\t", avail[x]);
    }
    printf("\n");
    int completed = 0;
    int done[n];
    for(int x=0; x<n; x++){
        done[x] = 0;
    }
    do{
        int deadlock = 0;
        for(int x=0; x<n; x++){
            if(done[x] == 0){
                int safe = 1;
                for(int y=0; y<r; y++){
                    if(avail[y] < need[x][y]){
                        safe = 0;
                        break;
                    }
                }
                if(safe == 1){
                    deadlock = 1;
                    completed++;
                    done[x] = 1;
                    printf("Process %d can be executed safely\n", (x+1));
                    for(int y=0; y<r; y++){
                        avail[y] += use[x][y];
                    }
                }
            }
        }
        if(deadlock == 0){
            printf("\nNo furthur process can be executed. System has entered Deadlock.\n");
            break;
        }
    }while(completed!=n);
    return 0;
}
