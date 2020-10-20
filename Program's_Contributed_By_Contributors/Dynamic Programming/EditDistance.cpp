#include<iostream>
#include<cstring>
using namespace std;

/* Bottom Up DP */
int editDistanceBottomUp(char *a,char *b){
int m = strlen(a);
int n = strlen(b);

int dp[m+1][n+1];

for(int i=0;i<=m;i++){
    for(int j=0;j<=n;j++){
        if(i==0){
            dp[i][j] = j;
        }
        else if(j==0){
            dp[i][j]=i;
        }
        else{
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min( dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j])) + 1;
            }

        }


    }

}


return dp[m][n];
}


/* Recursive Implementation */
int editDistanceRecursive(char *a,char *b,int i,int j){

if(i==strlen(a)){
    return strlen(b)-j;

}
if(j==strlen(b)){
    return strlen(a)-i;
}

if(a[i]==b[j]){
    return editDistanceRecursive(a,b,i+1,j+1);
}
else {
    return min(editDistanceRecursive(a,b,i,j+1),min(editDistanceRecursive(a,b,i+1,j+1),editDistanceRecursive(a,b,i+1,j)))+1;
    }
}


int main(){

char a[100];
char b[100];

cin>>a>>b;
cout<<editDistanceRecursive(a,b,0,0)<<endl;
cout<<editDistanceBottomUp(a,b)<<endl;
return 0;
}
