#include <bits/stdc++.h>
using namespace std;

int money_change(int *coin,int n,int money){
    int ans = 0;
    while(money>0){
        int idx = upper_bound(coin,coin+n,money)-coin-1;
        money = money - coin[idx];
        ans++;
    }
    return ans;
}

int main() {
    int money;
    cin>>money;
    int coin[]={1,2,5,10,20,50,100,200,500,2000};
    int size = sizeof(coin)/sizeof(int);
    cout<<money_change(coin,size,money);
}
