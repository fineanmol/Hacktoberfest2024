void bubble_sort(int a[],int n)
{
	int i,j,temp,flag=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>=a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
		{
			printf("already sorted\n");
			break;
		}
	}
}
void selection_sort(int a[],int n)
{
	int i,j,temp,min;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>=a[j+1])
			{
				min=i;
			}
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
}
void insertion_sort(int a[],int n){
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(a[j]>key&& j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}
void Insertion_sort(int a[],inr n)
{
	int i,j,key;
	for(i=1;i<n;i++){
		key=a[i];
		j=i-1;
		while(a[j]>key&&j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}
void merge_sort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		Merge(a,p,q,r);
	}
}
void Merge(int a[],int p,int q,int r)
{
	int b[20],l1=p,r1=q+1,i=p;
	while((l1<=q)&& (r1<=r))
	{
		if(a[l1]<a[r1]){
			b[i]=a[l1];
			l1=l1+1;
			i=i+1;
		}
		else
		{
			b[i]=a[r1];
			r1=r1+1;
			i=i+1;
		}
	}
	
	
	while(l1<=q)
	{
		b[i]=a[l1];
		l1=l1+1;
		i=i+1;
	}
	
	while(r1<=r)
	{
		b[i]=a[r1];
		r1=r1+1;
		i=i+1;
	}
	for(i=p;i<=r;i++)
	a[i]=b[i];
}
void merge_sort(int a[], int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		Merge(a,p,q,r);
	}
}
void Merge(inr a[], int p,int q,int r)
{
	int b[20],l1=p,r1=q+1,i=p;
	while(l1<=q &&r1<=r)
	{
		if(a[l1]<=a[r1])
		{
			b[i]=a[l1];
			l1=l1+1;
			i=i+1;
		}
		else
		{
			b[i]=a[r1];
			r1=r1+1;
			i=i+1;
		}
	}
	while(li<=q)
	{
		b[i]=a[l1];
		l1=l1+1;
		i=i+1;
	}
	while(r1<=r)
	{
		b[i]=a[r1];
		r1=r1+1;
		i=i+1;
	}
	for(i=p;i<=r;i++){
		a[i]=b[i];	
	}
}























void insertion_sort(int a[],int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(a[j]>key&& j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}

