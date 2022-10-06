/**
 * Based on my submission to the Java Programming Challenge at LeetCode.com
 * https://leetcode.com/problems/add-two-numbers/
 * Basically you have two linked lists, each representing a number, and you need to add them together.
 * The catch is that the numbers are stored in reverse order, so the first node in the list is the least significant digit.
 */
public class AddTwoNumbers {

    public static void main(String[] args) {
        var l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
        var l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

        var result = addTwoNumbers(l1, l2);

        System.out.println("======================");
        while (result != null) {
            System.out.println(result.val);
            result = result.next;
        }
        System.out.println("======================");
    }

    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        return addTwoNumbers(l1, l2, false);
    }

    public static ListNode addTwoNumbers(ListNode l1, ListNode l2, boolean overflow) {
        var left = l1 == null ? 0 : l1.val;
        var right = l2 == null ? 0 : l2.val;

        var summary = left + right + (overflow ? 1 : 0);
        var remain = summary >= 10 ? summary - 10 : summary;

        var leftNext = l1 != null ? l1.next : null;
        var rightNext = l2 != null ? l2.next : null;

        if (leftNext == null && rightNext == null) {
            if (summary >= 10) {
                return new ListNode(remain, addTwoNumbers(null, null, true));
            } else {
                return new ListNode(summary);
            }
        }

        return new ListNode(summary >= 10 ? remain : summary, addTwoNumbers(leftNext, rightNext, summary >= 10));
    }

    public static class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }
}
