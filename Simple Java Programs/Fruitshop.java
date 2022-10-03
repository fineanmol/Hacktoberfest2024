class Fruits {
   public void VariousFruits() {
       System.out.println("The various fruits are: ");
   }
}
class Apple extends Fruits {
    public void VariousFruits() {
        System.out.println("Apple is a sweet fruit!");
    }
}
class Mango extends Fruits {
    public void VariousFruits() {
        System.out.println("Mango is my favourite fruit!");
    }
}
class Banana extends Fruits {
    public void VariousFruits() {
        System.out.println("I don't like bananas!");
    }
}
class Fruitshop {
    public static void main(String[] args) {
        Fruits myapple = new Fruits();
        Fruits mymango = new Fruits();
        Fruits mybanana = new Fruits();
        myapple.VariousFruits();
        mymango.VariousFruits();
        mybanana.VariousFruits();

    }
}