package eteQuestionBank;
import  java.util.*;
public class textSearch {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String large = sc.nextLine();
        String target = sc.next();
        int targetLen = target.length();
        ArrayList<Integer> arr = new ArrayList<>();

        if(large.contains(target)){
            for(int i = 0; i<large.length()-1; i++){
                String check = "";
                for(int j = i; j<targetLen+i; j++){
                    check = check + large.charAt(j);
                }
                if(check.equals(target)){
                    arr.add(i);
                }
            }
            System.out.println(arr);
        }
        else{
            System.out.println(-1);
        }





//        for(int i = 0; i<arr.toArray().length; i++){
//            System.out.print(arr.get(i) + " ");
//        }
    }
}
