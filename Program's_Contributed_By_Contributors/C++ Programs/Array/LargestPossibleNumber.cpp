#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
// function to check whether the
// substring is prime or not
bool isprime(string f)
{
    int n = stoi(f);
   
    // corner case check
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
int longp(int a)
{
    // convert the number to a string
    string d = to_string(a);
    int n = d.length();
    int c = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int len = 1; len <= n - i; len++) {
           
            // calculate the substrings of the string
            string p = d.substr(i, len);
           
            // pass the substring to the prime check
            // function
            if (isprime(p)) {
                int l = stoi(p);
               
                // store the maximum value of the prime
                // substring
                c = max(c, l);
            }
        }
    }
    return c;
}
// Driver Code
int main()
{
 
    long long int n = 12691;
    int k = longp(n);
    cout << k;
    return 0;
}
