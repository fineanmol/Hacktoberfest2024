package main

import "fmt"

func leapYear(n int) {
	if n%4 == 0 {
		if n%100 != 0 {
			fmt.Println("It's a Leap Year")
		} else {
			fmt.Println("Not a Leap Year ")
		}
	} else {
		fmt.Println("Not a Leap Year")
	}
}
func main() {
	leapYear(2020)
}
