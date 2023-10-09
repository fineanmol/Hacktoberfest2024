
public class ArraySum {
    private int[] arrA, arrB, arrC;
    private int randomNum;

    public void loadElement() {
        arrA = new int[4];
        arrB = new int[4];
        arrC = new int[4];

        for (int i = 0; i < arrA.length; i++) {
            arrA[i] = randomNum = (int) (Math.random() * 60 + 1);// Random number (1-60)
            arrB[i] = randomNum = (int) (Math.random() * 60 + 1);
            System.out.println("test: " + randomNum);
        }

    }

    public void showElement() {

        for (int i = 0; i < arrC.length; i++) {
            arrC[i] = arrA[i] + arrB[i];
            System.out.println((i + 1) + "A. " + arrA[i]);
            System.out.println((i + 1) + "B. " + arrB[i]);
            System.out.println((i + 1) + "C. " + arrC[i]);

        }
    }

    public static void main(String[] args) {
        ArraySum arr = new ArraySum();
        arr.loadElement();
        arr.showElement();
    }

}
