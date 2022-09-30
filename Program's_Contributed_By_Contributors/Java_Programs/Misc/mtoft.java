// This is a JAVA program to convert meter to ft.

import java.util.*;
class mtoft {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double m,ft;
        System.out.println("Enter m:");
        m=sc.nextInt();
        ft= 3.2804*m;
        System.out.println("Converted into ft will be="+ft);
    }
}
