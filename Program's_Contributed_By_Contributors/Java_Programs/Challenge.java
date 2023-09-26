public class Challenge {
    public static void main(String[] args)
    {

        double myFirstValue = 20.00d;
        double mySecondValue = 80.00d;
        double myValueTotal = myFirstValue+mySecondValue*100.00d;
        System.out.println("My  Value Total is: "+myValueTotal);

        //remainder

        double remainerValue =(myValueTotal%40.00d);
        System.out.println("The Remainder Value is: "+remainerValue);

        boolean isnoRemainder =(remainerValue==0) ? true:false;
        System.out.println("Is no Remainder: " +isnoRemainder);

        if(!isnoRemainder)
        {
            System.out.println("There is a Remainder Value ");
        }


    }
}
