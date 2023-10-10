import java.util.Scanner;

class accountDetails{
    int totalAmount = 100;

    public void withdrawl(int amount){
        if(amount <= totalAmount){
            totalAmount -= amount;
        } else {
            System.out.println("The amount to be deduct is much greater than current money balance");   
        }
        System.out.println("The amount remainaing is: " + totalAmount);
    }

    public void deposite(int amount){
        totalAmount += amount;
        System.out.println("The amount added is: " + amount);
        System.out.println("The amount remainaing in account is: " + totalAmount);
    }
}

public class jjj{
    public static void main(String[] args){
        System.out.println("You have given 100 currency to start with");
        accountDetails A = new accountDetails();
        Scanner s = new Scanner(System.in);
        int ii = 1;
        while(ii > 0){
            System.out.println("Choose option below to perform an action:");
            System.out.println("1. For deposite money");
            System.out.println("2. For withdrawl money");
            System.out.println("3. For exiting program");
            System.out.print("Enter your choise: ");
            int ans = s.nextInt();
            switch (ans) {
                // deposite balance
                case 1:
                    System.out.print("Added money to be stored: ");
                    int addmoney = s.nextInt();
                    A.deposite(addmoney);
                    break;

                // withdral money
                case 2:
                    System.out.print("Added money to be withdrawl: ");
                    int removeMoney = s.nextInt();
                    A.withdrawl(removeMoney);
                    break;
            
                    
                // Exit
                case 3:
                    System.out.println("Thank you for using this programm");
                    ii = 0;
                    break;
            
                default:
                    break;
            }
        }
    }
}
