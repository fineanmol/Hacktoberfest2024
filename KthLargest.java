// Given an integer array nums and an integer k, return the kth largest element in the array.
//Note that it is the kth largest element in the sorted order, not the kth distinct element.
//You must solve it in O(n) time complexity.

class KthLargest {
  public int findKthLargest(int[] nums, int k) {
    PriorityQueue<Integer> mh = new PriorityQueue<Integer>(
        Collections.reverseOrder());
    for (int i = 0; i < nums.length; i++) {

      mh.add(nums[i]);

    }
    if (k > mh.size())
      return -1;
    int res = 0;
    for (int i = 0; i < k; i++) {
      res = mh.remove();
    }
    return res;
  }
}