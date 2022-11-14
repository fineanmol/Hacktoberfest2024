class Solution {
public:
    
    static bool check(string s1, string s2){
       return (s1+s2)>=(s2+s1);
    }
    
    string largestNumber(vector<int>& nums) {
        //checking whether all the elements in array is zero
        int x = 0;
        for(int i=0; i<nums.size();i++){
          if(nums[i]==0){
              x++;
          }  
        }
        //if all values are zero we'll return 0
        if(nums.size()==x) return "0";
        
        //the result may be very large, so you need to return a string instead of an integer
        vector<string> s(nums.size(),"");
        
        //cpnvert nums[i] into string and store in s[i]
        for(int i=0; i<s.size(); i++){
            s[i] = to_string(nums[i]);
        }
        
        //sort 
        sort(s.begin(),s.end(),check);
        
        string ans ="";
        
        for(int i=0; i<nums.size(); i++){
            ans+=s[i];
        }
        return ans;
    }
};
