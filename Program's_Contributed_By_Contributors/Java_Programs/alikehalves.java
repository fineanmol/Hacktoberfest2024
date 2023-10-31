
public class alikehalves {

    public static void main(String[] args) {
        String input = "textbook";
        checkVowelsAndConsonants(input);
    }

    public static void checkVowelsAndConsonants(String s) {
        int midlen=s.length()/2;
        int c=0,d=0;
        String a=s.substring(0,midlen);
        String b=s.substring(midlen);
        for (char ch : a.toCharArray()) {
            switch (Character.toLowerCase(ch)) {
                case 'a', 'e', 'i', 'o', 'u' -> c++;
            }

        }
        for (char ch : b.toCharArray()) {
            switch (Character.toLowerCase(ch)) {
                case 'a', 'e', 'i', 'o', 'u' -> d++;
            }

        }
        System.out.println(c+" "+d);
        System.out.println( (c==d));
        System.out.println(a+ " " + b);
        System.out.println(midlen);
//            System.out.println( Character.toLowerCase(str.charAt(0)));
//            System.out.println(str.toCharArray());
    }
}