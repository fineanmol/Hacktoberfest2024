import java.util.Arrays;
class counting_sort {
    static int max(int[] arr)
    {
        int max = arr[0];
        for(int i=0; i<arr.length; i++)
        {
            if(max < arr[i])
            {
                max = arr[i];
            }
        }
       return max;
    }
    static int min(int[] arr)
    {
        int min = arr[0];
        for(int i=0; i<arr.length; i++)
        {
            if(min > arr[i])
            {
                min = arr[i];
            }
        }
        return min;
    }
    public static void sort(int[] arr)
    {
        int max = max(arr);
        int min = min(arr);
        int diff = max - min + 1;
        int count_array[] = new int[diff];
        int output_array[] = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            count_array[arr[i] - min]++;
        }
        for (int i = 1; i < count_array.length; i++) {
            count_array[i] += count_array[i - 1];
        }

        for (int i = arr.length - 1; i >= 0; i--) {
            output_array[count_array[arr[i] - min] - 1] = arr[i];
            count_array[arr[i] - min]--;
        }

        for (int i = 0; i < arr.length; i++) {
            arr[i] = output_array[i];
        }
    }

    public static void main(String[] args)
    {
        int[] arr = { 1,5,10,-5,-15,3,9 };
        sort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
