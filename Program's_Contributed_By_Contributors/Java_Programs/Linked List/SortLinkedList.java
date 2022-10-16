class SortLinkedList {
    public ListNode sortList(ListNode head) {
		// base case.
		if (head == null || head.next == null) {
			return head;
		}
		// find middle of linked list
		ListNode mid = findMiddle(head);
		// get mid next as it will be starting point of second list
		ListNode midNext = mid.next;
		// remove mid next node. now list is divided into two halfs one with head and
		// other with midNext
		mid.next = null;
		// call recursively to divide list further
		ListNode left = sortList(head);
		ListNode right = sortList(midNext);
		// merge two sorted list
		return mergeSortedList(left, right);
	}

	private ListNode mergeSortedList(ListNode head1, ListNode head2) {
		// take dummy to avoid additional checks
		ListNode dummy = new ListNode(-1);
		ListNode head = dummy;
		// normal merge logic of two sorted list
		while (head1 != null && head2 != null) {
			if (head1.val < head2.val) {
				dummy.next = head1;
				head1 = head1.next;
			} else {
				dummy.next = head2;
				head2 = head2.next;
			}
			dummy = dummy.next;
		}
		// set remaining list out of two to dummy.next
		dummy.next = head1 == null ? head2 : head1;
		// head returned
		return head.next;
	}

	// find middle element of list. we are returning 1 node before centre as we need
	// to divide it in two halfs
	private ListNode findMiddle(ListNode head) {
		ListNode slow = head;
		ListNode fast = head;
		while (fast != null && fast.next != null && fast.next.next != null) {
			slow = slow.next;
			fast = fast.next.next;
		}
		return slow;
	}
}
