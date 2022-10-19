public class Solution {
    public String convert(String s, int numRows) {
      if (numRows == 1) return s;
      
      StringBuilder sb = new StringBuilder();
      
      int totalGap = 2 * numRows - 2;
      for (int i = 0; i < numRows; i++) {
        int j = i;
        int currGap = totalGap - 2 * i;
        while (j < s.length()) {
          sb.append(s.charAt(j));
          if (currGap == 0) currGap = totalGap - currGap;
          j += currGap;
          currGap = totalGap - currGap;
        }
      }
      
      return sb.toString();
    }
}
