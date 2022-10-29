package main

import "fmt"

func inc(a *int) {
	*a = *a + 1
}

func main() {
	a := 0xFF
	fmt.Printf("Variable a of type %T with value %v in hex is %X\n", a, a, a)
	fmt.Println("&a =", &a)

	var pa *int
	pa = &a
	fmt.Printf("pointer pa of type %T with value %v\n", pa, pa)

	b := 2
	pb := &b
	*pb = 10

	fmt.Printf("b = %v\n", b)
	fmt.Printf("data at %v is %v\n", pb, *pb)

	// func new(Type) *Type
	pc := new(int)
	fmt.Printf("data at %v is %v\n", pc, *pc)
	d := 12
	fmt.Printf("d was %v\n", d)
	e := &d
	inc(e)
	fmt.Printf("d is %v\n", *e)

	//arrays
	var x [3]int
	fmt.Println("array ", x)
	x[0] = 5
	x[1] = 7
	x[2] = 3
	fmt.Println("elements ", x[0], x[1], x[2])

	var v [3]int = [3]int{1, 2, 3}
	fmt.Println("array ", v)

	v1 := [...]int{1, 2, 3}
	fmt.Println("array ", v1)

	var v2 = [3]int{1, 2}
	fmt.Println("array ", v2)

	greetings := [5]string{
		"Hello",
		"Good morning",
		"Good afternoon",
		"Good evening",
		"Good night", //must have comma
	}
	fmt.Println(greetings)
	fmt.Println(len(greetings))

	for index, val := range greetings{
		fmt.Printf("greetings[%d] = %v\n", index, val)
	}

	A := [3][2]int{
		[2]int{1, 2},
		[2]int{3, 4},
	}
	fmt.Println(A)

	B := [...][2]int{
		[...]int{1, 2},
		[...]int{3, 4},
		[...]int{5, 6},
	}
	fmt.Println(B)

	C := [3][2]int{{1, 2}, {3, 4}, {5, 6}}
	fmt.Println(C)
}
