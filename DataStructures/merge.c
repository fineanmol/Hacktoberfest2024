#include<stdio.h>
int MAX;
void merge(int [], int ,int);
void sort(int [], int, int, int);
void main()
{
 int i,n;
 printf("Enter no. of elements : ");
scanf("%d",&n);
 int *a;
a= (int*) malloc(n * sizeof(int));
 MAX=n;
printf("Enter elements : ");
for(i=0;i<n;i++)
 {
 scanf("%d",&a[i]);
 }

 printf("\n Before sort : ");
 for(i=0;i<n;i++)
 printf(" %d",a[i]);

 merge(a,0,n-1); 

 printf("\n After sort : ");
 for(i=0;i<n;i++)
 printf(" %d",a[i]);
}
void merge(int a[], int f, int l)
{
 int m;
 if(f<l)
 {
 m=(f+l)/2;
 merge(a,f,m);
 merge(a,m+1,l);
 sort(a,f,m,l);
 }
}
void sort(int a[], int f, int m, int l)
{
 int temp[MAX];
 int i=f,j=m+1,k=f,x;
 while(i<=m && j<=l)
 {
 if(a[i]<a[j])
 temp[k++]=a[i++];
 else if(a[i]>a[j])
 temp[k++]=a[j++];
 else
 {
 temp[k++]=a[i++];
 temp[k++]=a[j++];
 }
 }
 if(i>m)
 {
 for(x=j;x<=l;x++)
 temp[k++]=a[x];
 }
 else
 {
 for(x=i;x<=m;x++)
 temp[k++]=a[x];
 }

 for(i=f;i<=l;i++)
 a[i]=temp[i]; 
} 
