import java.util.Scanner;
class CollisionException extends Exception{
    CollisionException(String msg){
        super(msg);
    }
}
class CollisionExceptionCl
{
public static void main(String[] args) {
    try (Scanner sc = new Scanner(System.in)) {
        System.out.println("Enter the direction of Vehicle 1 and 2 as 0  for forward and 1 for Backward");
        int vd1 = sc.nextInt();
        int vd2 = sc.nextInt();
try {

if (vd1 != vd2) {

throw new CollisionException("There is a chance of collision!");

}
else{
        System.out.println("No chance of collision");
}

} catch (Exception e) {

System.out.println(e);
}
    }
}
}