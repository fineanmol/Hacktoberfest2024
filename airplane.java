class Airplane{
    String company;
    String model;

    public void height(){
        System.out.println("40,000ft");
    }

    public void printCompany(){
        System.out.println(this.company);
    }

    public void printModel(){
        System.out.println(this.model);
    }
}

public class obj {
    public static void main(String[] args){
         Airplane Airplane1 = new Airplane();
         Airplane1.company = "Airbus";
         Airplane1.model = "A350";
         Airplane1.height();

         Airplane Airplane2 = new Airplane();
         Airplane2.company = "Boeing";
         Airplane2.model = "787";

         Airplane1.printCompany();
         Airplane1.printModel();

         Airplane2.printCompany();
         Airplane2.printModel();

    }

}
