#define ll long long
#define mod 1000000007
using namespace std;

int main()
{
  ll t=1;
  while(t--)
  {
    ll n;
    cin>>n;
    ll after[30001],x,prev[30001],a[n];
    memset(after,0,sizeof(after));
    memset(prev,0,sizeof(prev));
    for(ll i=0;i<n;i++)
    {
      cin>>a[i];
      after[a[i]]++;
    }
    ll count=0;
    for(ll i=0;i<n;i++)
    {
      after[a[i]]--;
      ll l=a[i],r=a[i];
      while(l>=1&&r<=30000)
      {
        count=count+prev[l]*after[r];
        if(l!=r)
          count=count+prev[r]*after[l];
        l--,r++;
      }
      prev[a[i]]++;
    }
    cout<<count<<endl;
  }
  return 0;
}
