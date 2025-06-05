#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map> 

using namespace std;

string hidePhoneNumber(string num[]){
    string result="";
    int n=sizeof(num)/sizeof(num[0]);

    for (int i=0;i<n;i++){
        for (int j=0;j<10;j++){
            if (to_integer(num[i][j])%2!=0){
                result+=num[i][j];
            }
        }
        for (int j=9;j>=0;j--){
            if (num[i][j]%2==0){
                result+=num[i][j];
            }
        }
        result+="\n";
    }
    return result;
}