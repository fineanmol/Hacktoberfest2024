class Solution {
    fun hammingDistance(x: Int, y: Int): Int {
        var tmpX = x
        var tmpY = y
        var count = 0
        var isComplementBit: Int

        while (tmpX != 0 || tmpY != 0) {
            isComplementBit = tmpX xor tmpY and 1
            count += isComplementBit
            tmpX = tmpX.shr(1)
            tmpY = tmpY.shr(1)
        }

        return count
    }
}

fun main(args: Array<String>) {
    val sol = Solution()
    val x = 1
    val y = 4
    val result: Int

    result = sol.hammingDistance(x, y)
    println(result)
}
