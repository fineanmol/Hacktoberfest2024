class Solution {
    fun bulbSwitch(n: Int): Int {
        return Math.sqrt(n.toDouble()).toInt()
    }
}

fun main(args: Array<String>) {
    val sol = Solution()
    val n = 3 //99999999
    val result: Int

    result = sol.bulbSwitch(n)
    println(result)
}
