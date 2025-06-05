#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <unordered_map> 

using namespace std;


string solve(int n, string s){
    for (auto i:s){
        if (i=='1'){
            return "YES";
        }
    }
    return "NO";
}

int main(){
    cout<<solve(4,"1100");
}