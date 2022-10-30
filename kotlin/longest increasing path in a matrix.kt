class Solution {
    val dirMatrix = arrayOf(intArrayOf(1, 0), intArrayOf(-1, 0), intArrayOf(0, -1), intArrayOf(0, 1))
    var yLen: Int = 0
    var xLen: Int = 0

    fun longestIncreasingPath(matrix: Array<IntArray>): Int {
        yLen = matrix.size
        if (yLen == 0) {
            return yLen
        }
        xLen = matrix[0].size
        val lenMatrix = Array(yLen, { IntArray(xLen, { 0 }) })
        var maxLen = 0

        for (j in 0 until yLen) {
            for (i in 0 until xLen) {
                maxLen = Math.max(maxLen, dfs(matrix, lenMatrix, i, j))
            }
        }

        return maxLen
    }

    fun dfs(matrix: Array<IntArray>, lenMatrix: Array<IntArray>, x: Int, y: Int): Int {
        var len: Int = lenMatrix[y][x]
        var i: Int
        var j: Int

        if (len > 0) {
            return len
        } else {
            len = 1
        }

        for (dir in dirMatrix) {
            j = y + dir[0]
            i = x + dir[1]

            if (j < 0 || j >= yLen || i < 0 || i >= xLen || matrix[j][i] <= matrix[y][x]) {
                continue
            }

            len = Math.max(len, 1 + dfs(matrix, lenMatrix, i, j))
        }

        lenMatrix[y][x] = len

        return len
    }
}

fun main(args: Array<String>) {
    val sol = Solution()
    //val matrix: Array<IntArray> = arrayOf(intArrayOf(9, 9, 4), intArrayOf(6, 6, 8), intArrayOf(2, 1, 1))
    val matrix = arrayOf(intArrayOf(3, 4, 5), intArrayOf(3, 2, 6), intArrayOf(2, 2, 1))
    val result: Int

    result = sol.longestIncreasingPath(matrix)
    println(result)
}
