package main

import "fmt"

// MergeSort function
func MergeSort(arr []int) []int {
	if len(arr) <= 1 {
		return arr
	}

	mid := len(arr) / 2
	left := arr[:mid]
	right := arr[mid:]

	left = MergeSort(left)
	right = MergeSort(right)

	return merge(left, right)
}

// merge function
func merge(left, right []int) []int {
	result := make([]int, 0)

	for len(left) > 0 || len(right) > 0 {
		if len(left) > 0 && len(right) > 0 {
			if left[0] <= right[0] {
				result = append(result, left[0])
				left = left[1:]
			} else {
				result = append(result, right[0])
				right = right[1:]
			}
		} else if len(left) > 0 {
			result = append(result, left[0])
			left = left[1:]
		} else if len(right) > 0 {
			result = append(result, right[0])
			right = right[1:]
		}
	}

	return result
}

func main() {
	arr := []int{12, 11, 13, 5, 6, 7}
	fmt.Println("Unsorted array:", arr)
	sortedArr := MergeSort(arr)
	fmt.Println("Sorted array:", sortedArr)
}
