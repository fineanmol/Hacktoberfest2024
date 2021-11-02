#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


#define rep(i,n) for(int i=0;i<(n);++i)
class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int N)
    {

        int t[N + 1][W + 1];

        rep(i, N + 1)
        {
            rep(j, W + 1)
            {
                if (i == 0 || j == 0)
                {
                    t[i][j] = 0;
                }
                else
                {
                    if (wt[i - 1] <= j)
                    {
                        t[i][j] = max ( (val[i - 1] + t[i - 1][j - wt[i - 1]] ) , (t[i - 1][j]) );
                    }
                    else
                    {
                        t[i][j] = t[i - 1][j];
                    }
                }
            }
        }

        return t[N][W];


    }
};

// { Driver Code Starts.

int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        //inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        //inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        //calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;

    }
    return 0;
}  // } Driver Code Ends