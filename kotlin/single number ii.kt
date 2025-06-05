class Solution {
    fun singleNumber(nums: IntArray): Int {
        var one = 0
        var two = 0
        var three = 0

        for (num in nums) {
            two = two or (one and num)
            one = one xor num
            three = one and two
            one = one and three.inv()
            two = two and three.inv()
        }

        return one
    }
}

fun main(args: Array<String>) {
    val sol = Solution()
    val nums = intArrayOf(2, 2, 3, 2)
    val result: Int

    result = sol.singleNumber(nums)
    println(result)
}
