class Solution {
    public long maxKelements(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);

        for(int i = 0; i < nums.length; i++){
            pq.offer(nums[i]);
        }

        long max = 0;
    
        while(k-- > 0){
            int val = pq.poll();
            max += val;
            int ceil = (int) Math.ceil(val / 3.0);
            pq.offer(ceil);
        }

        return max;

    }
}
