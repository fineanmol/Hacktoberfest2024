#include<bits/stdc++.h>
using namespace std;
 
int maximum(int a, int b);
int minimum(int a, int b);

double MedianSortedArrays(int *a, int n,
                              int *b, int m)
{
     
    int min_index = 0, max_index = n, i, j, median;
    while (min_index <= max_index)
    {
        i = (min_index + max_index) / 2;
        j = ((n + m + 1) / 2) - i;
         
        if (j < 0)
        {
            max_index = i-1;
            continue;
        }
 
        if (i < n && j > 0 && b[j - 1] > a[i])       
            min_index = i + 1;
                 
        else if (i > 0 && j < m && b[j] < a[i - 1])       
            max_index = i - 1;
 
        else
        {
            if (i == 0)           
                median = b[j - 1];           
             
            else if (j == 0)           
                median = a[i - 1];           
            else           
                median = maximum(a[i - 1], b[j - 1]);           
            break;
        }
    }
     
    if ((n + m) % 2 == 1)
        return (double)median;
           
    if (i == n)
        return (median+b[j]) / 2.0;
         
    if (j == m)
        return (median + a[i]) / 2.0;
     
    return (median + minimum(a[i], b[j])) / 2.0;
}
 
int maximum(int a, int b)
{
    return a > b ? a : b;
}

int minimum(int a, int b)
{
    return a < b ? a : b;
}
 
int main()
{
    int a[20],b[20];
    int n,m;
    cout<<"Enter size of a: ";
    cin>>n;

    cout<<"Enter size of b: ";
    cin>>m;
    cout<<"Enter ele of a: "<<endl;
    for(int i=0;i<n;i++){
      cin>>a[i];
    }

    cout<<"Enter ele of b: "<<endl;
    for(int i=0;i<m;i++){
      cin>>b[i];
    }
     
    if (n < m)
        cout << "The median is : "
             << MedianSortedArrays(a, n, b, m);
    else
        cout << "The median is : "
             << MedianSortedArrays(b, m, a, n);
 
    return 0;
}