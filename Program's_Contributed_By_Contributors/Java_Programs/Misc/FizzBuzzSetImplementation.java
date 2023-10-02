// FizzBuzz Java implementation using sets
// Author: @muhazafasa

import java.util.LinkedList;
import java.util.HashSet;
import java.util.Random;
import java.util.Scanner;

interface Result {
    String result(int x);
}

public class FizzBuzzSetImplementation {
    public static void main(String[] args) {
        class Pair<X, Y> { 
            public final X first; 
            public final Y second; 
            public Pair(X first, Y second) { 
                this.first = first; 
                this.second = second; 
            } 
        }

        HashSet<Integer> fizz = new HashSet<Integer>();
        for (int i = 3; i <= 100; i += 3)
            fizz.add(i);

        HashSet<Integer> buzz = new HashSet<Integer>();
        for (int i = 5; i <= 100; i += 5)
            buzz.add(i);
        
        HashSet<Integer> fizzBuzz = new HashSet<Integer>(fizz);
        fizzBuzz.retainAll(buzz);

        HashSet<Integer> rest = new HashSet<Integer>();
        for (int i = 1; i <= 100; ++i)
            rest.add(i);
        rest.removeAll(fizz);
        rest.removeAll(buzz);

        Result fizzResult = x -> "Fizz";
        Result buzzResult = x -> "Buzz";
        Result fizzBuzzResult = x -> "FizzBuzz";
        Result restResult = x -> String.format("%d", x);

        LinkedList<Pair<HashSet<Integer>, Result>> results = new LinkedList<Pair<HashSet<Integer>, Result>>();
        results.add(new Pair(fizzBuzz, fizzBuzzResult));
        results.add(new Pair(fizz, fizzResult));
        results.add(new Pair(buzz, buzzResult));
        results.add(new Pair(rest, restResult));

        Random rand = new Random();
        Scanner scan = new Scanner(System.in);

        while (true) {
            int number = rand.nextInt(99) + 1;
            for (var type : results)
                if (type.first.contains(number)) {
                    System.out.println(type.second.result(number));
                    break;
                }
            scan.nextLine();
        }
    }
}
