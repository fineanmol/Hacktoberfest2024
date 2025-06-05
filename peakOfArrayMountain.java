//852. Peak Index in a Mountain Array (leetcode)
// Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int start=0, end=arr.length-1, mid;
        while(start<=end)
        {
          
            mid=end+(start-end)/2;
            //peak element
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            {
                return mid;
            }
            //rightside move
            else if(arr[mid]>arr[mid-1])
            {
                start=mid+1;
            }
            //leftside move
            else
            {
                end=mid-1;
            }
        }
        return -1;
    }
}
