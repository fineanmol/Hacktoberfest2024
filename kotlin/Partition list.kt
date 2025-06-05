class ListNode(var `val`: Int = 0) {
    var next: ListNode? = null
}

class Solution {
    fun partition(head: ListNode?, x: Int): ListNode? {
        var curNode = head
        var smallerList: ListNode? = ListNode(-1)
        var largerList: ListNode? = ListNode(-1)
        val smallHead = smallerList
        val largeHead = largerList

        while (curNode != null) {
            if (curNode.`val` < x) {
                smallerList?.next = curNode
                smallerList = smallerList?.next
            } else {
                largerList?.next = curNode
                largerList = largerList?.next
            }

            curNode = curNode.next
        }

        smallerList?.next = largeHead?.next
        largerList?.next = null

        return smallHead?.next
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
    val input = intArrayOf(1, 4, 3, 2, 5, 2)
    val x = 3
    var head: ListNode?

    head = sol.buildList(input)
    head = sol.partition(head, x)
    sol.printNode(head)
}
