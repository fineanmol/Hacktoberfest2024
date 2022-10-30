class Solution {
    fun singleNumber(nums: IntArray): IntArray {
        var xorResult = 0
        val rightmostSetBit: Int
        var first = 0
        var second = 0

        for (num in nums) {
            xorResult = xorResult xor num
        }

        rightmostSetBit = xorResult and -xorResult

        for (num in nums) {
            if (num and rightmostSetBit == 0) {
                first = first xor num
            } else {
                second = second xor num
            }
        }

        return intArrayOf(first, second)
    }
}

fun main(args: Array<String>) {
    val sol = Solution()
    val nums = intArrayOf(1,2,1,3,2,5)
    val result: IntArray

    result = sol.singleNumber(nums)
    println(result.joinToString())
}
