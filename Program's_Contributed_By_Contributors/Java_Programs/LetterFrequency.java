import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class LetterFrequency {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a text: ");
        String text = scanner.nextLine();

        Map<Character, Integer> letterFrequency = calculateLetterFrequency(text);

        for (Map.Entry<Character, Integer> entry : letterFrequency.entrySet()) {
            char letter = entry.getKey();
            int frequency = entry.getValue();
            System.out.println(letter + ": " + frequency);
        }
    }

    public static Map<Character, Integer> calculateLetterFrequency(String text) {
        Map<Character, Integer> letterFrequency = new HashMap<>();

        for (char c : text.toCharArray()) {
            if (Character.isLetter(c)) {
                char lowercase = Character.toLowerCase(c);
                letterFrequency.put(lowercase, letterFrequency.getOrDefault(lowercase, 0) + 1);
            }
        }

        return letterFrequency;
    }
}
