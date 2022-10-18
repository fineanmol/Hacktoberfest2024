#include <iostream>
using namespace std;
 int main(){
    int s, e, n = 17, k ,inm ,j=0 ,t=2;
    cout << "number of elements : " << n <<  endl ;
    s=0;
    e=n;
    // n-1 is not getting the last entry as intermediate. 
    int arr[n] = { 1 ,8, 10, 22, 35, 67, 75, 78, 91, 99,102,302,420,589,620,852,1025};
    

    k = 589 ;
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
