class ListNode(var `val`: Int = 0) {
    var next: ListNode? = null
}

class Solution {
    fun removeNthFromEnd(head: ListNode?, n: Int): ListNode? {
        var nodeNum = 1
        var curNode = head
        val preNodeOrder: Int
        val dummyHead = ListNode(-1)

        while (curNode?.next != null) {
            nodeNum++
            curNode = curNode.next
        }

        dummyHead.next = head
        curNode = dummyHead
        preNodeOrder = nodeNum - n
        for (i in 0 until preNodeOrder) {
            curNode = curNode?.next
        }

        curNode?.next = curNode?.next?.next

        return dummyHead.next
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
    head = sol.removeNthFromEnd(head, x)
    sol.printNode(head)
}
