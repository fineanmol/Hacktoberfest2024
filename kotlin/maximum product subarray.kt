class Solution {
    fun maxProduct(nums: IntArray): Int {
        var maxProduct = nums[0]
        var localMaxProduct = nums[0]
        var localMinProduct = nums[0]
        var leftIdx = 0
        var rightIdx = 0
        var tmpMaxProduct: Int

        for (i in 1 until nums.size) {
            tmpMaxProduct = localMaxProduct

            // localMaxProduct = Math.max(nums[i], Math.max(nums[i]*localMaxProduct, nums[i]*localMinProduct))
            localMaxProduct = Math.max(nums[i]*localMaxProduct, nums[i]*localMinProduct)
            if (nums[i] > Math.max(maxProduct, localMaxProduct) || (localMaxProduct >= tmpMaxProduct && nums[i] > localMaxProduct)) {
                localMaxProduct = nums[i]
                leftIdx = i
            }

            localMinProduct = Math.min(nums[i], Math.min(nums[i]*tmpMaxProduct, nums[i]*localMinProduct))

            if (localMaxProduct > maxProduct) {
                maxProduct = localMaxProduct
                rightIdx = i
            }
        }

        //println("subarray is [%s]".format(nums.copyOfRange(leftIdx, rightIdx+1).joinToString()))

        return maxProduct
    }
}

fun main(args: Array<String>) {
    val sol = Solution()
    val nums = intArrayOf(3, 0, 0, 2, 2) // intArrayOf(3, -1, 4)//intArrayOf(0, 2) // intArrayOf(2, 3, -2, 4)
    val result: Int

    result = sol.maxProduct(nums)
    println(result)
}
