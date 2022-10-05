// similar to : https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// see striver video, inversion count , reverse pairs
// https://takeuforward.org/data-structure/count-inversions-in-an-array/

// TC = O(nlogn)
// SC = O(n)

class Solution {
public:

    int merge(vector<pair<int, int>>&vp , int start , int mid , int end){
        // CALCULATING 
        int c = 0;
        int j = mid+1;
        int i;
        for(i = start;i<=mid;i++){
            while(j<=end and vp[i].first>2LL*vp[j].first){
                j++;
            }
            c += (j-(mid+1));  // bcz [start, mid] and [mid+1, end] are sorted
            // so for start<=x<=end, x>2*(some y number of elements in [mid+1, end]) , then we can say start<= x+1<=end , will surely be greater than atleast y elements, and we will continue to look for new elements in [mid+1, end] holding nums[x+1]<2*nums[j] from the same index we left before...
        }
        
        // ----------------- doing the merge sort part ---------------------
        vector<pair<int, int>>temp(end-start+1);     // to join the 2 sorted partitions
        i = start; // start of left partition
        j = mid+1; // start of right partition
        int k = 0; // index for combined sorted partition
        
        while(i<=mid and j<=end){
            if(vp[i].first>vp[j].first){
                temp[k] = vp[j];
                k+=1;
                j+=1;
            }else{
                temp[k] = vp[i];
                k+=1;
                i+=1;
            }
        }
        
        // now adding remaining elements to our sorted temp..
        
        while(i<=mid) temp[k++] = vp[i++]; 
        while(j<=end) temp[k++] = vp[j++];  
    
        // now we update our value-pair(vp) to temp, why because we will pass vp for our next recursion only..
        i = start;
        k = 0;
        while(i <= end){
            vp[i++] = temp[k++];
        }
        
        return c;
    }
    
    int mergesort(vector<pair<int , int>>&vp, int l , int r){
        int inv_count = 0;
        if(l<r){             // if , not while   (l<r) not equal
            int m = (l+r)/2;
            inv_count+= mergesort(vp, l , m);
            inv_count+= mergesort(vp , m+1 , r);
            inv_count+= merge(vp, l ,m , r);   // rememeber (l , m, r)
        }
        
        return inv_count;
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        
        vector<pair<int , int>>vp; // bcz after sorting the indexes will be changed , so to track it
        for(int i = 0;i<n;i++){
            vp.push_back({nums[i], i});
        }
        
        int ans = mergesort(vp, 0 , n-1);  // rememeber 0 to (n-1)
        return ans;
    }
};
