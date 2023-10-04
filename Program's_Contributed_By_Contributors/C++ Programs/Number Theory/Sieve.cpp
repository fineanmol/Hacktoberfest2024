#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back


const int MAX = 1e5;

vector<ll> primes;
vector<bool> bs(MAX+5, true);


void sieve()
{
    for(ll i=4; i<=MAX; i+=2)
        bs[i]=false;
    bs[0]=bs[1]=false;

    primes.push_back(2);
    for(ll i=3; i*i<=MAX; i+=2) {
        if(bs[i]) {
            for(ll j=i*i; j<=MAX; j=j+(2*i)) {
                bs[j] = false;
            }
        }
    }
    for(int i=3; i<=MAX; i+=2) {
        if(bs[i]) primes.pb(i);
    }

}

int main() {
    sieve();
    for(int i=0; i<primes.size(); i++) cout<<primes[i]<<" ";
}