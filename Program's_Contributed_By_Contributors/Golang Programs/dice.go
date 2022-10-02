package main

import (
	"fmt"
	"math/rand"
	"time"
)

func roll(side int) int {
	return rand.Intn(side) + 1
}

func main() {
	rand.Seed(time.Now().UnixNano())

	dice, sides := 4, 2
	rolls := 5

	for i := 1; i <= rolls; i++ {
		sum := 0

		for d := 1; d <= dice; d++ {
			rolled := roll(sides)
			sum += rolled
			fmt.Println("Roll-", i, "die-", d, ":", rolled)
		}
		fmt.Println("Total sum=", sum)
		switch sum := sum; {
		case sum == 2 && dice == 2:
			fmt.Println("Snakee eyyes!!")
		case sum == 7:
			fmt.Println("lucky")
		case sum%2 == 0:
			fmt.Println("even")
		case sum%2 == 1:
			fmt.Println("Odd")

		}
	}
}
