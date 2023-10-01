#include <stdio.h>

int insertion_sort(int a[],int n){
    int max,t;
    for (int i=0;i<n;i++){
        max = i;
        for (int j=i+1;j<n;j++){
            if (a[j]>a[max]){
                max = j;
            }
        }
        t = a[i];
        a[i] = a[max];
        a[max] = t;
    }
    return 0;
}

int main(){
    int t;
	scanf("%d",&t);
		
	int n,s,p,v;
	for (int i=0;i<t;i++){
	    scanf("%d",&n);
		int a[n];
	    for (int j=0;j<n;j++){
		    scanf("%d %d %d",&s,&p,&v);
		    a[j] = (p/(s+1))*v;
	    }
	    insertion_sort(a,n);
        printf("%d\n",a[0]);
	}
    return 0;
}