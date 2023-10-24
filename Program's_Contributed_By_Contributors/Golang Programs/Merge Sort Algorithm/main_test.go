package main

import (
	"math/rand"
	"reflect"
	"testing"
	"time"
)

func TestMergeSort(t *testing.T) {
	// Test case 1: Sorting an empty slice should return an empty slice.
	arr1 := []int{}
	expected1 := []int{}
	result1 := MergeSort(arr1)
	if !reflect.DeepEqual(result1, expected1) {
		t.Errorf("Test case 1 failed. Expected: %v, got: %v", expected1, result1)
	}

	// Test case 2: Sorting a slice with one element should return the same slice.
	arr2 := []int{5}
	expected2 := []int{5}
	result2 := MergeSort(arr2)
	if !reflect.DeepEqual(result2, expected2) {
		t.Errorf("Test case 2 failed. Expected: %v, got: %v", expected2, result2)
	}

	// Test case 3: Sorting a slice with multiple elements.
	arr3 := []int{12, 11, 13, 5, 6, 7}
	expected3 := []int{5, 6, 7, 11, 12, 13}
	result3 := MergeSort(arr3)
	if !reflect.DeepEqual(result3, expected3) {
		t.Errorf("Test case 3 failed. Expected: %v, got: %v", expected3, result3)
	}
}

func generateRandomSlice(size int) []int {
	rand.Seed(time.Now().UnixNano())
	arr := make([]int, size)
	for i := 0; i < size; i++ {
		arr[i] = rand.Intn(1000) // Generate random numbers between 0 and 999
	}
	return arr
}

func BenchmarkMergeSort(b *testing.B) {
	for i := 0; i < b.N; i++ {
		input := generateRandomSlice(1000) // Adjust the slice size as needed
		MergeSort(input)
	}
}
