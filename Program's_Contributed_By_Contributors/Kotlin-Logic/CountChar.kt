package testLogic

fun main() {
    val s = "dani Maulana".filter { it == 'a' }.count()
//    val ss = s.filter {  it == 'a' }.count()
    println(s)

}

fun countOccurrences(s: String, ch: Char): Int {
    return s.filter { it == ch }.count()
}