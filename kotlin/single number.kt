class Solution {
    fun singleNumber(nums: IntArray): Int {
        var result = 0

        for (i in nums) {
            result = i xor result
        }

        return result
    }
}

fun main(args: Array<String>) {
    val sol = Solution()
    val nums = intArrayOf(4, 1, 2, 1, 2)
    val result: Int

    result = sol.singleNumber(nums)
    println(result)
}
