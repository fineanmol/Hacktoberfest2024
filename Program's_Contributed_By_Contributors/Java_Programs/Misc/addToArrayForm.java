import java.util.*;

public class Codechef {
    public static void main(String[] args) {
        int[] num = {9, 9, 9};
        int k = 1;

        List<Integer> result = addToArrayForm(num, k);
        System.out.println(result);
    }

    static List<Integer> addToArrayForm(int[] num, int k) {
        ArrayList<Integer> ans = new ArrayList<>();

        for (int digit : num) {
            ans.add(digit);
        }

        Collections.reverse(ans);

        int carry = 0;

        int i = 0;
        while (k > 0 || carry > 0) {
            if (i < ans.size()) {
                int sum = ans.get(i) + (k % 10) + carry;
                int digit = sum % 10;
                carry = sum / 10;
                ans.set(i, digit);
            } else {
                int sum = (k % 10) + carry;
                int digit = sum % 10;
                carry = sum / 10;
                ans.add(digit);
            }
            k = k / 10;
            i++;
        }

        Collections.reverse(ans);
        return ans;
    }
}
