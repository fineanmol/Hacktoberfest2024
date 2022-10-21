//Link: https://leetcode.com/problems/climbing-stairs/

unordered_map<int,int>mp={{1,1},{2,2}};


int climbStairs(int n) {

    if(n<0){
        return 0;
    }
    if(n==1 or n==2){
        return n;
    }
    if(mp.find(n)!=mp.end()){
        return mp[n];
    }
    
    mp[n]=climbStairs(n-2)+climbStairs(n-1);
    return mp[n];
}
