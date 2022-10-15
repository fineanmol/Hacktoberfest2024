fun main() {

    var a = intArrayOf(1, 2, 3, 4, 5)
    var b = intArrayOf(1, 2, 3, 4, 5)

    print('Enter the number to be added: ')
    var input = readLine()!!.toInt()

    var c = a + b + input
    println(c)

    # Output will differ from the expected output
    # Above line will give error if uncommented
}