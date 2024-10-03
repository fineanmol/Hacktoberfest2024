package main

import (
	"flag"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type CommandFlags struct {
	Add    string
	Delete int
	Edit   string
	Toggle int
	List   bool
}

func NewCommandFlags() *CommandFlags {
	commandFlag := CommandFlags{}

	flag.StringVar(&commandFlag.Add, "add", "", "Add a new todo specify title")
	flag.StringVar(&commandFlag.Edit, "edit", "", "Edit a todo by index & specify a new title. id:new_title")
	flag.IntVar(&commandFlag.Delete, "delete", -1, "Specify a todo by index to delete")
	flag.IntVar(&commandFlag.Toggle, "toggle", -1, "Specify a todo by index to toggle")
	flag.BoolVar(&commandFlag.List, "list", false, "List all todos")

	flag.Parse()

	return &commandFlag
}

func (commandFlag *CommandFlags) Execute(todos *Todos) {
	switch {
	case commandFlag.List:
		todos.print()

	case commandFlag.Add != "":
		todos.add(commandFlag.Add)

	case commandFlag.Edit != "":
		parts := strings.SplitN(commandFlag.Edit, ":", 2)
		if len(parts) != 2 {
			fmt.Println("Error! Invalid format for edit. Please use id:new_title")
			os.Exit(1)
		}

		index, err := strconv.Atoi(parts[0])

		if err != nil {
			fmt.Println("Error! Invalid index for edit!")
			os.Exit(1)
		}

		todos.edit(index, parts[1])

	case commandFlag.Toggle != -1:
		todos.toggle(commandFlag.Toggle)

	case commandFlag.Delete != -1:
		todos.delete(commandFlag.Delete)

	default:
		fmt.Println("Invalid command!")
	}

}
