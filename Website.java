public class Website {

    protected int no_of_webpages;
    protected int no_of_images;


    void assignValue(int no_of_webpages, int no_of_images) {
        this.no_of_webpages = no_of_webpages;
        this.no_of_images = no_of_images;

    }
    void printMSG() {
        System.out.println("Website is ready to use!");
    }

    void display() {
        System.out.println("No: of webpages: " + no_of_webpages);
        System.out.println("Number of images: " + no_of_images);
    }
}

class Shopping extends Website {

    private int no_of_stocks;
    void assignValue(int no_of_webpages, int no_of_images, int no_of_stocks) {
        this.no_of_webpages = no_of_webpages;
        this.no_of_images = no_of_images;
        this.no_of_stocks = no_of_stocks;
    }
    @Override
    void printMSG() {
        System.out.println("Shopping website is ready to use!");
    }

    void displayStocks() {
        super.display();
        System.out.println("Number of stocks available: " + no_of_stocks);
    }
}

class Example3 {
    public static void main(String[] args) {
        Website website = new Website();
        Website shopping = new Shopping(); //  the reference type determines which methods and members are accessible at compile time.
                                            // we can only access the overridden methods of the child class

        website.assignValue(5, 10);
        shopping.printMSG();
        ((Shopping)shopping).assignValue(5,11, 50); // casted so we can access instances of Shopping
        ((Shopping)shopping).displayStocks();
    }
}


