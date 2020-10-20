#include<iostream>
using namespace std;


// This is the most tricky solution.
int CoinChange_1d_dp(int coins[100],int n,int max_value){

int dp[205]={0};
    //Note this initialisation.

    dp[0] = 1;

    for(int i=0;i<n;i++){
    //Pick each coin and check for which it can be added.
        for(int value=coins[i];value<=max_value;value++){
            {
                dp[value]+= dp[value-coins[i]];
            }
        }
    }

return dp[max_value];
}


int CoinChange_2D_DP(int coins[],int n,int value){
int dp[value+1][n];
//n is the number of coins

//1 way to make value 0  using 0 coins of any denomination.
for(int i=0;i<n;i++){
    dp[0][i] = 1;
}

for(int val= 1;val<=value;val++){
    for(int index=0;index<n;index++){

        int includingCurrentCoin = val-coins[index]>=0 ? dp[val-coins[index]][index]:0;
        int excludingCurrentCoin = (index-1)>=0?dp[val][index-1]:0;

        dp[val][index] = includingCurrentCoin + excludingCurrentCoin;

    }

}

return dp[value][n-1];
}


//No of ways to make a denomination from a given choice of coins.
int CoinChange(int coins[100],int n,int value,int index){

    if(index>=n){
        return 0;
    }

    if(value < 0){
        return 0;
    }
    if(value==0 && index <n){
        return 1;
    }
    //A coin at index at i is included  (one or more times ) + Not included anytime.
    return CoinChange(coins,n,value-coins[index],index)+CoinChange(coins,n,value,index+1);
}

int main(){

//Input 1 , OUtput 4
int arr[] = {1, 2, 3};
cout<<CoinChange(arr,3,40,0)<<endl;

//Input 2 , OUtput 5
 int coins[] = {2, 5, 3, 6};
 cout<<CoinChange(coins,4,100,0)<<endl;

cout<<"DP SOLUTION"<<endl;
cout<<CoinChange_2D_DP(coins,4,100)<<endl;

cout<<CoinChange_1d_dp(coins,4,100)<<endl;

//cout<<CoinChangeDP(arr,3,40)<<endl;
//cout<<CoinChangeDP(coins,4,100)<<endl;
return 0;
}
