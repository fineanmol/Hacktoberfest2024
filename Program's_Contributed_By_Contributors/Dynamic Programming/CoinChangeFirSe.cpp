#include<iostream>
using namespace std;

int CoinChange1Dp(int *coin,int sum,int n){
int dp[100000]={0};

dp[0] = 1;

//Iterate over coins.Solve the smaller problems first.Add the answers coin by coin.
for(int i=0;i<n;i++){
    for(int val=coin[i];val<=sum;val++){

        dp[val] += dp[val-coin[i]];

    }

}

return dp[sum];
}


int CoinChangeDp(int *coin,int sum,int n){

int dp[sum+1][n+1];

for(int i=0;i<=n;i++){
    dp[0][i]=1; //1 way to make sum 0.
}

for(int i=1;i<=sum;i++){
    for(int j=0;j<n;j++){

        int includingCurrentCoin = i-coin[j]>=0?dp[i - coin[j]][j]:0;
        int excludingCurrentCoin = (j-1)>=0?dp[i][j-1]:0;

        dp[i][j] = includingCurrentCoin + excludingCurrentCoin;

    }

}

return dp[sum][n-1];
}


int main(){
int coins[] = {5, 3, 6,2};
cout<<CoinChangeDp(coins,100,4)<<endl;
cout<<CoinChange1Dp(coins,100,4)<<endl;

return 0;
}
