package main

func main() {
	todos := Todos{}
	storage := NewStorage[Todos]("todos.json")
	storage.Load(&todos)
	commandFlags := NewCommandFlags()
	commandFlags.Execute(&todos)
	storage.Save(todos)
}
