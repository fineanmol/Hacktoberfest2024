class Solution {
    public int paintWalls(int[] cost, int[] time) {
        int n=cost.length;
        return (int)paintWallsHelper(cost,time,0,0,new Long[n][501]);
    }
    
    private long paintWallsHelper(int[] cost, int[] time, int index, int total, Long[][] memo) {
        if(total >= cost.length)
            return 0;
        if(index >= cost.length)
            return Integer.MAX_VALUE;
        if(memo[index][total] != null)
            return memo[index][total];
        
        long with=cost[index] + paintWallsHelper(cost,time,index+1,total+time[index]+1,memo);
        long without=paintWallsHelper(cost,time,index+1,total,memo);
        return memo[index][total]=Math.min(with,without);
    }
}
