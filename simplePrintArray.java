public class simplePrintArray {
    public static void main(String args[]) {
        String[] arr = { "BMW", "Toyota", "Mercedes Benz", "Daihatsu" };
        for (int i = 0; i < arr.length; i++) {
            System.out.println((i + 1) + ". Car Brand : " + arr[i]);
        }
    }

}