
// package daa_pgm;
import java.io.*;
import java.util.*;

public class Selection_sort {

    static int[] a;
    static int n;

    static void sel_Sort(int a[]) {
        int len = a.length;

        for (int i = 0; i < len; i++) {
            int min = i;
            for (int j = i + 1; j < len; j++) {
                if (a[j] < a[min])
                    min = j;
            }

            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;

        }

    }

    public static void main(String[] args) throws IOException {

        int i;

        long st, et, et1, et2;

        Scanner read = new Scanner(System.in);
        Random ran = new Random();
        PrintWriter out = new PrintWriter(new File("Random.txt"));

        System.out.println("enter the number of elements(>5000)");
        n = read.nextInt();
        a = new int[n];

        for (i = 0; i < n; i++) {

            a[i] = ran.nextInt(n) + 1;
            out.print(a[i] + "\t");

        }

        System.out.println("The total number generated:" + i);
        out.close();

        // worst case

        st = System.nanoTime();

        sel_Sort(a);

        et = System.nanoTime() - st;

        PrintWriter outA = new PrintWriter(new File("Ascending.txt"));

        for (i = 0; i < n; i++)
            outA.print(a[i] + '\t');

        outA.close();

        System.out.println("The time complexity for Worstcase is: " + (et / 1000000000.0) + " seconds");

        // best case

        st = System.nanoTime();

        sel_Sort(a);

        et1 = System.nanoTime() - st;

        PrintWriter outB = new PrintWriter(new File("BestCase.txt"));

        for (i = 0; i < n; i++) {

            outB.print(a[i] + '\t');

        }

        outB.close();

        System.out.println("The time complexity for Bestcase is: " + (et1 / 1000000000.0) + " seconds");

        // average case

        for (i = 0; i < n; i++) {

            a[i] = ran.nextInt(n) + 1;

        }

        st = System.nanoTime();

        sel_Sort(a);

        et2 = System.nanoTime() - st;

        PrintWriter outD = new PrintWriter(new File("Descending.txt"));

        for (i = 0; i < n; i++)

            outD.print(a[i] + '\t');

        outD.close();
        System.out.println("The time complexity for Average case is: " + (et2 / 1000000000.0) + " seconds");
    }
}