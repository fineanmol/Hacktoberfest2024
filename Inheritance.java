package Hacktoberfest2024;
class Demo1{
    void m1(){
        System.out.println("In Demo1 class m1 method called....");
    }
}
class Demo2 extends Demo1 {
    void m2(){
        System.out.println("In Demo2 m2 method called....");
    }
}
public class Inheritance {
    public static void main(String[] args) {
        Demo2 demo = new Demo2();
        demo.m1();
        demo.m2();
    }
}
