class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
   
        
        
        
             int start = 0;
        int end = arr.size()-1;
        int mid = start + (end-start)/2;
        while(start<end){
            if(arr[mid]<arr[mid+1]){
                start = mid + 1;
            }
            else{
                end = mid;
            }
            mid = start + (end-start)/2;
        }
        return start;
    }
};
