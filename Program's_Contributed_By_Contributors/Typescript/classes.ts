interface UserInterface{
	getFullname(): string
}

class User implements UserInterface {
	private	firstName: string //can't be accessed or inherited
	private lastName: string
	readonly unchangeableName:string //cant be modified (immutable)
	static secretNumber : number = 20
	constructor(firstName: string, lastName: string) {
		this.firstName = firstName
		this.lastName = lastName
		this.unchangeableName = firstName
	}

	getFullname(): string {
		return this.firstName + " " + this.lastName
	}
}

class Admin extends User {
	private editor: string
	
	setEditor(editor: string): void{
		this.editor = editor
	}

	getEditor(): string{
		return this.editor
	}
}

const user = new User("John", "Doe")
console.log(user) //.firstName doesnt work
console.log(User.secretNumber) // cant do this in an object, only in a class
console.log(Admin.secretNumber) //even inherited cl;asses can access

