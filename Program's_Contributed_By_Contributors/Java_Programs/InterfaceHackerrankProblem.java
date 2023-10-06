import java.util.*;
public class InterfaceHackerrankProblem {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */

        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();

        MyCalculator mc = new MyCalculator();

        int result = mc.divisor_sum(n);

        System.out.println("I implemented: AdvancedArithmetic");
        System.out.println(result);
    }
}

interface AdvancedArithmetic{
    public int divisor_sum(int n);
}

class MyCalculator implements AdvancedArithmetic {

    @Override
    public int divisor_sum(int n){
        int[] divisori = new int[20];

        int contatore = 0;

        for(int i=1; i<=n; i++){
            if(n%i==0){
                divisori[contatore] = i;
                contatore++;
            }
        }

        int somma=0;
        for(int i=0; i<contatore; i++){
            somma+=divisori[i];
        }

        return somma;
    }
}