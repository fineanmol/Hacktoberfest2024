// Overview of Armstrong Number in JavaScript
// An Armstrong number is a number whose sum of cubes of all the digits will equal itself. In general, it is also called a narcissistic number.
//   The narcissistic number proposes that the number is said to be narcissistic or Armstrong’s number if the sum of all of its digits 
//   raised to the power n, where n is the number of digits, is equal to the number itself.

// Given below is an example of a three-digit number:

// 153 = (1)3 + (5)3 + (3)3

// = (1 * 1 * 1) + (5 * 5 * 5) + (3 * 3 * 3)

// = 1 + 125 + 27

// = 153


// program to check an Armstrong number of three digits

let sum = 0;
const number = prompt('Enter a three-digit positive integer: ');

// create a temporary variable
let temp = number;
while (temp > 0) {
    // finding the one's digit
    let remainder = temp % 10;

    sum += remainder * remainder * remainder;

    // removing last digit from the number
    temp = parseInt(temp / 10); // convert float into integer
}
// check the condition
if (sum == number) {
    console.log(`${number} is an Armstrong number`);
}
else {
    console.log(`${number} is not an Armstrong number.`);
}
