const addId = <T extends object>(obj: T) => { //can only add object types here
	const id = Math.random().toString(16);
	return {
		...obj,
		id
	}
}

interface UserInterface<T,V>{
	name: string;
	data: T;
	meta: V;
}

const user: UserInterface<{meta: string},number> = {
	name: "Jack",
	data: {
		meta:"Hello"
	},
	meta: 4
}

const user2: UserInterface<string[],string> = {
	name: "John",
	data: ["foo", "bar", "baz"],
	meta : "Doe"
}

const result = addId<object>(user);//explicit declaration of UserInterface type
console.log("result ", result)

//Using generics , we can avoid writing multiple interfaces for small changes
