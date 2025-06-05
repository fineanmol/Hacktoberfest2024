class Solution {
public:
    int max(int p,int q){
    if(p>q)
    return p;
    else
    return q;
}
int min(int p, int q){
    if(p<q)
    return p;
    else
    return q;
}
    int trap(vector<int>& height) {
    long long int n,sum,ans=0;
        n=height.size();
        long long int pmax[n];
    pmax[0]=height[0];
    for(long long int i=1;i<=n-1;i++){
        pmax[i]=max(pmax[i-1],height[i]);
    }
    long long int smax[n];
    smax[n-1]=height[n-1];
    for(long long int i=n-2;i>=0;i--){
        smax[i]=max(smax[i+1],height[i]);
    }
    for(long long int i=1;i<=n-2;i++){
        sum=min(pmax[i-1],smax[i+1]);
        if(sum>height[i]){
            ans+=(sum-height[i]);
        }
    }
        return ans;
    }
};
