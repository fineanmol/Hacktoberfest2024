package main

import "fmt"

func fib(n int) int {
	if n < 2 {
		return n
	}

	a := 0
	b := 1
	var result int

	for i := 0; i < n; i++ {
		a = b
		b = result
		result = a + b
	}
	return result
}

func main() {
	var n int
	fmt.Print("Enter the value of n: ")
	fmt.Scanf("%d", &n)

	fmt.Println("The nth fibonacci number is", fib(n))
}
