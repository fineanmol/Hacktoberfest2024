package main

import "fmt"

// Function accepting arguments
func sub(x int, y int) {
	total := 0
	total = x - y
	fmt.Println(total)
}

func main() {
	// Passing arguments
	sub(20, 30)
}
