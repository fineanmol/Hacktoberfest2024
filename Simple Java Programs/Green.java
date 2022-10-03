abstract class VegetableShop {
   public abstract void Thanks();
   public void Onion() {
        System.out.println("The cost of 1 kg of onion is Rs. 30");
    }
   public void Chilli() {
       System.out.println("The cost of 1 kg of chilli is Rs. 60");
   }
   public void Tomato() {
       System.out.println("The cost of 1 kg of tomato is Rs. 55");
   }
   public void Brinjal() {
       System.out.println("The cost of 1 kg of brinjal is Rs. 50");
   }
   public void Ladyfinger() {
       System.out.println("The cost of 1 kg of Ladyfinger is Rs. 40");
   }
   public void Shoppee() {
    System.out.println("How many Kgs do you need?");
    System.out.println("The cost of 2 kgs of brinjal is Rs. 100");
   }
}
class Run extends VegetableShop {
    public void Thanks() {
        System.out.println("Thank you for shopping with us! Please come back!");
    }
}
class Green {
    public static void main(String[] args) {
        Run myobj = new Run();
        myobj.Onion();
        myobj.Chilli();
        myobj.Tomato();
        myobj.Brinjal();
        myobj.Ladyfinger();
        myobj.Shoppee();
        myobj.Thanks();    
    }  
}