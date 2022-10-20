#include<iostream>
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int arr[n];
    int max = 0;
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
      if(max<arr[i])
      {
        max = arr[i];
      }
      
    }
    if(max == 0)
    {

      char c = 'a';
      cout<<c<<endl;
      for(int i=0;i<n;i++)
      {
        string str ="";
        str += char(c + 1);
        cout<<str<<endl;
        c = char(c+1);
      }
    }
    else
    {
      string s;
      for(int i=0;i<max;i++)
      {
        s += 'a';
      }
      cout<<s<<endl;
      for(int i =0;i<n;i++)
      {
        string st="";
        int j=0;
        for(j=0;j<arr[i];j++)
        {
          st+=s[j];
        }
        for(j = arr[i];j<max;j++)
        {
          if(s[j] > 'z')
            s[j] = 'a';
          st+= char(s[j] + 1);
        }
        cout<<st<<endl;
        s = "";
        for(int p=0;p<max;p++)
        {
          s += st[p];
        }

    }
    }
  }

  return 0;
}
