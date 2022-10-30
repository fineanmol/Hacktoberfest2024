class ListNode(var `val`: Int = 0) {
    var next: ListNode? = null
}

class Solution {
    fun reorderList(head: ListNode?): Unit {
        if (head?.next?.next == null) {
            return
        }

        // find second half
        var slow: ListNode? = head
        var fast: ListNode? = head
        var head2: ListNode?

        while (fast?.next?.next != null) {
            slow = slow?.next
            fast = fast.next?.next
        }

        head2 = slow?.next
        slow?.next = null

        // reverse second half
        var tmpNode: ListNode? = null
        var nextNode: ListNode?
        while (head2 != null) {
            nextNode = head2.next
            head2.next = tmpNode
            tmpNode = head2
            head2 = nextNode
        }
        head2 = tmpNode

        // insert reversed second half to first half
        var nextNode2: ListNode?
        var head1 = head
        while (head1 != null || head2 != null) {
            nextNode = head1?.next
            nextNode2 = head2?.next

            head1?.next = head2
            head2?.next = nextNode

            head1 = nextNode
            head2 = nextNode2
        }
    }

    fun buildList(input: IntArray): ListNode? {
        var head: ListNode? = null
        var tmp: ListNode?

        for (i in input.lastIndex downTo 0) {
            tmp = ListNode(input[i])
            tmp.next = head
            head = tmp
        }

        return head
    }
}

fun main(args: Array<String>) {
    val sol = Solution()
    val input = intArrayOf(1, 2, 3, 4, 5)
    val head: ListNode?

    head = sol.buildList(input)
    sol.reorderList(head)
}
