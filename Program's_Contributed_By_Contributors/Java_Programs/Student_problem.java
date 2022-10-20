import java.util.*;
class student{
    int Rollno;
    String name;
    int marks[];
    String []subjects;
    float average;
    int max=-1000;
    int min=1000;
    Scanner inp= new Scanner(System.in);
    student(){
        subjects= new String[]{"Mathematics", "Physics", "Chemistry", "English", "Programming"};
        System.out.println("Enter the Roll no of the student");
        Rollno=inp.nextInt();
        System.out.println("Enter the name of the student");
        inp.nextLine();
        name=inp.nextLine();
        System.out.println("Enter the marks of "+ name);
        marks= new int[5];
        for(var i=0; i<marks.length; i++){
            System.out.println("Enter the marks of "+subjects[i]);
            marks[i]= inp.nextInt();
        }
    }
    public void display(){
        System.out.println("The Roll No. of the student is :" + Rollno);
        System.out.println("Name of student : "+name);
        System.out.println("The marks of "+name+" are:");
        for(int res: marks){
            System.out.println(res);
        }
        System.out.println(" ");
    }
    public void Statistics(){

        for (int i = 0; i <marks.length; i++) {
                 if(marks[i]>max){
                     max= marks[i];
                 }
                 if(marks[i]<min){
                     min=marks[i];
                 }
                 average= average + marks[i];
        }
        average= average/marks.length;
        System.out.println("The maximum marks of "+name+" are "+max);
        System.out.println("The minimum marks scored by "+name+ " are "+ min);
        System.out.println("the average score is : "+ average);
    }
}
public class stumain{
    public static void main(String[] args) {
        Scanner inp=new Scanner(System.in);
        System.out.println("Enter the no. of students:");
        int n=inp.nextInt();
        student arr[]=new student[n];
        for(var i=0; i<arr.length; i++){
            arr[i]= new student();
        }
        for(var i=0; i<arr.length; i++){
            arr[i].display();
            arr[i].Statistics();
        }
    }
}
