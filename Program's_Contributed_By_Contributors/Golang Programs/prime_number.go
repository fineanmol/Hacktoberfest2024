package main

import (
	"fmt"
)

func isPrime(n int) bool {
	if n <= 1 {
		return false
	}
	if n <= 3 {
		return true
	}
	if n%2 == 0 || n%3 == 0 {
		return false
	}
	for i := 5; i*i <= n; i += 6 {
		if n%i == 0 || n%(i+2) == 0 {
			return false
		}
	}
	return true
}

func main() {
	var number int
	fmt.Print("Enter a number: ")
	fmt.Scan(&number)

	if isPrime(number) {
		fmt.Printf("%d is a prime number.\n", number)
	} else {
		fmt.Printf("%d is not a prime number.\n", number)
	}
}
