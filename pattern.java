public class q1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char col;
        for (int row = 1; row <= n; row=row+1) {
            for (col = 'a'; col <= 'e'; col = (char) (col + 1)) {
                System.out.print(col+" ");
            }
            System.out.println();
        }
    }
}
