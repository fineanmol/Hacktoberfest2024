//Rock Paper Scissor Game 

package Rameez;

import java.util.*;

public class Main {

public static void main(String[] args) {

    

//	public static void main(String[] args) {	  	// Rock paper Scissor Game 

	  int victory = 0;

	

   	int Rock = 0 , Paper = 1, Scissor = 2 ;

   	int turn ;

   Scanner zap = new Scanner(System.in);

Random ram = new Random();

     System.out.println("This is a Rock- Paper-Scissor Game  ");

   System.out.println(" Press Number Accordingly \n Rock --> 0\n Paper --> 1\n Scissor --> 2 \n  ");

    	System.out.println(" This Game has 5 Rounds ");

    	for(int step = 1 ; step<= 5; step++){

   System.out.println(" *******  Round 0" + step + "  ********\n --> Computer's has Choosen the number\n ");

  	int player1 = ram.nextInt(2);

	

		

	System.out.println(" --> Your's Turn ");

	int player2 = zap.nextInt();

	

	while (player2 < 0 || player2 >= 3)

	{

			System.out.println(" Please enter the number between 0-2 \n Enter the number again ");

			player2=zap.nextInt();

	}

	if (player1==player2){

		System.out.println(" Both choose same Weapon \n Match Tie !!  ");

	}

	else

{

	 if (player1==0  && player2 == 1){

	 	

		System.out.println(" You wins !! ");

	victory+= 1;

      	 }

       else if (player1==1  && player2 == 0)

      	{

      		 System.out.println(" You loss !! ");

      System.out.println("Computer's Choice is " + player1 + " ( Paper )");

      		}

  

  else  if (player1==2 && player2 == 1)

    {

		System.out.println(" You loss !! ");

		System.out.println("Computer's Choice is " + player1 + " ( Scissor )");

		}

  else if (player1==1 && player2 == 2){

	 System.out.println(" You wins !! ");

	 	victory+= 1;

	 }

 else   if (player1== 2  && player2 == 0){

    	

		System.out.println(" You wins !! ");

			victory+= 1; }

	

	else if  (player1== 0  && player2 == 2)

	{	

	System.out.println(" You loss !! ");

	System.out.println("Computer's Choice is " + player1 + " ( Rock )");

	}

}

	System.out.println("\n__________________________\n");

	if (step == 5 ){

		System.out.println( " Your Total Victories are " + victory +

		" \n ******* Game End ******* " + "\n *** Programed By Muhammad Rameez ***\n ***** Gcu Lahore (0090-Bscs-20) *****");

		

	}}

	}

	}
