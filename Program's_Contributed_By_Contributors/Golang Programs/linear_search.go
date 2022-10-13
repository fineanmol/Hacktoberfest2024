package main
import "fmt"

func linearSearch(A []int, n int, x int) {
 for i := 0; i < n; i++ {
  if A[i] == x {
   fmt.Println("Number found at position : ", i+1)
   return
  }
 }

 fmt.Println("Number not found")
 return

}

func main() {
 fmt.Println("Enter the size of the array")
 var n int
 fmt.Scan(&n)

 var x int
 A := make([]int, n, 100)
fmt.Println("Enter elements of the array : ")

 for i := 0; i < n; i++ {
  fmt.Scan(&A[i])
 }

 fmt.Println("Enter the number to be searched")
 fmt.Scan(&x)

 linearSearch(A, n, x)

}
