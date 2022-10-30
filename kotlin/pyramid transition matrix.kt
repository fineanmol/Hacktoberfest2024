class Solution {
    fun pyramidTransition(bottom: String, allowed: List<String>): Boolean {
        val charMap =  HashMap<Char, List<CharArray>>()
        var tmpArray: CharArray
        var tmpChar: Char
        val size = bottom.length
        val dp = Array(size){Array(size){Array(26){false}}}
        var result = false

        for (triple in allowed) {
            tmpChar = triple[2]
            tmpArray = charArrayOf(triple[0], triple[1])

            if (charMap.containsKey(tmpChar)) {
                charMap[tmpChar] = charMap.getValue(tmpChar) + listOf(tmpArray)
            } else {
                charMap.put(tmpChar, listOf(tmpArray))
            }
        }

        for (i in 0 until size) {
            dp[size-1][i][bottom[i]-'A'] = true
        }

        for (i in size-2 downTo 0) {
            for (j in 0..i) {
                for (char in 'A'..'G') {
                    if (!charMap.containsKey(char)) {
                        continue
                    }

                    for (charArray in charMap.getValue(char)) {
                        if (dp[i+1][j][charArray[0]-'A'] && dp[i+1][j+1][charArray[1]-'A']) {
                            dp[i][j][char-'A'] = true
                        }
                    }
                }
            }
        }

        for (char in 'A'..'G') {
            if (dp[0][0][char-'A']) {
                result = true
                break
            }
        }

        return result
    }
}

fun main(args: Array<String>) {
    val sol = Solution()
    val bottom = "XXYX" // ""XYZ"
    val allowed = listOf("XXX", "XXY", "XYX", "XYY", "YXZ") // listOf("XYD", "YZE", "DEA", "FFF")
    val result: Boolean

    result = sol.pyramidTransition(bottom, allowed)
    println(result)
}
