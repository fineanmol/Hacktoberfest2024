#include <bits/stdc++.h>
using namespace std ;

/*

Sliding Window ALgo. 

A window (of given size = k) slides over a complete array of size 'n' and finds the property to be found . 
Used when Sub-array / sub-string / max-min sum , etc is used in quesn. 

Logic - we build a window of size=k , check the property of current window and then check it for next k consecutive elemnts 
IN A SINGLE LOOP .

INFO. - we are actually NOT building a window of size k and updating its starting and ending indexes and rechecking for new k consecutive
elemnts  as it would take more time
and increase TC . 

Instead , we ASSUME that the window of size k is initialized already and since a new window contains k-1 elemnts of old window ,
 hence , for new window ,
 we only need to remove first elemtn of old window and add new ele of next window . 

 e.g. - {1 , 2 , 3} , k=2

first window = {1,2}

second window -> remove 1(first elemtn of old window ) , add 3 (new ele of next window ) => {2,3}

Window size should ALWAYS be fixed and TC of Sliding window = O (n) 

*/

// Finding the MAX SUM of any k-consecutive elemnts of an array 

// MAX SUb-ARRAY SUM where size of subarray - k

int max_sum_k (vector<int> &nums , int k ){

int n = nums.size() ;

// assume window is already built , we just need to remove 1 old ele and add 1 new ele .
// Initialize a window that initially stores sum of first K consecutive ele . 

int curr_sum =0 ;

int max_sum  = INT_MIN ;

for(int i=0;i<k;i++){
    curr_sum +=nums[i] ; // any property to be checked for is initialized here .
  
}
// after checking the sum (completely) of first k consecutive lee , we calibarte our max sum . 
  max_sum  = max(curr_sum , max_sum ) ; 

// slide this window of size k by removing 1 ele and adding 1 ele . (we just use property of the window )

// i denotes the last ele of window here .
for(int i=k ; i<n;i++){

    // update that current property 

    curr_sum-= nums[i-k] ; // removing 1 ele of old window (first ele of old window ids k units behind CURRENt i )

    curr_sum += nums[i] ; // adding 1 ele of new window 
  // for this new window formed , check the property (optimum value we are looking for )
   max_sum  = max(curr_sum , max_sum ) ; 

}

return max_sum ;

}

int main(){

vector<int> nums = {5 , 2 , -1 , 0  , 3 } ;

cout << max_sum_k (nums , 3) << endl ;


    return 0 ;
}
