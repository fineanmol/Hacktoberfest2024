import java.util.Stack;

public class LargestRectangle {
    public static void main(String[] args) {
        int[] arr = {2,1,5,6,2,3};

        int res = largestRectangleArea(arr);
            System.out.println(res);


    }
    public static int largestRectangleArea(int[] heights) {
        int len = heights.length;
        Stack<Integer> s = new Stack<>();
        int maxArea = 0;
        for (int i = 0; i <= len; i++){
            int h = (i == len ? 0 : heights[i]);
            if (s.isEmpty() || h >= heights[s.peek()]) {
                s.push(i);
            } else {
                int top = s.pop();
                maxArea = Math.max(maxArea, heights[top] * (s.isEmpty() ? i : i - 1 - s.peek()));
                i--;
            }
        }
        return maxArea;
    }
}



