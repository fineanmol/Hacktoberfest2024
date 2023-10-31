package main

import "fmt"

// Function accepting arguments
func add(x int, y int) int {
	total := 0
	total = x + y
	fmt.Println(total)
	return total
}

func main() {
	// Passing arguments
	add(20, 30)
}
