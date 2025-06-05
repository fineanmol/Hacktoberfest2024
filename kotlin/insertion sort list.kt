class ListNode(var `val`: Int = 0) {
    var next: ListNode? = null
}

class Solution {
    fun insertionSortList(head: ListNode?): ListNode? {
        if (head?.next == null) {
            return head
        }

        val dummyHead = ListNode(-1)
        var curNode = head
        var insertedNode: ListNode?
        var checkNode: ListNode?

        dummyHead.next = head

        while (curNode?.next != null) {
            if (curNode.`val` <= curNode.next!!.`val`) {
                curNode = curNode.next
            } else {
                insertedNode = curNode.next
                curNode.next = insertedNode?.next

                checkNode = dummyHead
                while (checkNode?.next!!.`val` <= insertedNode!!.`val`) {
                    checkNode = checkNode.next
                }
                insertedNode.next = checkNode.next
                checkNode.next = insertedNode
            }
        }

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
    val input = intArrayOf(4, 2, 1, 3)
    val head: ListNode?
    val result: ListNode?

    head = sol.buildList(input)
    result = sol.insertionSortList(head)
    sol.printNode(result)
}
