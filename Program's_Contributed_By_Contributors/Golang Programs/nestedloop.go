package main

import "fmt"

func main() {
    // Define the number of rows and columns
    rows := 3
    columns := 4

    // Nested loop to iterate over rows and columns
    for i := 0; i < rows; i++ {
        for j := 0; j < columns; j++ {
            fmt.Printf("(%d, %d) ", i, j)
        }
        fmt.Println() // Move to the next line after each row
    }
}
