import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class StrandSort {
    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};

        System.out.println("Original array: " + Arrays.toString(arr));

        int[] sortedArray = strandSort(arr);

        System.out.println("Sorted array: " + Arrays.toString(sortedArray));
    }

    public static int[] strandSort(int[] arr) {
        List<Integer> inputList = new ArrayList<>();
        for (int num : arr) {
            inputList.add(num);
        }

        List<Integer> result = new ArrayList<>();
        
        while (!inputList.isEmpty()) {
            List<Integer> sublist = new ArrayList<>();
            sublist.add(inputList.remove(0));

            for (int i = 0; i < inputList.size(); i++) {
                if (inputList.get(i) >= sublist.get(sublist.size() - 1)) {
                    sublist.add(inputList.remove(i));
                    i--;
                }
            }

            result = merge(result, sublist);
        }

        int[] sortedArray = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            sortedArray[i] = result.get(i);
        }

        return sortedArray;
    }

    public static List<Integer> merge(List<Integer> list1, List<Integer> list2) {
        List<Integer> mergedList = new ArrayList<>();
        int i = 0;
        int j = 0;

        while (i < list1.size() && j < list2.size()) {
            if (list1.get(i) < list2.get(j)) {
                mergedList.add(list1.get(i));
                i++;
            } else {
                mergedList.add(list2.get(j));
                j++;
            }
        }

        while (i < list1.size()) {
            mergedList.add(list1.get(i));
            i++;
        }

        while (j < list2.size()) {
            mergedList.add(list2.get(j));
            j++;
        }

        return mergedList;
    }
}
