class ListNode(var `val`: Int = 0) {
    var next: ListNode? = null
}

class LinkedList {
    var head: ListNode? = null

    fun insert(value: Int) {
        val newNode = ListNode(value)
        var tmpNode: ListNode?

        if (head == null) {
            head = newNode
        } else {
            tmpNode = head
            while (tmpNode?.next != null) {
                tmpNode = tmpNode.next
            }
            tmpNode?.next = newNode
        }
    }

    fun printNode() {
        var tmpNode = head
        while (tmpNode != null) {
            print("%d ".format(tmpNode.`val`))
            tmpNode = tmpNode?.next
        }
        println()
    }

}

class Solution {
    fun swapPairs(head: ListNode?): ListNode? {
        var curNode = head
        var newHead = head
        var nextNode: ListNode?
        var preNode: ListNode? = null

        while (curNode != null && curNode?.next != null) {
            nextNode = curNode?.next

            curNode?.next = nextNode?.next
            nextNode?.next = curNode

            if (newHead == head) {
                newHead = nextNode
            } else {
                preNode?.next = nextNode
            }

            preNode = curNode
            curNode = curNode?.next
        }

        return newHead
    }
}

fun main(args: Array<String>) {
    val sol = Solution()
    val ll = LinkedList()

    ll.insert(1)
    ll.insert(2)
    ll.insert(3)
    ll.insert(4)
    ll.printNode()

    ll.head = sol.swapPairs(ll.head)
    ll.printNode()
}
