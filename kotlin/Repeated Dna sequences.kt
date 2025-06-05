class Solution {
    fun findRepeatedDnaSequences(s: String): List<String> {
        val map: HashMap<Char, Int> = hashMapOf('A' to 0, 'C' to 1, 'G' to 2, 'T' to 3)
        val firstSet = hashSetOf<Int>()
        val secondSet = hashSetOf<Int>()
        var result = listOf<String>()
        var subNum: Int
        val subLen = 10
        val lastIndex = s.length - subLen

        for (i in 0..lastIndex) {
            subNum = 0
            for (j in i until i+subLen) {
                subNum = subNum.shl(2)
                subNum = subNum or map.getValue(s[j])
            }

            if (!firstSet.add(subNum) && secondSet.add(subNum)) {
                result += listOf(s.substring(i, i+subLen))
            }
        }

        return result
    }
}

fun main(args: Array<String>) {
    val sol = Solution()
    val s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
    val result: List<String>

    result = sol.findRepeatedDnaSequences(s)
    println(result)
}
