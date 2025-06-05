package main

import (
	_ "github.com/go-sql-driver/mysql"
	"github.com/jmoiron/sqlx"
	"log"
)

type User struct {
	Id int
	First, Last, Email string
}

func main() {
	db, err := sqlx.Connect("mysql", "root:@(localhost:3306)/user")
	if err != nil {
		log.Fatalln(err)
	}

	user := []User{}

	db.Select(&user, "Select * from users")

	log.Println("users...")
	log.Println(user)

}