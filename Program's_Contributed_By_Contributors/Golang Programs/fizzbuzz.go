package main

import ( 
	"fmt" 
)

func main() {

	fmt.Print("Enter integer: ")
	var input int
	fmt.Scanf("%d", &input)
	
	for i := 1; i <= input; i++ {
		fizzbuzz(i)	
	}
}

func fizzbuzz(i int) {
	fizz := "fizz"
	buzz := "buzz"
	
	if i % 3 == 0 && i % 5 == 0 {
		fmt.Println(i, fizz + buzz)
	} else if i % 3 == 0 {
		fmt.Println(i, fizz)
	} else if i % 5 == 0 {
		fmt.Println(i, buzz)
	} else {
		fmt.Println(i)
	}
}
