#include <iostream>
using namespace std;
 int main(){
    int s, e, n, k ,inm ,j=0 ,t=2;
    cout << "number of elements : " << endl ;
    cin >> n ;
    s=0;
    e=n;
    // n-1 is not getting the last entry as intermediate. 
    int arr[n];
    cout << "enyer number in array : " << endl ;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout << "key : " << endl ;
    cin >> k;
    while (s!=e)
    {   inm=(s+e)/2;
        if (arr[inm]==k)
        {
            cout << inm << endl;
            j=1;
            s=e;
        }
        else if (arr[inm]>k)
        {
            e=inm-1;
        }
        else if (arr[inm]<k)
        {
            s=inm+1;
            // to make s=e
        }
    }
    if (j!=1)
    {
        cout << "not found" ;
    }

    getchar();
    

  return 0;  
 }
