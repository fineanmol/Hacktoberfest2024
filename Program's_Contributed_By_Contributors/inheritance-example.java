package GRPA_and_PPA.W3;
import java.util.*;


    class Person{
        private String name;
        private long aadharno;
        public Person(String name, long aadharno){
            this.name = name;
            this.aadharno = aadharno;
        }
        public void print() {
            System.out.println("name : " + name);
            System.out.println("aadharno : " + aadharno);
        }
    }

    class Employee extends Person{
        private double salary;

        //implement the constructor
        public Employee(String nameE, long ano, double sal){
            super(nameE, ano);
            salary = sal;
        }

        //override print method
        public void print(){
            super.print();
            System.out.println("salary : "+salary);
        }
    }

    class ContactEmployee extends Employee{
        final private static double hourlyPay = 100.00;
        private int contactHour;

        //implement the constructor
        public ContactEmployee(String nm, long adhar, int cnth){
            super(nm, adhar,cnth*hourlyPay);
            contactHour = cnth;

        }
        //salary is computed as contactHour * hourlyPay
    }

    class FClass{
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            String nm1 = sc.nextLine();
            String nm2 = sc.nextLine();
            long adh1 = sc.nextLong();
            long adh2 = sc.nextLong();
            double sal = sc.nextDouble();
            int cont = sc.nextInt();
            Employee[] eArr = new Employee[2];
            eArr[0] = new Employee(nm1, adh1, sal);
            eArr[1] = new ContactEmployee(nm2, adh2, cont);
            for(Employee e : eArr)
                e.print();
        }
    }

