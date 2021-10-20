//if statements

const x = "20";

if (x === 20) {
  console.log(true);
} else {
  console.log(false);
}

//ternary operators

const y = 20;

const color = y <= 20 ? "red" : "blue";
console.log(color);

//switch case statements

switch (color) {
  case "red":
    console.log("color is red");
    break;
  case "blue":
    console.log("colore is blue");
    break;
  default:
    console.log("color is not red or blue");
    break;
}

//functions

function addNumber(num1, num2) {
  console.log(num1 + num2);
}

addNumber(10, 12);

//fat arrow function

const addNumbers = (num3, num4) => {
  console.log(num3 + num4);
};
addNumbers(100, 89);

//object oriented programming

function Person(firstName, lastName, dob) {
  this.firstName = firstName;
  this.lastName = lastName;
  this.dob = new Date(dob);
}

// Instantiate object
const Person1 = new Person("Akash", "kumar", "2-2-2001");

console.log(Person1);
// alert(Person1.firstName + " " + Person1.lastName + " " + Person1.dob);

//classes

class Person_Class {
  constructor(firstName, lastName, dob) {
    this.firstName = firstName;
    this.lastName = lastName;
    this.dob = new Date(dob);
  }
  getBirthYear() {
    return this.dob.getFullYear();
  }

  getFullName() {
    return `${this.firstName} ${this.lastName}`;
  }
}

const Person_Class_1 = new Person_Class("Harry", "Potter", "4-2-1992");

console.log(Person_Class_1.getFullName());
console.log(Person_Class_1);
