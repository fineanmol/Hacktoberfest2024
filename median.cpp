class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       // Initialization some neccessary variables
        vector<int>v;
        
        // store the array in the new array
        for(auto num:nums1)   // O(n1)
            v.push_back(num);
        
        for(auto num:nums2)  // O(n2)
            v.push_back(num);
        
        // Sort the array to find the median
        sort(v.begin(),v.end());  // O(nlogn)
        
        // Find the median and Return it
        int n=v.size();  // O(n)
        
        return n%2?v[n/2]:(v[n/2-1]+v[n/2])/2.0;
    }
};

** Accepted **
// Optimized Using: Two Pointer with Extra Space
  // Time Complexity: O(m+n)
  // Space Complexity: O(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // Create a single sorted by merging two sorted arrays
        int n1=nums1.size();
        int n2=nums2.size();
        int i=0;
        int j=0;
        int lastindex=-1;
             
        // Initialize a new array
           vector<int>v(n1+n2,0);
        
        while(i<n1&&j<n2)
        {
            if(nums1[i]<=nums2[j])
                v[++lastindex]=nums1[i++];
            else
                v[++lastindex]=nums2[j++];
        }
        
        while(i<n1)
            v[++lastindex]=nums1[i++];
        while(j<n2)
            v[++lastindex]=nums2[j++];
        
    // Return the result
        int n=n1+n2;
        return n%2?v[n/2]:(v[n/2]+v[n/2-1])/2.0;
        
    }
};

** Accepted **
// Optimized Using: Two Pointer without Extra Space (Insertion Sort)
  // Time Complexity: O(n1*n2)
  // Space Complexity: O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
       // Calculate Total length of final array: O(N)
        int n1=nums1.size();  
        int n2=nums2.size();
        int n=n1+n2;  
      
        // Edge Cases
        if(n2==0)
            return n1%2?nums1[n1/2]:(nums1[n1/2-1]+nums1[n1/2])/2.0;
        if(n1==0)
             return n2%2?nums2[n2/2]:(nums2[n2/2-1]+nums2[n2/2])/2.0;
        
        // Resize the array 'nums1': O(N), N is size of resized array
        nums1.resize(n);
        
        // Now use pointer to compare arrays elements 
        int i=0;
        int j=0;
        
       // Store all element in 'array 1' in sorted order 
        while(i<n1)  // O(n1)
        {
            if(nums1[i]>nums2[0])
            {
                swap(nums1[i],nums2[0]);  // O(1)
                // Rearrange Array nums2
                rearrangeArray(nums2);  // O(n2)
            }
            i++;
        }
        
        // Store remaining elements of 'array 2' in 'array 1' 
        while(j<nums2.size()) // O(n2)
            nums1[i++]=nums2[j++];
        
    // Return Result
    return n%2?nums1[n/2]:(nums1[n/2-1]+nums1[n/2])/2.0;
        
    }
    
    void rearrangeArray(vector<int>&nums2)
    {
        // Using insertion sort for insertion 
           // worst case Time Complexity Would be: O(n)
        for(int i=1;i<nums2.size()&&nums2[i]<nums2[i-1];i++)
            swap(nums2[i],nums2[i-1]);
    }
};

** Accepted **
// Optimized Approach: Using gap method:
    // Time Complexity: O((log base 2 power N)*(N))
   //  Space Complexity: O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // Do some pre-calculation : O(N)
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
        
        // Now Create Two Pointer
        int gap=ceil((n1+n2)/2.0);
        int i=0;
        int j=gap;
        
        // Edge Cases
        if(n1==0)
            return n2%2?nums2[n2/2]:(nums2[n2/2]+nums2[n2/2-1])/2.0;
        
        if(n2==0)
            return n1%2?nums1[n1/2]:(nums1[n1/2]+nums1[n1/2-1])/2.0;
        
        // Apply gap method: O((log base 2 power N)*N)
        
       while(gap)
       {   i=0;
           j=gap;
       // Move both pointer until they reach at last 
        while(j<n)
        {
            // If 'i' in 'nums1' and 'j' is also in 'nums1'
            if(i<n1&&j<n1&&nums1[i]>nums1[j])
            swap(nums1[i],nums1[j]);
        else
            // if 'i' in 'nums1' and 'j' is in 'nums2'
            if(i<n1&&j>=n1&&nums1[i]>nums2[j-n1])
                swap(nums1[i],nums2[j-n1]);
        else 
            // if 'i' in 'nums2' and 'j' is also in 'nums2'
            if(i>=n1&&j>=n1&&nums2[i-n1]>nums2[j-n1])
                 swap(nums2[i-n1],nums2[j-n1]);
            
        // Move both pointer ahead by only one step
        i++;
        j++;
        }
        
        // Edge Case, because of 'ceil()' gap never becomes zero
        if(gap==1)
            gap=0;
         
         gap=ceil(gap/2.0);
       }   
        
    //Return Result
      if(n%2)
          return n/2<n1?nums1[n/2]:nums2[n/2-n1];
     else
         if(n/2<n1)
             return (nums1[n/2]+nums1[n/2-1])/2.0;
        else
            if((n/2-1)<n1)
               return (nums1[n/2-1]+nums2[n/2-n1])/2.0;
       else 
           return (nums2[n/2-n1]+nums2[n/2-1-n1])/2.0;
       
    }
};

** Accepted **
// Optimized Approach: Binary Search
    // Time Complexity: O(log(min(m,n)))
   //  Space Complexity: O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
                   // ** Intuition  **
        // I have to find out correct left half and correct right half
          // i.e : // 7 ,  || 12 , 14 , 15  --> parition it
                  //  1 , 2 , 3 , 4 , || 9 , 11  --> parition it
                  // Now just findout max(left1,left2), min(right1,right2)
        
        
        // Initilaization of some neccessary variables
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
         
      if(n1>n2)  return findMedianSortedArrays(nums2,nums1);
        
     // When length is even, let's say 10 then left half length should be: (10+1)/2 =>5
     // When length is odd, let's say 11 then left half length should be: (11+1)/2 =>6
        // This mean that this formula gonna work in both condition
        int partition=(n+1)/2; 
        
    
    // Edge Case
    if(n1==0)
        return n2%2?nums2[n2/2]:(nums2[n2/2]+nums2[n2/2-1])/2.0;
    
    if(n2==0)
        return n1%2?nums1[n1/2]:(nums1[n1/2]+nums1[n1/2-1])/2.0;
    
    // Now do Partioning
    int left1=0;
    int right1=n1;
    int cut1,cut2;
    int l1,r1,l2,r2;
    
    do
    {   
        //Findout 'cut1' and 'cut2'
        cut1=(left1+right1)/2;
        cut2=partition-cut1;
   
        // Calculation for l1
        l1=cut1==0?INT_MIN:nums1[cut1-1];
        
        // Calculation for l2
        l2=cut2==0?INT_MIN:nums2[cut2-1];
        
        // Calculation for r1
        r1=cut1>=n1?INT_MAX:nums1[cut1];
        
        // Calculation for r2
        r2=cut2>=n2?INT_MAX:nums2[cut2];
        
        if(l1<=r2&&l2<=r1)
             // Return Result
             return n%2?max(l1,l2):(max(l1,l2)+min(r1,r2))/2.0;
        else
            
        if(l1>r2)
            right1=cut1-1;
        else
             left1=cut1+1;
       
       
    }while(left1<=right1);
        
             
    return 0.0;
    }
};
