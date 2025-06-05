package eteQuestionBank;
import java.util.*;
public class reverseStringWithSpace {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        StringBuilder sb = new StringBuilder();
        sb = sb.append(sc.nextLine());

        ArrayList<Integer> arr = new ArrayList();
        StringBuilder withoutSpace = new StringBuilder();

        for(int i = 0; i<sb.length(); i++){
            if(sb.charAt(i)==' '){
                arr.add(i);
                continue;
            }
            else{
                withoutSpace.append(sb.charAt(i));
            }
        }

        withoutSpace.reverse();

        for(int j = 0; j<arr.toArray().length; j++){
            withoutSpace.insert(arr.get(j), " ");
        }

        System.out.println(withoutSpace);


    }
}
