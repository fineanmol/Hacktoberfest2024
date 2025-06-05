class Solution {
    fun majorityElement(nums: IntArray): Int {
        var majority = nums[0]
        var count = 0

        for (i in 0 until nums.size) {
            if (count == 0) {
                majority = nums[i]
                count = 1
                continue
            }

            if (nums[i] == majority) {
                count++
            } else {
                count--
            }
        }

        return majority
    }
}

fun main(args: Array<String>) {
    val sol = Solution()
    val nums = intArrayOf(3, 2, 3) //intArrayOf(2, 2, 1, 1, 1, 2, 2)
    val result: Int

    result = sol.majorityElement(nums)
    println(result)
}
