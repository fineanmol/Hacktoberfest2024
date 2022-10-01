#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
#define fo1(x, y) for (lli x = 0; x < y; x++)
#define fo2(x, y) for (lli x = 1; x <= y; x++)

int main()
{
    lli t;
    cin >> t;
    while (t--)
    {
        lli count = 0;
        lli n;
        cin >> n;
        lli arr[n];
        lli j = 1;
        fo1(i, n)
        {
            cin >> arr[i];
            if (arr[i] > (j))
            {
                count += arr[i] - (j);
                //cout << count << endl;
                j += arr[i] - (j);
                //cout << i << endl;
                // n+= arr[i] - (i);
                // cout << n << endl;
                // n--;
                // i++;
            }
            j++;
        }
        cout << count << endl;
    }
}

// lli count=0;
// lli n;
// cin>>n;
// lli arr[n];
// fo1(i,n){
//     cin>>arr[i];
//     if(arr[i]>(i+1)){
//         count+=arr[i]-(i+1);
//     }
// }

// cout<<count<<endl;