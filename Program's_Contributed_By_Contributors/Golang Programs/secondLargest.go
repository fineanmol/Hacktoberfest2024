package main

import "fmt"

func findSecondLargest(numbers []int) int {
    if len(numbers) < 2 {
        return -1 // Not enough elements to determine the second largest.
    }

    largest, secondLargest := numbers[0], numbers[0]

    for _, num := range numbers {
        if num > largest {
            secondLargest = largest
            largest = num
        } else if num > secondLargest && num < largest {
            secondLargest = num
        }
    }

    return secondLargest
}

func main() {
    numbers := []int{10, 5, 8, 20, 15, 10, 30}
    secondLargest := findSecondLargest(numbers)
    fmt.Printf("The second largest number in the list is: %d\n", secondLargest)
}
