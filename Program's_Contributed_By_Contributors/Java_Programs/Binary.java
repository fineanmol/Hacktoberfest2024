public class Binary{
    public static String getBinary(int n){
        if(n==0)
          return "";
        return getBinary(n/2)+n%2;
    }
    public static void main(String[] args) {
        System.out.println(getBinary(4));
    }
}