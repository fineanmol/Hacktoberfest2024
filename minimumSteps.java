class Solution {
    public long minimumSteps(String s) {
        long swaps = 0;
        int whiteCount = 0;

        for(int i = s.length() - 1 ; i >= 0; i--){
            if(s.charAt(i) == '1'){
                swaps += (long) whiteCount;
            }else{
                whiteCount++;
            }
        }
        return swaps;
    }
}
