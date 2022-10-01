// https://leetcode.com/problems/find-k-closest-elements

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int ei = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        
        int si;
        int count = 1;
        if (ei>=arr.size()){
            si = arr.size()-1;
            ei = arr.size();
        } else if (ei==0){
            si = ei;
            ei++;
        }
        else if (arr[ei] == x){
            si = ei;
            ei++;
            
        } else {
            if (abs(arr[ei-1]-x)<=abs(arr[ei]-x)){
                si = ei-1;
                
            } else {
                si = ei;
                ei = ei+1;
                
            }
        }
        
        while (count<k && si>=1 && ei<arr.size()){
            if (abs(arr[si-1]-x)<=abs(arr[ei]-x)){
                si--;
                
            } else {
                ei++;
            }
            count++;
        }
                // cout<<si<<" "<<ei<<" "<<count<<endl;

        while (count<k && si>0){
            si--;count++;
        }
        
        while (count<k && ei<arr.size()){
            ei++;count++;
        }
        vector<int> result;
        for (int i = si;i<ei;i++){
            result.push_back(arr[i]);
        }
        
        return result;
            
        
        
    }
};