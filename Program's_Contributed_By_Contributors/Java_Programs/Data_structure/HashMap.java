package Sample;

import java.util.Map;

public class HashMap {

    public static void main(String[] args){
        Map<Integer , String> numbers = new HashMap<>();

        numbers.put(1 , "one");
        numbers.put(2 , "two");
        numbers.put(3 , "three");

        System.out.println("Map : " +numbers);
        System.out.println("Keys : "+numbers.keySet());
        System.out.println("Values : "+numbers.values());
        System.out.println("Entries : "+numbers.entrySet());

        String value = numbers.remove(2);
        System.out.println("Removed Value : "+value);
    }

}
