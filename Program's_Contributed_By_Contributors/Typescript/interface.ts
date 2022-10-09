interface UserInterface {
	name: string
	age?: number //makes age optional can be present or not
	getMessage():string
}

const user: UserInterface = {
	name: "Moster",
	age: 30,
	getMessage() {
		return "Hello " + this.name
	} 	
}

const user2: UserInterface = {
	name: "Jack",
	getMessage() {
		return "Hello " + this.name
	}
}

console.log(user.getMessage())
