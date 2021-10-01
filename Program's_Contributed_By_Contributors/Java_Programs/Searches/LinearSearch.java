/**
 * 
 * In linear search algorithm, we iterate through all the elements of the array and compare it with the target, if we find the target then we return the index of the target, or else we return -1.
 * @author Tumin Sheth (https://github.com/tuminzee)
 * Time Complexity - O(n)
 * Space Complexity - O(1)
 * 
 * Resources
 * https://en.wikipedia.org/wiki/Linear_search
 * https://www.geeksforgeeks.org/linear-search/
 * 
 */


public class LinearSearch {
    public static void main(String[] args) {
        int target = 10;
        int [] arr = {1,2,3,4,5,6,7,8,9,10};
        int ans = Search(arr, target);
        if(ans == -1 ) System.out.println("Not Found");
        else System.out.println("Found at index: " + ans);
    }

    public static int Search(int [] arr, int target){
        for(int i = 0; i < arr.length; i++){
            if(arr[i] == target){
                return i;
            }
        }
        return -1;
    }
}
