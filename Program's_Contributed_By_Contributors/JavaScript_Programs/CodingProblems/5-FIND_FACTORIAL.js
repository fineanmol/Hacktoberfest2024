// : Find factorial of user input number

const number = parseInt(window.prompt(`Enter Positive integer:`))
let fact = 1;
if (number < 0) {
    console.log('Error! Factorial for negative number does not exist.')
} else if (number == 0) {
    console.log(`The factorial is 1.`)
} else {
    for (let i = 1; i <= number; i++) {
        fact *= i
    }
}
console.log(fact)