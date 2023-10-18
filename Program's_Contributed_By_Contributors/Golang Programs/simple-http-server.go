package main

import (
	"fmt"
	"log"
	"net/http" // function to create web server
)

func helloHandler(w http.ResponseWriter, req *http.Request) {
	if req.URL.Path != "/hello" {
		http.Error(w, "404 not found", http.StatusNotFound)
		return
	}
	if req.Method != "GET" {
		http.Error(w, "Method not supported!", http.StatusNotFound)
		return
	}
	fmt.Fprintf(w, "Hello!")
}

func formHandler(w http.ResponseWriter, req *http.Request) {
	if err := req.ParseForm(); err != nil {
		fmt.Fprintf(w, "ParseForm() err: %v", err)
		return
	}
	fmt.Fprintf(w, "POST request successful!\n")
	name := req.FormValue("name")
	address := req.FormValue("address")
	phone := req.FormValue("phone")
	fmt.Fprintf(w, "Name = %s\n", name)
	fmt.Fprintf(w, "Address = %s\n", address)
	fmt.Fprintf(w, "Phone = %s\n", phone)
}

// driver function
func main() {
	fileServer := http.FileServer(http.Dir("./static"))
	http.Handle("/", fileServer)
	http.HandleFunc("/form", formHandler)   // handles form
	http.HandleFunc("/hello", helloHandler) // prints hello

	fmt.Printf("Starting Server at port 8080\n")

	if err := http.ListenAndServe(":8080", nil); err != nil {
		log.Fatal(err)
	}
}
