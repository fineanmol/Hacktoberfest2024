
//This is a JAVA program to implement Bubble sort.
class bubblesort {
    public static void main(String[] args) {
        String str[] = { "Dixit", "Vishwa", "Dhruvish", "Shubhr", "Kenil" };
        String temp;
        System.out.println("String in Sorted Order:");
        for (int i = 0; i < str.length; i++) {
            for (int j = i + 1; j < str.length; j++) {
                if (str[j].compareTo(str[i]) < 0) {
                    temp = str[i];
                    str[i] = str[j];
                    str[j] = temp;
                }
            }
            System.out.println(str[i]);
        }
    }
}