package eteQuestionBank;
import java.util.*;
public class contactDetails {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();

        String[] name = new String[n];
        String[] phone = new String[n];
        String[] email = new String[n];

        for(int i = 0; i<n; i++){
            name[i] = sc.next();
            phone[i] = sc.next();
            email[i] = sc.next();
        }

        String target = sc.next();

        int res = isFound(name, target);

        if(res!=-1){
            System.out.print(name[res] + " " + phone[res] + " " + email[res]);
        }
        else{
            System.out.println(-1);
        }

    }

    static int isFound(String[] name, String target){
        for(int i = 0; i< name.length; i++){
            if(name[i].equals(target)){
                return i;
            }
        }

        return -1;
    }
}
