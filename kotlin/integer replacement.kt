class Solution {
    fun integerReplacement(n: Int): Int {
        // iteration
        var num = n.toLong()
        var count = 0

        while (num > 1) {
            count++

            if (num and 1.toLong() == 1.toLong()) {
                if (((num+1) % 4 == 0.toLong()) && (num != 3.toLong())) {
                    num++
                } else {
                    num--
                }
            } else {
                num = num.shr(1)
            }
        }

        return count
    }
}

fun main(args: Array<String>) {
    val sol = Solution()
    val n = 1234 //65535 //7
    val result: Int

    result = sol.integerReplacement(n)
    println(result)
}
