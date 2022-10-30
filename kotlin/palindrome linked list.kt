class ListNode(var `val`: Int = 0) {
    var next: ListNode? = null
}

class Solution {
    fun isPalindrome(head: ListNode?): Boolean {
        var slowPointer = head
        var fastPointer = head
        var newHead: ListNode?
        var curNode: ListNode?
        var result = true

        while (fastPointer != null && fastPointer.next != null) {
            fastPointer = fastPointer.next?.next
            slowPointer = slowPointer?.next
        }

        if (fastPointer != null) {
            slowPointer = slowPointer?.next
        }

        newHead = reverseList(slowPointer)

        curNode = head
        while (newHead != null && curNode != null) {
            if (newHead.`val` != curNode.`val`) {
                result = false
                break
            }

            newHead = newHead.next
            curNode = curNode.next
        }

        return result
    }

    fun reverseList(head: ListNode?): ListNode? {
        var preNode: ListNode? = null
        var nextNode: ListNode?
        var curNode = head

        while (curNode != null) {
            nextNode = curNode.next
            curNode.next = preNode
            preNode = curNode
            curNode = nextNode
        }

        return preNode
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
    val input = intArrayOf(1, 2, 2, 1)
    val head: ListNode?
    val result: Boolean

    head = sol.buildList(input)
    result = sol.isPalindrome(head)
    println(result)
}
