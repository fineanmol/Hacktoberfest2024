public class ContainerWithMaxWater {
  public static void main(String[] args) {
    int[] height = { 1,8,6,2,5,4,8,3,7 };
    // o/P -> 49
    int res = maxArea(height);
    System.out.println(res);
  }

  private static int maxArea(int[] height) {
    int l=0;
    int r= height.length-1;
    int area=0;
    int maxArea = 0;
    while(l<r) {
      area = Math.min(height[l], height[r]) * (r-l);
      maxArea = Math.max(area, maxArea);
      if(height[l] < height[r]) l++;
      else r--;
    }
    return maxArea;
  }
}
