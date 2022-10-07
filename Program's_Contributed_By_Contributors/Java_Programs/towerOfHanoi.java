public class towerOfHanoi {
    static int count = 0;
    public static void TowerOfHanoi(int disk, int source, int helper, int destination){
        if(disk == 1){
            System.out.println("disk no. " + disk + "transferred from "+source+" to "+destination);
            return;
        }
        TowerOfHanoi(disk -1,source, destination, helper);
        System.out.println("disk no. " + disk + "transferred from "+source+" to "+destination);
        TowerOfHanoi(disk-1, helper, source, destination);

    }
    public static void reverseString(String str, int index){
        if(index<0){
            return;
        }
        System.out.print(str.charAt(index));
        reverseString(str, index-1);
    }
    public static void main(String[] args) {
        TowerOfHanoi(3,1,2,3);
        // System.out.println(steps);
        reverseString("nikhil", 5);
        
    }
}
