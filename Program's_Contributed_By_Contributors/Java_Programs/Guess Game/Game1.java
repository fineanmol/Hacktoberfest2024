package games;
import java.util.Random;
import java.util.Scanner;
class Game{
    int a;
    int b; int guesses; boolean isCorrect;
    public Game(){
        Random rd= new Random();
        a=rd.nextInt(100);
    }
    public void takeUserInput(){
        System.out.println("ENTER A NUMBER BETWEEN 1 TO 100.");
        Scanner sc= new Scanner(System.in);
        b=sc.nextInt();
    }
    public void process(){
        if (b>a){
            System.out.println("Your guess is greater than the number .");
            isCorrect=false;
        }else if(b<a){
            System.out.println("your guess is less than the number .");
            isCorrect=false;
        }else{
            System.out.println("Correct guess");
            isCorrect=true;
        }
    }

    public void setGuesses(int n){
        guesses=n;
    }
    public int getGuesses(){
        return guesses;
    }
}


public class Game1 {
    public static void main(String[] args) {
        Game guess_game=new Game();
        int noOfGuesses=0;
        while (guess_game.isCorrect==false){
            guess_game.takeUserInput();
            guess_game.process();
            noOfGuesses++;

        }
        guess_game.setGuesses(noOfGuesses);
        System.out.println("You got correct ans with "+guess_game.getGuesses()+" guesses.");
    }
}