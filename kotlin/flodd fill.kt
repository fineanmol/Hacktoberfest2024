class Solution {
    fun floodFill(image: Array<IntArray>, sr: Int, sc: Int, newColor: Int): Array<IntArray> {
        val seenImage = Array(image.size){IntArray(image[0].size){0}}
        val directPixelList: ArrayList<IntArray> = arrayListOf()

        seenImage[sr][sc] = 1
        directPixelList.add(intArrayOf(sr, sc))
        getDirectPixelList(image, sr, sc, directPixelList, seenImage)

        for (it in directPixelList.iterator()) {
            image[it[0]][it[1]] = newColor
        }

        return image
    }

    fun getDirectPixelList(image: Array<IntArray>, sr: Int, sc: Int, directPixelList: ArrayList<IntArray>, seenImage: Array<IntArray>) {
        val tmpPixelList: ArrayList<IntArray> = arrayListOf()
        var newSr: Int
        var newSc: Int
        val rangeArray = intArrayOf(-1, 1)

        for (i in rangeArray.iterator()) {
            newSr = sr + i

            if (newSr < 0 || newSr >= image.size ||
                image[newSr][sc] != image[sr][sc] ||
                seenImage[newSr][sc] == 1) {
                continue
            }

            seenImage[newSr][sc] = 1
            tmpPixelList.add(intArrayOf(newSr, sc))
        }

        for (i in rangeArray.iterator()) {
            newSc = sc + i

            if (newSc < 0 || newSc >= image[0].size ||
                image[sr][newSc] != image[sr][sc] ||
                seenImage[sr][newSc] == 1) {
                continue
            }

            seenImage[sr][newSc] = 1
            tmpPixelList.add(intArrayOf(sr, newSc))
        }

        directPixelList += tmpPixelList

        for (it in tmpPixelList.iterator()) {
            getDirectPixelList(image, it[0], it[1], directPixelList, seenImage)
        }
    }
}

fun main(args: Array<String>) {
    val sol = Solution()
    val image = arrayOf(intArrayOf(1, 1, 1), intArrayOf(1, 1, 0), intArrayOf(1, 0, 1))
    val sr = 1
    val sc = 1
    val newColor = 2
    val result: Array<IntArray>

    result = sol.floodFill(image, sr, sc, newColor)

    for (it in result.iterator()) {
        println(it.toList().toString())
    }
}
