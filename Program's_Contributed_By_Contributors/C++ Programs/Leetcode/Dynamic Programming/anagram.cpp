#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <unordered_map> 

using namespace std;

string CheckAnagram(string s1, string s2, string s3){
    if (s1.length()==s2.length() && s2.length()==s3.length()){
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        sort(s3.begin(),s3.end());

        if (s1==s2 && s2==s3){
            return "YES";
        }
        else{
            return "NO";
        }
    }
    return "NO";
}

int main(){
    cout<<CheckAnagram("dcbg","bcad","adcb");
}