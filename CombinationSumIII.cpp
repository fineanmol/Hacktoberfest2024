class Solution {
     void fun(int index, int n , int target,vector<int> &temp, vector<vector<int>> &v){
        if(target<0 || temp.size() > n){
            return ;
        }
        if(temp.size()==n){
            if(target==0){
                v.push_back(temp);
                return;
            }
        }
        else{
            for(int i=index ; i<=9 ; i++){
                temp.push_back(i);
                fun(i+1 , n ,target-i , temp ,v);
                temp.pop_back();
                // fun(index+1 , n ,target , temp ,v);
            }
        }

    }
  public:
    vector<vector<int>> combinationSum(int n, int target) {
        // code here
        vector<vector<int>>v;
        vector<int>temp;
        fun(1,n,target,temp,v);
        return v;
    }
};
