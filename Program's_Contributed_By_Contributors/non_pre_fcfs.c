#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of process\n");
    scanf("%d",&n);
    int a[n][4],c=0;
    for(int i=0;i<n;i++){
        printf("Enter the arival time and burst time of process %d\n",(i+1));
        scanf("%d%d",&a[i][0],&a[i][1]);
        a[i][2]=c+a[i][1]-a[i][0]; //a[i][2] is storing turn around time of each process
        a[i][3]=a[i][2]-a[i][1];  //a[i][3] is storing waiting time of each process
        c=c+a[i][1];
    }
    printf("No\tTAT\tWT\n");
    int a1,a2=0;
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\n",(i+1),a[i][2],a[i][3]);
        a1+=a[i][2];
        a2=a2+a[i][3];
    }
    printf("Average TAT=%d\n",(a1/n));
    printf("Average WT=%d\n",(a2/n));
}
