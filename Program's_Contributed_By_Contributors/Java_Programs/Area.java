import java.util.Scanner;

public class Area {
    private int len;
    private int bre;

    public Area(int length, int breadth) {
        this.len = length;
        this.bre = breadth;
    }

    public int calculateArea() {
        return len * bre;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the length of the rectangle: ");
        int length = sc.nextInt();

        System.out.print("Enter the breadth of the rectangle: ");
        int breadth = sc.nextInt();

        Area a = new Area(length, breadth);

        System.out.println("Area of Rectangle is: " + a.calculateArea());

        sc.close();
    }
}
