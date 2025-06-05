class ListNode(var `val`: Int = 0) {
    var next: ListNode? = null
}

class Solution {
    fun sortList(head: ListNode?): ListNode? {
        if (head?.next == null) {
            return head
        }

        val mid = findMid(head)
        val rightList = sortList(mid?.next)
        mid?.next = null
        val leftList = sortList(head)

        return mergeList(leftList, rightList)
    }

    private fun findMid(head: ListNode?): ListNode? {
        var slow = head
        var fast = head

        while (fast?.next?.next != null) {
            slow = slow?.next
            fast = fast.next?.next
        }

        return slow
    }

    private fun mergeList(leftList: ListNode?, rightList: ListNode?): ListNode? {
        var list1 = leftList
        var list2 = rightList
        val result = ListNode(-1)
        var curNode: ListNode? = result

        while (list1 != null && list2 != null) {
            if (list1.`val` < list2.`val`) {
                curNode?.next = list1
                list1 = list1.next
            } else {
                curNode?.next = list2
                list2 = list2.next
            }

            curNode = curNode?.next
        }

        if (list1 != null) {
            curNode?.next = list1
        }

        if (list2 != null) {
            curNode?.next = list2
        }

        return result.next
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
    result = sol.sortList(head)
    sol.printNode(result)
}
