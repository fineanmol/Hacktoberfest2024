// Prime Number
// A prime number is a positive integer that is only divisible by 1 and itself. For example, 2, 3, 5, 7, 11 are the first few prime numbers.


// program to check if a number is prime or not

// take input from the user
const number = parseInt(prompt("Enter a positive number: "));

function isPrime(num) {
    if (num <= 1) {
        return false;
        //check for one
    }
    if (num <= 3) {
        return true;
        //check up to 3
    }

    if (num % 2 === 0 || num % 3 === 0) {
        return false;
    }

    for (let i = 5; i * i <= num; i += 6) {
        if (num % i === 0 || num % (i + 2) === 0) {
            return false;
        }
        //check for all the numbers greater than 3 which comes in the form of 6k ± 1
    }

    return true;
}

if (isPrime(number)) {
    console.log(`${number} is a prime number`);
} else {
    console.log(`${number} is not a prime number`);
}
