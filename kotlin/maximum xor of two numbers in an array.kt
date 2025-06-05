class Solution {
    fun findMaximumXOR(nums: IntArray): Int {
        var set: HashSet<Int>
        var mask = 0
        var max = 0
        var tmpMax: Int

        for (i in 31 downTo 0) {
            set = HashSet()
            mask = mask or 1.shl(i)
            for (j in nums) {
                set.add(mask and j)
            }

            tmpMax = max or 1.shl(i)
            for (j in set) {
                if (set.contains(tmpMax xor j)) {
                    max = tmpMax
                    break
                }
            }
        }

        return max
    }
}

fun main(args: Array<String>) {
    val sol = Solution()
    val nums = intArrayOf(14, 11, 7, 2)
    val result: Int

    result = sol.findMaximumXOR(nums)
    println(result)
}
