public class SwapNodesInPairs {
    // LEETCODE 24
    public static void main(String[] args) {
        // call your fn here
    }

    class Solution {
        public ListNode swapPairs(ListNode head) {
            if ((head == null) || (head.next == null)) {
                return head;
            }
            ListNode n = head.next;
            head.next = swapPairs(head.next.next);
            n.next = head;
            return n;

        }
    }
}
