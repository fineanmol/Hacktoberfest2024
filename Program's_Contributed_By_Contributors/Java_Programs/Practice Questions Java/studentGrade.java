package eteQuestionBank;
import java.io.CharArrayReader;
import java.util.*;
public class studentGrade {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Character[] answerKey = {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};

        int n = sc.nextInt();

        Character[][] students = new Character[n][10];

        for(int i = 0; i<n; i++){
            for(int j = 0; j<10; j++){
                students[i][j] = sc.next().charAt(0);
            }
        }

        for(int i = 0; i<n; i++){
            int marks = 0;
            for(int j = 0; j<10; j++){

                if(answerKey[j]==students[i][j]){
                    marks = marks + 1;
                }

            }
            System.out.println(marks);
        }
    }
}
