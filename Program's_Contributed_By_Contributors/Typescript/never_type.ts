const doSomething = (): never => {
	throw "never";
}//this is used when function will never have a return type

const infiniteWhile = (): never => {
	while (true) {
		console.log("Never gonna give you up")
	}
}//Loop runs forever so no return type
