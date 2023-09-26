public class Ternary_Operator {
    public static void main(String[] args)
    {
        String makeofcar = "BMW";

        boolean isDomestic = makeofcar=="BMW" ? false:true;

        if(isDomestic)
        {
            System.out.println("This  car is Domestic  to our country ");
        }

        /*
          else
        {
            System.out.println("This car is not domestic");
        }
         */

        // dentoded the output by assigning the value  to a character

        String s =(isDomestic) ? "The care is domestic" : "The car is not domestic";
        System.out.println(s);
    }
}
