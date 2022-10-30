class ListNode(var `val`: Int = 0) {
    var next: ListNode? = null
}

class Solution {
    fun reverseKGroup(head: ListNode?, k: Int): ListNode? {
        val dummyHead: ListNode? = ListNode(-1)
        var newHead: ListNode? = dummyHead

        dummyHead?.next = head

        while (newHead != null) {
            newHead = reverseK(newHead, k)
        }

        return dummyHead?.next
    }

    fun reverseK(head: ListNode?, k: Int): ListNode? {
        var newHead = head
        var curNode: ListNode?
        var nextNode: ListNode?
        var preNode: ListNode?

        for (i in 0 until k) {
            newHead = newHead?.next
        }

        if (newHead == null) {
            return newHead
        }

        curNode = head?.next?.next
        preNode = head?.next
        preNode?.next = newHead.next
        newHead = head?.next

        for (i in 1 until k) {
            nextNode = curNode?.next
            curNode?.next = preNode
            head?.next = curNode
            preNode = curNode
            curNode = nextNode
        }

        return newHead
    }

    fun printNode(head: ListNode?) {
        var tmpNode = head

        while (tmpNode != null) {
            print("%d, ".format(tmpNode.`val`))
            tmpNode = tmpNode.next
        }
        println()
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
    val x = 2
    var head: ListNode?

    head = sol.buildList(input)
    head = sol.reverseKGroup(head, x)
    sol.printNode(head)
}
