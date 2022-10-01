//Ques is we have to find a maximum sequence length in array where elements are firstly increasing and then decreasing. Link(https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/)
//Ex: [1,2,3,4,3,2,3] => Ans => 6 [1,2,3,4,3,2]

//Approach: First we make two arrays, left and right [Variation of LIS]
//left[i] stores the length of the Longest Increasing subsequence ending with nums[i]. 
//right[i] stores the length of the longest Decreasing subsequence starting from arr[i].
//return (left[i] + right[i] - 1) from 0 to n-1 to find max value.

public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    int n = nums.size();
	    vector<int> left(n,0),right(n,0);
	 
	    left[0] = 1;
	    for(int i=1;i<n;i++){
	        int x = left[i];
	        for(int j=0;j<i;j++){
	            if( nums[i] > nums[j]){
	                x = max(x,left[j]);
	            }
	        }
	        left[i] = x + 1;
	    }
	    
	    right[n-1] = 1;
	    for(int i=n-2;i>=0;i--){
	        int x = right[i];
	        for(int j=n-1;j>i;j--){
	            if( nums[i] > nums[j]){
	                x = max(x,right[j]);
	            }
	        }
	        right[i] = x + 1;
	    }
	    
	
	    int ans = 0;
	    
	    for(int i=0;i<n;i++){
	        ans = max(ans,left[i] + right[i] - 1);    
	    }
	    
	    return ans;
	}
