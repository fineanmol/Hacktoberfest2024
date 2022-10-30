class Solution {
    fun leastInterval(tasks: CharArray, n: Int): Int {
        val map: HashMap<Char, Int> = hashMapOf()

        for (task in tasks.iterator()) {
            if (!map.containsKey(task)) {
                map[task] = 1
                continue
            }

            map[task] = map.getValue(task) + 1
        }

        val maxTaskMap: Map<Char, Int>
        var maxTaskNum = 0

        for (item in map) {
            if (item.value > maxTaskNum) {
                maxTaskNum = item.value
            }
        }

        maxTaskMap = map.filter { it.value == maxTaskNum }

        return Math.max( tasks.size, (maxTaskNum-1) * (n+1) + maxTaskMap.size )
    }
}

fun main(args: Array<String>) {
    val sol = Solution()
    val tasks = charArrayOf('A', 'A', 'A', 'B', 'B', 'B')
    val n = 0//2
    val result: Int

    result = sol.leastInterval(tasks, n)
    println(result)
}
