class ListNode(var `val`: Int = 0) {
    var next: ListNode? = null
}

class Solution {
    fun mergeKLists(lists: Array<ListNode?>): ListNode? {
        val listNum = lists.size

        when (listNum) {
            0 -> return null
            1 -> return lists[0]
        }

        return mergeLists(lists, 0, listNum-1)
    }

    fun mergeLists(lists: Array<ListNode?>, leftIdx: Int, rightIdx: Int): ListNode? {
        val diffIdx: Int = rightIdx - leftIdx
        val result: ListNode?

        result = when (diffIdx) {
            0 -> lists[leftIdx]
            1 -> mergeTwoLists(lists[leftIdx], lists[rightIdx])
            else -> {
                val middleIdx: Int = diffIdx / 2 + leftIdx
                mergeTwoLists(mergeLists(lists, leftIdx, middleIdx), mergeLists(lists, middleIdx+1, rightIdx) )
            }
        }

        return result
    }

    fun mergeTwoLists(firstList: ListNode?, secondList: ListNode?): ListNode? {
        var dummyHead: ListNode? = ListNode(-1)
        var curNode = dummyHead
        var list1 = firstList
        var list2 = secondList

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

        return dummyHead?.next
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
    val input1 = intArrayOf(1, 4, 5)
    val input2 = intArrayOf(1, 3, 4)
    val input3 = intArrayOf(2, 6)
    val list1: ListNode?
    val list2: ListNode?
    val list3: ListNode?
    val lists: Array<ListNode?>
    val head: ListNode?

    list1 = sol.buildList(input1)
    list2 = sol.buildList(input2)
    list3 = sol.buildList(input3)
    lists = arrayOf(list1, list2, list3)
    head = sol.mergeKLists(lists)
    sol.printNode(head)
}
