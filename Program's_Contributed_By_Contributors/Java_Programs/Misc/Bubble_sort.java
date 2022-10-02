//Bubble sort

class Hello {
    public static void main(String args[]) {
        int a[] = { 4, 7, 1, 2, 3, 9, 0 };
        for (int i = 0; i <= a.length - 1; i++) {
            for (int j = 1; j <= a.length - 1; j++) {
                if (a[i] >= a[j]) {
                    System.out.println(a[i]);
                }
            }
        }
    }
}