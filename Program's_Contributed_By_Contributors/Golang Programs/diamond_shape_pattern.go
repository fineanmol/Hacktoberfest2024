package main

import "fmt"

func main() {
	var n int
	var k int
	fmt.Print("Enter a number: ")
	fmt.Scanf("%d", &n)
	k = 2*n - 2
	for i := 0; i < n; i++ {
		for j := 0; j < k; j++ {
			fmt.Printf(" ")
		}
		k = k - 1
		for j := 0; j < i+1; j++ {
			fmt.Printf("* ")
		}
		fmt.Println("")
	}
	k = n - 2
	for i := n; i > -1; i-- {
		for j := k; j > 0; j-- {
			fmt.Printf(" ")
		}
		k = k + 1
		for j := 0; j < i+1; j++ {
			fmt.Printf("* ")
		}
		fmt.Println("")
	}
}
