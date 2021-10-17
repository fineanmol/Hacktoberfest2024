const names =
  "Akash Kumar , Roshan kumar , Tarun singh , Harneet Kaur , Deepak , Abhi";

const age = 20;

console.log(names.split(", "));

//Arrays

const numbers = new Array(1, 2, 3, 3, 4, 4, 5, 5, 5, 5);

console.log(numbers);

const Names = ["Akash", "kumar", "sharma", 20, "student"];
Names.push("Lovely professional university");
Names.unshift("Mr.");

console.log(Names);

console.log(Names.indexOf("kumar"));

console.log(Names[0] + " " + Names[1]);

//Object literals

const Person = {
  firstName: "Akash",
  middleName: "kumar",
  lastName: "sharma",
  age: 20,
  hobbies: ["music", "football", "cricket", "programming", "movies"],
  college: "Lovely proffessional university",
  address: {
    street: "Ih 131 jct mill thapar colony",
    city: "Phagwara",
    state: "Punjab",
    country: "India",
    pinCode: 144401,
  },
};

Person.email = "akaysharma894@gmail.com";
console.log(Person);

console.log(Person.address.pinCode);

//making Todos

const todos = [
  { id: 1, text: "Learn Javascript", isComplete: true },
  { id: 2, text: "Learn React", isComplete: false },
  { id: 3, text: "Learn Node.js", isComplete: false },
];

const todoJSON = JSON.stringify(todos);

console.log(todoJSON);

//for Loop

for (let i = 0; i < todos.length; i++) {
  console.log(todos[i].text);
}

for (let todo of todos) {
  console.log(todo.id, todo.text, todo.isComplete);
}

//higher order functions

//1. for each
todos.forEach((todo) => {
  console.log(todo.text);
});

//2. map

const todoText = todos.map((todo) => {
  return todo.text;
});

console.log(todoText);

//3. filter

const todoCompleted = todos
  .filter((todo) => {
    return todo.isComplete === true;
  })
  .map((todo) => {
    return todo.text;
  });

alert(todoCompleted);
