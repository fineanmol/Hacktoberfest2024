class Solution {
    fun strStr(haystack: String, needle: String): Int {
        var index = -1
        var isMatched: Boolean
        val checkEndIndex = haystack.length - needle.length

        if (checkEndIndex < 0) {
            return index
        }

        for (i in 0..checkEndIndex) {
            isMatched = true
            for (j in 0 until needle.length) {
                if (haystack[i+j] != needle[j]) {
                    isMatched = false
                    break
                }
            }

            if (isMatched) {
                index = i
                break
            }
        }

        return index
    }
}

fun main(args: Array<String>) {
    val haystack = "mississippi" // "aaaaa", "hello"
    val needle = "mississippi" // "bba", 'll'
    val sol = Solution()
    val index: Int

    index = sol.strStr(haystack, needle)
    println(index)
}
