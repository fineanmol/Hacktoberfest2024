import java.util.Scanner;

import java.util.Random;

public class GuessTheNumber

{

    public static void main(String [] args)

    {

        Random obj=new Random();

        int a=obj.nextInt(101);

        System.out.println("Generated Number= "+a);

        Scanner input=new Scanner(System.in);

        System.out.println("Number Generated Successfully!!\n\nNow start Guessing the Number.");

        System.out.println("Are you Ready?? Enter Yes or No.");

        String b=input.next();

        int count1=0,count2=0,count3=0;

        if(b.equalsIgnoreCase("yes"))

        {

            for(int i=0;i<50;i++)

            {

                System.out.println("Make a Guess.");

                int x=input.nextInt();

                if(a-x>0)

                {

                    System.out.println("Oops!! not a right guess. \nHint: Increse your Number.");

                    count1++;

                    int c1=count1+count2+count3;

                    System.out.println("No. of attempts= "+c1);

                    System.out.println("Unsuccessful attempts= "+c1+" Successful attempts= 0");

                    System.out.println("\nIf you want to continue, go ahead and enter Y for Yes. \nElse,want to leave game enter N for No.");

                    String c=input.next();

                    if(c.equalsIgnoreCase("n"))

                    break;

                }

                else if(a-x<0)

                {

                    System.out.println("Oops!! not a right guess. \nHint: Decrese your Number.");

                    count2++;

                    int c2=count1+count2+count3;

                    System.out.println("No. of attempts= "+c2);

                    System.out.println("Unsuccessful attempts= "+c2+" Successful attempts= 0");

                    System.out.println("\nIf you want to continue, go ahead and enter Y for Yes. \nElse,want to leave game enter N for No.");

                    String d=input.next();

                    //count2++;

                    if(d.equalsIgnoreCase("n"))

                    break;

                }

                else if(a-x==0)

                {

                    System.out.println("Congrats!! You Guessed it Right.");

                    count3++;

                    int c3=count1+count2+count3;

                    System.out.println("No. of attempts= "+c3);

                    System.out.println("Unsuccessful attempts= "+(c3-1)+" Successful attempts= 1.");

                    break;

                }

            }

        }

    }

}
