package main

import "fmt"

type Node struct {
	value int
	next  *Node
}

var head *Node = nil

func push(value int) {
	newNode := Node{value: value}
	newNode.next = nil
	if head == nil {
		head = &newNode
	} else {
		newNode.next = head
		head = &newNode
	}
}
func pop() int {
	if head == nil {
		fmt.Println("Stack is empty")
		return 0
	}
	value := head.value
	head = head.next
	return value
}
func printStack() {
	if head == nil {
		fmt.Println("Stack is empty")
		return
	}
	temp := head
	for temp.next != nil {
		fmt.Print(temp.value, "->")
		temp = temp.next
	}
	fmt.Println(temp.value)
}

func Basic03() {
	push(5)
	push(20)
	push(40)
	fmt.Println("Pop Stack : ", pop())
	push(6)
	printStack()

}
