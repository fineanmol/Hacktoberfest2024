import java.util.*;
public class morsecode {
    public static void morseToEnglish(String[] code,
                                      String morseCode)
    {
        String[] array = morseCode.split(" ");
        System.out.print("Morse code " + morseCode
                + " to English is: ");
        // Morse code to English
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < code.length; j++) {
                if (array[i].compareTo(code[j]) == 0) {
                    System.out.print((char)(j + 'a') + " ");
                    break;
                }
            }
        }
    }
    public static void englishToMorse(String[] code,
                                      String englishLang,
                                      char[] letter)
    {
        System.out.print("Morse code of " + englishLang
                + " is ");
        for (int i = 0; i < englishLang.length(); i++) {
            for (int j = 0; j < letter.length; j++) {
                if (englishLang.charAt(i) == letter[j]) {
                    System.out.print(code[j] + " ");
                    break;
                }
            }
        }
    }

    public static void main(String[] args)
    {

        // store the all the alphabet in an array
        char[] letter = { 'a', 'b', 'c', 'd', 'e', 'f',
                'g', 'h', 'i', 'j', 'k', 'l',
                'm', 'n', 'o', 'p', 'q', 'r',
                's', 't', 'u', 'v', 'w', 'x',
                'y', 'z', '1', '2', '3', '4',
                '5', '6', '7', '8', '9', '0' };
        // Morse code by indexing
        String[] code
                = { ".-", "-...", "-.-.", "-..", ".",
                "..-.", "--.", "....", "..", ".---",
                "-.-", ".-..", "--", "-.", "---",
                ".--.", "--.-", ".-.", "...", "-",
                "..-", "...-", ".--", "-..-", "-.--",
                "--..", "|" };

        // Given Strings
        String morseCode = "- .... .- - .----. ... / -.-. --- --- .-..";
        String englishLang = "hacktober";
        // morse to English
        morseToEnglish(code, morseCode);
        System.out.println();
        // English to morse code
        englishToMorse(code, englishLang, letter);
    }
}
