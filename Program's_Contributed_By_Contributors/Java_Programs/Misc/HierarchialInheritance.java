class Teacher
{
    int com;
    void taught(int a,int b)
    { 
         System.out.println("Age of the teacher = " + a);   
         com = b;
    }
    void show()
    {
         System.out.println("Syllabus Completed:- " + com + "%\n");
    }
}

class Student1 extends Teacher
{
    void report1(int s, int m)
    {
        show(); 
        System.out.println("\n1st STUDENT\n");
        System.out.println("Syllabus Completed:- " + com + "%");
        System.out.println("Marks obtained:- " + m);
    }
}
class Student2 extends Teacher
{ 
    void report2(int s, int m)
    {
        System.out.println("\n2nd STUDENT\n");
        System.out.println("Syllabus Completed:- " + s + "%");
        System.out.println("Marks obtained:- " + m);
    }
}

class HierarchialInheritance
{
    public static void main(String args[])
    { 
        Student1 s1 = new Student1();
        Student2 s2 = new Student2();
        s1.taught(60,98);
        s1.report1(90,75);
        s2.report2(70,68);
    }
}