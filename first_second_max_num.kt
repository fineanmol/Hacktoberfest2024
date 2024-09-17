fun main(){
        val simpleArray = arrayOf(1, 55, 20, 99, 23, 34, 88, 72, 61, 43)

        var min = Integer.MIN_VALUE
        var largestElement = Integer.MIN_VALUE
        for(i in simpleArray) {
            if(i > largestElement) {
                min = largestElement
                largestElement = i
            } else if(i > min) {
                min = i
            }
        }
        println("second max Number : $min")
        println("max Number : $largestElement")
    }
