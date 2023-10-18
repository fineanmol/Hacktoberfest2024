import java.util.Scanner;

class Calculator {
    int add(int a, int b) {
        return a + b;
    }

    int sub(int a, int b) {
        return a - b;
    }

    int mult(int a, int b) {
        return a * b;
    }

    float div(int a, int b) {
        return a / b;
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int a, b, ad, s, m, ch;
            System.out.println("enter two numbers:");
            a = sc.nextInt();
            b = sc.nextInt();
            float d;
            System.out
                    .println("Enter choice as 1 for sum, 2 for subtraction, 3 for multiplication and 4 for division:");
            ch = sc.nextInt();
            Calculator c = new Calculator();
            if (ch == 1) {
                ad = c.add(a, b);
                System.out.println(ad);
            } else if (ch == 2) {
                s = c.sub(a, b);
                System.out.println(s);
            } else if (ch == 3) {
                m = c.mult(a, b);
                System.out.println(m);
            } else if (ch == 4) {
                d = c.div(a, b);
                System.out.println(d);
            }
        }
    }
}