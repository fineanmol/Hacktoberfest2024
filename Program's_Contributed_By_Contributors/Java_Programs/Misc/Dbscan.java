import java.util.*;

public class Dbscan {
    public static void main(String[] args) {
        int x[] = new int[13];
        int y[] = new int[13];
        double dist[][] = new double[13][13];
        int flag[] = new int[13];
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Enter the number of points:");
        int n = sc.nextInt();
        
        System.out.println("Enter the coordinates of the points:");
        for (int i = 1; i <= n; i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = Math.sqrt(Math.pow(x[i] - x[j], 2) + Math.pow(y[i] - y[j], 2));
            }
        }
        
        System.out.println("Enter the minimum number of points to form a cluster: ");
        int m = sc.nextInt();
        
        System.out.println("Enter the value of epsilon:");
        double e = sc.nextDouble();
        
        for (int i = 1; i <= n; i++) {
            int counter = 0;
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] <= e) {
                    counter += 1;
                }
            }
            if (counter >= m) {
                System.out.println(i + " Core Point");
                flag[i] = 1;
            }
        }
        
        for (int i = 1; i <= n; i++) {
            int[] arr = {0, 0, 0, 0, 0};
            int l = 1;
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] <= e) {
                    arr[l++] = j;
                }
            }
            if (flag[i] == 0) {
                int f = 0;
                outer: for (int k = 1; k <= n; k++) {
                    for (int o = 1; o <= 4; o++) {
                        if (k == arr[o]) {
                            if (flag[k] == 1) {
                                System.out.println(i + " Border Point");
                                f = 1;
                                break outer;
                            }
                        }
                    }
                }
                if (f != 1) {
                    System.out.println(i + " Noise Point");
                }
            }
        }
    }
}