// Link to Problem : https://leetcode.com/problems/two-sum/

vector<int> twoSum(vector<int>& num, int target) {
      map<int,int> m;
      vector<int> ans(2,0);
      int a;
      for(int i=0;i<num.size();i++){
          a = target-num[i];
          auto it = m.find(a);
          if(it != m.end()){
              ans[0]=it->second;
              ans[1]=i;
              return ans;
          }
          else
              m[num[i]]=i;
      }
      return ans;
  }
