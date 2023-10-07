#include<stdio.h>
#include<stdlib.h>
struct pcs
{
    int at,bt,ord,remt,rt,wt,tt,term;
};
int allterminate(int n,struct pcs arr[])
{
    for(int i=0;i<n;i++)
    {
        if(!arr[i].term)
        {
            return 0;
        }
    }
    return 1;
}
int nextprocess(int n,struct pcs arr[],int ct)
{
    int min=100,x=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i].at<=ct && !arr[i].term)
        {
            if(arr[i].ord<min)
            {
                min=arr[i].ord;
                x = i;
            }
            
        }
    }
    return x;
}
int main()
{
    int n,i,ct=0,x;
    printf("Enter no. processes : ");
    scanf("%d",&n);
    struct pcs arr[n];
    for(i=0;i<n;i++)
    {
        printf("Process %d\n",i);
        printf("Enter arrival time : ");
        scanf("%d",&arr[i].at);
        printf("Enter burst time : ");
        scanf("%d",&arr[i].bt);
        printf("Enter order : ");
        scanf("%d",&arr[i].ord);
        arr[i].term=0;
        arr[i].remt=arr[i].bt;
        arr[i].wt = 0;
    }
    while(!allterminate(n,arr))
    {
        x=nextprocess(n,arr,ct);
        if(x==-1)
        {
            printf("t=%d idle\n",ct++);
            continue;
        }
        if (arr[x].remt==arr[x].bt)
        {
            arr[x].rt=ct-arr[x].at;
        }
        arr[x].remt--;
        if(arr[x].remt==0)
        {
            arr[x].tt=ct+1-arr[x].at;
            arr[x].term=1;
        }
        for(i=0;i<n;i++)
        {
            if(i==x)
            {
                continue;
            }
            else
            {
                if(arr[i].at<=ct && arr[i].term)
                {
                    arr[i].wt++;
                }
            }
        }
        printf("t=%d P%d\n",ct,x);
        ct++;
    }
    for(i=0;i<n;i++)
    {
        printf("Process %d\n",i);
        printf("Response time : %d\n",arr[i].rt);
        printf("Waiting time : %d\n",arr[i].rt);
        printf("Turnaround time : %d\n",arr[i].rt);
    }
    
    return 0;
}



