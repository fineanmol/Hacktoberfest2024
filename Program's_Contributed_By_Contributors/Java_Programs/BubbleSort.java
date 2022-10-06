import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BubbleSort {
    public static void main(String[] args) throws IOException {
        int[] input = input();
        input = bubbleSort(input, input.length);
        output(input);
    }

    private static int[] bubbleSort(int[] input, int length) {
        int tmp;
        for (int i = length - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (input[j] > input[j + 1]) {
                    tmp = input[j];
                    input[j] = input[j + 1];
                    input[j + 1] = tmp;
                }
            }
        }
        return input;
    }

    private static int[] input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("array length : ");
        int num = Integer.parseInt(br.readLine());
        int[] arr = new int[num];

        for (int i=0; i<num; i++){
            System.out.print(i+"th value in arr : ");
            arr[i] = Integer.parseInt(br.readLine());
        }
        return arr;
    }

    private static void output(int[] arr) {
        for (int a : arr) {
            System.out.print(a + " ");
        }
    }
}
