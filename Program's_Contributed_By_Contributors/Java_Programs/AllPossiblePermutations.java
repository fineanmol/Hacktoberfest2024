import java.util.*;

public class AllPossiblePermutations {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number of Element in Array");
        int rowCount = sc.nextInt();
        int[] arr = new int[rowCount];

        for(int i=0; i<arr.length; i++){
            arr[i] = sc.nextInt();
        }

        List<List<Integer>> lists = findAllPossiblePermutations(arr);
        System.out.println(lists);
    }

    private static List<List<Integer>> findAllPossiblePermutations(int[] arr) {
        int totalPermutationPossible = 1;

        for(int i=1; i<=arr.length ; i++) {
            totalPermutationPossible *= i;
        }

        List<List<Integer>> result = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        for(int i : arr)
            list.add(i);
        result.add(new ArrayList<>(list));
        for(int i=1; i<totalPermutationPossible; i++){
            result.add(new ArrayList<>(nextPermutation(list)));
        }

        return result;
    }

    private static List<Integer> nextPermutation(List<Integer> list) {

        int xi=-1, yi=-1;

//        find X
        for(int i=list.size()-2; i>=0; i--){
            if(list.get(i)<list.get(i+1)){
                xi = i;
                break;
            }
        }

        if(xi == -1){
            Collections.sort(list);
            return list;
        }

//        find Y
        for(int i=list.size()-1; i>xi; i--){
            if(list.get(xi)<list.get(i)){
                yi = i;
                break;
            }
        }

//        swap
        Collections.swap(list, yi, xi);

//        reverse
        if(xi+1 != list.size()-1)
            reverseFrom(list, xi+1);

        return list;
    }

    private static void reverseFrom(List<Integer> list, int startIndex) {
        int endIndex = list.size()-1;
        int half = startIndex + ((endIndex + 1) - startIndex) / 2;
        int endCount = endIndex;
        for (int startCount = startIndex; startCount < half; startCount++) {
            Collections.swap(list, startCount, endCount);
            endCount--;
        }
    }
}
