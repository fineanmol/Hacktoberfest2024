class Solution {
    fun missingNumber(nums: IntArray): Int {
        // sum
        val size = nums.size
        var sum = size*(size+1)/2

        for (num in nums) {
            sum -= num
        }

        return sum

        // xor
        /*
        val size = nums.size
        var result = 0

        for (i in 0 until size) {
            result = result xor (i+1) xor nums[i]
        }

        return result
        */
    }
}

fun main(args: Array<String>) {
    val sol = Solution()
    val nums = intArrayOf(9,6,4,2,3,5,7,0,1)
    val result: Int

    result = sol.missingNumber(nums)
    println(result)
}
