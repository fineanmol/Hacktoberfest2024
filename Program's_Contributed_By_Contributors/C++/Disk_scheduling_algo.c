// disk scheduling algorithms
// a) FCFS
// b) SSTF
// c) SCAN
// d) C-SCAN
// e) LOOK
// f) C-LOOK
#include<stdio.h>

void copy(int arr[], int copy[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    copy[i] = arr[i];
  }
}
int find(int arr[],int n,int key){
    for (int i = 0; i < n; i++){
        if(arr[i]==key)
            return i;    
    }
    
}
void Sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
  
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
}
int diff(int a,int b){return (a>b)?(a-b):(b-a);}

void fifo(int arr[],int n){
    int seektime=0;
    for(int i=0;i<n-1;i++){
        seektime+=diff(arr[i],arr[i+1]);
    }
    printf("Seektime is %d\n",seektime);
}
void sstf(int arr[],int n){
    int seektime=0,curr=0,smallpos;
    for(int i=0;i<n-1;i++){
        int smallest=9999;
        for(int j=0;j<n;j++){
            if(j==curr)continue;
            if(diff(arr[curr],arr[j])<smallest){
                smallest=diff(arr[curr],arr[j]);
                smallpos=j;
            }
                
        }
        seektime+=smallest;
        arr[curr]=9999;
        curr=smallpos;
    }
    printf("Seektime is %d\n",seektime);
}

int scan(int arr[],int headpos,int n,int right,int end,int c){
    if(headpos==0)return diff(arr[n-1],arr[0]);
    if(right)return c?(end-arr[headpos]+end+arr[headpos-1]):(end-arr[headpos]+end-arr[0]);
    else return c?(arr[headpos]+end+end-arr[headpos+1]):(arr[headpos]+arr[n-1]);
}
int look(int arr[],int headpos,int n,int right,int end,int c){
    if(headpos==0)return diff(arr[n-1],arr[0]);
    if(right)return c?(arr[n-1]-arr[headpos] + arr[n-1]-arr[0] + arr[headpos-1]-arr[0]):(arr[n-1]-arr[headpos] + arr[n-1]-arr[0]);
    else return c?(arr[headpos]-arr[0] + arr[n-1]-arr[0] + arr[n-1]-arr[headpos+1]):(arr[headpos]-arr[0] + arr[n-1]-arr[0]);
}



int main()
{
printf("Enter the number of sectors:");
int n;scanf("%d",&n);
printf("Enter the sectors(the first sector should be the head)");
int arr[n],arrcpy[n];
for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
for(int i=0;i<n;i++)printf("%d ",arr[i]);
printf("Enter the previous sector");
int prev,head=arr[0];scanf("%d",&prev);
printf("0.To Exit\n1.FCFS\n2.SSTF\n3.SCAN\n4.CSCAN\n5.LOOK\n6.CLOOK\n");
int flag;
int headpos;copy(arr,arrcpy,n);Sort(arrcpy,n);headpos=find(arrcpy,n,head);
do{
    printf("Enter your choice:");
    scanf("%d",&flag);
    switch(flag){
        case 1:
            copy(arr,arrcpy,n);for(int i=0;i<n;i++)printf("%d ",arrcpy[i]);printf("{%d} ",n);
            fifo(arrcpy,n);
            break;
        case 2:
            copy(arr,arrcpy,n);
            sstf(arrcpy,n);
            break;
        case 3:
            copy(arr,arrcpy,n);
            Sort(arrcpy,n);
            printf("Seektime is %d\n",scan(arrcpy,headpos,n,prev<head,199,0));   // 0 is scan and 1 is circular scan
            break;
        case 4:
            copy(arr,arrcpy,n);
            Sort(arrcpy,n);
            printf("Seektime is %d\n",scan(arrcpy,headpos,n,prev<head,199,1));   // 199 is the last sector of the disk
            break;
        case 5:
            copy(arr,arrcpy,n);
            Sort(arrcpy,n);
            printf("Seektime is %d\n",look(arrcpy,headpos,n,prev<head,199,0));   // 0 is look and 1 is circular look
            break;
        case 6:
            copy(arr,arrcpy,n);
            Sort(arrcpy,n);
            printf("Seektime is %d\n",look(arrcpy,headpos,n,prev<head,199,1));   // 199 is the last sector of the disk
            break;
    }

}while(flag);

return 0;
}
