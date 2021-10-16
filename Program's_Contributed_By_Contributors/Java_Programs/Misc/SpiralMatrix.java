import java.util.*;

public class SpiralMatrix {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of rows: ");
        int m = sc.nextInt();
        System.out.print("Enter the number of columns: ");
        int n = sc.nextInt();
        int matrix[][] = new int[m][n];
        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = sc.nextInt();
            }
            System.out.println();
        }
        System.out.println(spiralOrder(matrix));
        sc.close();
    }

    public static List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> list = new ArrayList<>();
        int minr = 0;
        int minc = 0;
        int maxr = matrix.length - 1;
        int maxc = matrix[0].length - 1;

        int total = matrix.length * matrix[0].length;
        ;
        int count = 1;

        while (count <= total) {
            // traverse upperwall
            for (int i = minc; i <= maxc && count <= total; i++) {
                list.add(matrix[minr][i]);
                count++;
            }
            minr++;
            // traverse right wall
            for (int i = minr; i <= maxr && count <= total; i++) {
                list.add(matrix[i][maxc]);
                count++;
            }
            maxc--;
            // traverse lower wall
            for (int i = maxc; i >= minc && count <= total; i--) {
                list.add(matrix[maxr][i]);
                count++;
            }
            maxr--;
            // traverse left wall
            for (int i = maxr; i >= minr && count <= total; i--) {
                list.add(matrix[i][minc]);
                count++;
            }
            minc++;
        }
        return list;
    }
}