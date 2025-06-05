class LinearSearch {
    public static void main(String[] args) {
        int[] arr = {1, 4, 2, 5, -1};
        int target = 2;
        boolean flag = false;
        for(int i = 0; i < arr.length; i++) {
            if(arr[i] == target) {
                System.out.println("Target found at index: " + i);
                flag = true;
                break;
            }
        }
        if(flag == false) System.out.println("Target is not present");
    }
}