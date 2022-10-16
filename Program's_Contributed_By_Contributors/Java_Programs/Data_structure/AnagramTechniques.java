package Arrays;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class AnagramTechniques {

  

    public static boolean isAnnagramUsingFrequencyCounter(String s, String t) {
        // You can use py counters -- return Counter(s) == Counter(t)

    }
    public static boolean isAnagramUsingSorting(String s, String t) {
        if (s.length() != t.length()) return false;
        // You can use py counters -- return Counter(s) == Counter(t)
        // You can also use sroting -- sorted(s) == sorted(t) -- PY || O(nlogn)  /O(1)
        char[] str1 = s.toCharArray();
        char[] str2 = t.toCharArray();
        Arrays.sort(str1);
        Arrays.sort(str2);
        return Arrays.equals(str1, str2);
    }
    
    public static boolean isAnagramIUsingHash(String s, String t) {

        if (s.length() != t.length()) return false;
        // You can use py counters -- return Counter(s) == Counter(t)

        // Use hashing
        Map<String, Integer> smap = new HashMap();
        Map<String, Integer> tmap = new HashMap();

        String sArray[] = s.split("");
        String tArray[] = t.split("");

        for (int i = 0; i < sArray.length; i++) {

            if (smap.containsKey(sArray[i])) {
                smap.put(sArray[i], smap.get(sArray[i]) + 1);
            } else {
                smap.put(sArray[i], 1);
            }

            if (tmap.containsKey(tArray[i])) {
                tmap.put(tArray[i], tmap.get(tArray[i]) + 1);
            } else {
                tmap.put(tArray[i], 1);
            }
        }

        for (String ch : smap.keySet()) {
            if (smap.get(ch) != tmap.get(ch)) return false;
        }

        return true;
    }

      public static void main(String[] args) {
        String s = "anagramz", t = "managraq";
        System.out.println(isAnagramIUsingHash(s, t));
    }
}

