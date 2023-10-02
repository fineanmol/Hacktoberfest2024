import java.util.*;

public class RainwaterTrapping{
    public static int waterlvl(int height[]) {
        int n = height.length;
        int leftmax[]=new int[n];
        leftmax[0]=height[0];
        for(int i = 1; i<n;i++){
            leftmax[i]=Math.max(height[i], leftmax[i-1]);
        }
        int rightmax[]=new int[n];
        rightmax[n-1]=height[n-1];
        for(int i=n-2; i>=0;i--){
            rightmax[i]=Math.max(height[i], rightmax[i+1]);
        }
        int trappedwater=0;
        for(int i = 0; i<n; i++){
            int waterlvl = Math.min(leftmax[i], rightmax[i]);
            int a = waterlvl - height[i];
            trappedwater = trappedwater + a;
        }
        return trappedwater;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int height[]=new int [size];
        for(int i = 0; i<height.length;i++){
            height[i]=sc.nextInt();
        }
        int a = waterlvl(height);
        System.out.println("The amount os water stored is: "+a);
        sc.close();
    }
}