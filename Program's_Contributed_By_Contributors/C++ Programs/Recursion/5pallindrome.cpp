/*
====================================================================================
Title:  Check pallinrome using recursion
Author: Bhupendra Dangwal
Date:   09-09-2022
====================================================================================
*/
#include<bits/stdc++.h>
using namespace std;

bool isPalindromeHelper ( int l , int r , string & s ) {
    // base case
    if( l >= r ){
        return true;
    }

    if( s[l] != s[r] ){
        return false;
    }
	return isPalindromeHelper(l+1, r-1, s);
}

int main()
{
    string s = "RADAR";
    int n = s.size();
    bool status = isPalindromeHelper ( 0 , n-1 , s );
    cout<<"Status: "<<status;
    return 0;
}