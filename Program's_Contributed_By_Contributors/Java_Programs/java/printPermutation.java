public class printPermutation {
    public static void printPerm(String str, String permutation){
        if(str.length() == 0){
            System.out.println(permutation);
            return;
        }
        for(int i=0;i<str.length();i++){
            char currChar = str.charAt(i);
            // "abc" --> "ab" i.e. removing the character which has been chosen at first place
            String newStr = str.substring(0,i) + str.substring(i+1);
            printPerm(newStr, permutation+currChar);
        }
    }
    public static void main(String args[]){
        String str = "abc";
        printPerm(str, "");
    }
}

//  Time complexity O(n) = n!
