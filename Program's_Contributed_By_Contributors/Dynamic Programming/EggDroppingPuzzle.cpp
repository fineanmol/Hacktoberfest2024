#include<iostream>
#include<climits>
using namespace std;

int eggDroppingDP(int number_of_eggs,int total_floors){
int dp[100][100];

for(int i=0;i<=number_of_eggs;i++){
    dp[i][0] = 0;
    dp[i][1] = 1;
}

for(int i=0;i<=total_floors;i++){
    dp[0][i] = 0;
    dp[1][i] = i;
}

for(int i=2;i<=number_of_eggs;i++){
    for(int j=2;j<=total_floors;j++){

            int minimum = INT_MAX;
            int current;
            for(int x=1;x<=j;x++){
                current = max(dp[i-1][x-1],dp[i][j-x])+1;

                if(current<minimum){
                    minimum = current;
                }
            }
            dp[i][j] = minimum;
    }
}
int ans = dp[number_of_eggs][total_floors];
return ans;
}


//Returns the min no of droppings required in the worst case.
int eggDroppingRecursive(int number_of_eggs,int total_floors){

if(number_of_eggs==1){
    return total_floors;
}
if(total_floors==1){
    return 1;
}
if(total_floors==0){
    return 0;
}

int minimum = INT_MAX;

for(int kth_floor = 1;kth_floor<=total_floors;kth_floor++){

    int ans = max( eggDroppingRecursive(number_of_eggs-1,kth_floor-1),eggDroppingRecursive(number_of_eggs,total_floors-kth_floor));
    minimum = min(minimum,ans);
}

return minimum+1;
}


int main(){

cout<<eggDroppingRecursive(10,10)<<endl;
cout<<eggDroppingDP(2,36)<<endl;

return 0;
}
