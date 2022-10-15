import java.util.Scanner;

public class AnyBaseToAnyBaseConverter {
    public static void main(String args[]){
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int baseN= scn.nextInt();
        int base= scn.nextInt();
        int dec = AnyBaseToDecimal(n, baseN);
        int result = DecimalToAnyBase(dec, base);
        System.out.println(result);
    }

    public static int AnyBaseToDecimal(int n, int base){
        int result=0;
        int basPower = 1;
        while(n>0){
            int rem = n%10;
            n=n/10;
            result += rem*basPower;
            basPower*=base;
        }
        return result;
    }

    public static int DecimalToAnyBase(int n, int base){
        int result = 0;
        int decimalPower=1;
        while(n>0){
            int rem = n%base;
            n=n/base;

            result +=rem*decimalPower;
            decimalPower *=10;
        }
       return result;
    }
}
