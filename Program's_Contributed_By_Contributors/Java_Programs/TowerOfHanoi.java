package Sample;

public class TowerOfHanoi {

    public static void main(String[] args){
        int n = 3;
        towerOfHanoi(n,'A','C','B');
    }

    public static void towerOfHanoi(int n, char source, char dest, char spare){
        if (n == 1)
        {
            System.out.println("Move disk 1 from rod " +  source + " to rod " + dest);
            return;
        }
        towerOfHanoi(n-1, source, spare, dest);
        System.out.println("Move disk " + n + " from rod " +  source + " to rod " + dest);
        towerOfHanoi(n-1, spare, dest, source);
    }
}

