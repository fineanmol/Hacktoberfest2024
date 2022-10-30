class Solution {
    fun isToeplitzMatrix(matrix: Array<IntArray>): Boolean {
        val x = 0
        val y = 0
        var value: Int
        var ii: Int
        var jj: Int
        val xSize = matrix.size
        val ySize = matrix[0].size

        for (j in 0 until ySize) {
            value = matrix[x][j]
            ii = x + 1
            jj = j + 1
            while (ii < xSize && jj < ySize) {
                if (matrix[ii][jj] != value) {
                    return false
                }
                ii++
                jj++
            }
        }

        for (i in 0 until xSize) {
            value = matrix[i][y]
            ii = i + 1
            jj = y + 1
            while (ii < xSize && jj < ySize) {
                if (matrix[ii][jj] != value) {
                    return false
                }
                ii++
                jj++
            }

        }

        return true
    }
}

fun main(args: Array<String>) {
    val sol = Solution()
    val matrix = arrayOf(intArrayOf(1, 2), intArrayOf(2, 2))// arrayOf(intArrayOf(1, 2, 3, 4), intArrayOf(5, 1, 2, 3), intArrayOf(9, 5, 1, 2))
    val result: Boolean

    result = sol.isToeplitzMatrix(matrix)
    println(result)
}
