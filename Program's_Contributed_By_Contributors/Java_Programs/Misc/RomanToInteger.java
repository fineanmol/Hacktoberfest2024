import java.util.ArrayList;
import java.util.List;


public class RomanToInteger {
    public static void main(String[] args) throws Exception {

        System.out.println(romanToInt("LVIII"));
    }

    public static int romanToInt(String s) {

        List<String> roman = new ArrayList();
        roman.add(s);
        int num = 0;
        while (roman.get(0).length() > 0) {
            num = convertToInteger(roman, num);
        }

        return num;
    }

    public static int convertToInteger(List<String> roman, int num) {

        if (roman.get(0).length() >= 2) {
            String roman01 = roman.get(0).substring(0, 2);

            if (roman01.equals("IV")) {
                roman.set(0, roman.get(0).substring(2));
                num += 4;

            } else if (roman01.equals("IX")) {
                roman.set(0, roman.get(0).substring(2));
                num += 9;

            } else if (roman01.equals("XL")) {
                roman.set(0, roman.get(0).substring(2));
                num += 40;

            } else if (roman01.equals("XC")) {
                roman.set(0, roman.get(0).substring(2));
                num += 90;

            } else if (roman01.equals("CD")) {
                roman.set(0, roman.get(0).substring(2));
                num += 400;

            } else if (roman01.equals("CM")) {
                roman.set(0, roman.get(0).substring(2));
                num += 900;

            } else {
                num = getNum(roman, num);
            }
        } else {
            num = getNum(roman, num);
        }

        return num;
    }

    private static int getNum(List<String> roman, int num) {
        String roman02 = roman.get(0).substring(0, 1);
        if (roman02.equals("I")) {
            num += 1;

        } else if (roman02.equals("V")) {
            num += 5;

        } else if (roman02.equals("X")) {
            num += 10;

        } else if (roman02.equals("L")) {
            num += 50;

        } else if (roman02.equals("C")) {
            num += 100;

        } else if (roman02.equals("D")) {
            num += 500;

        } else if (roman02.equals("M")) {
            num += 1000;
        }
        roman.set(0, roman.get(0).substring(1));
        return num;
    }
}
