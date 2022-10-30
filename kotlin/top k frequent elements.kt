import java.util.PriorityQueue
class Solution {
    fun topKFrequent(nums: IntArray, k: Int): List<Int> {
        val map = hashMapOf<Int, Int>()
        val result: ArrayList<Int> = arrayListOf()
        for (item in nums) {
            map[item] = map.getOrDefault(item, 0) + 1
        }
        val maxHeap = PriorityQueue<Int> {a, b -> map.getValue(b) - map.getValue(a)}
        map.forEach { key, _ ->
                maxHeap.add(key)
        }
        for (i in 0 until k) {
            result.add(maxHeap.poll())
        }
        return result.toList()
    }
}
fun main(args: Array<String>) {
    val sol = Solution()
    val nums = intArrayOf(1, 1, 1, 2, 2, 3)
    val k = 2
    val result: List<Int>

    result = sol.topKFrequent(nums, k)
    println(result)
}
