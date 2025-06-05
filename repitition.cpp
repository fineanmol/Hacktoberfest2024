#include<iostream>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    long long n=1, m=0;
    string s;
    cin >> s;
    long long size=s.size();
    for(long long i=0; i<size; i++)
    {
        if (s[i]==s[i+1])
            n++;
        else if (n>m)
        {
            m=n;
            n=1;
        }
    }
    cout << m << endl;
    return 0;
}
