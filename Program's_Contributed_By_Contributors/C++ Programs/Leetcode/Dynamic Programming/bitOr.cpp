#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map> 

using namespace std;

string solve(int N, long long S, int D, vector<int> power){
    string result ="";

    sort(power.begin(),power.end());
    int moves=0;
    int currMax=N-1;

    while (D>=0 && power[currMax]!=0){
        D=D-power[currMax];
        power[currMax]/=2;
        sort(power.begin(),power.end());
        moves++;
    }
    if (moves>=D)
        return "Impossible";
    else{
        return to_string(moves);
    }
}