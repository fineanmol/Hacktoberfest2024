package main

import (
    "fmt"
    "net/http"
)

// This function creates a simple web server that listens on port 8080.
func main() {
    // Create a new HTTP handler.
    http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
        // Write a response to the client.
        fmt.Fprintf(w, "Hello, world!")
    })

    // Start the web server.
    http.ListenAndServe(":8080", nil)
}
