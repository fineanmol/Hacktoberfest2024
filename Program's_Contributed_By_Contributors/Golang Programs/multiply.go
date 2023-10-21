package main

import "fmt"

// Function accepting arguments
func mul(x int, y int) {
	total := 0
	total = x * y
	fmt.Println(total)
}

func main() {
	// Passing arguments
	mul(20, 30)
}
