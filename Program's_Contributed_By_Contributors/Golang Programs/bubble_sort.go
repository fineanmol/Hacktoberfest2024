package main

import "fmt"

func main() {
    numbers := []int32{4, 2, 6, 8, 9, 4, 1}

    bubbleSort(numbers)

    fmt.Println(numbers)
}

func bubbleSort(arr []int32) {
    n := len(arr)
    swapped := true
    for swapped {
        swapped = false
        for i := 1; i < n; i++ {
            if arr[i-1] > arr[i] {
                arr[i-1], arr[i] = arr[i], arr[i-1]
                swapped = true
            }
        }
        n--
    }
}
