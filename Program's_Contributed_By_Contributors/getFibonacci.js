// Author: Elijah ALlotey
// Date: 10/20/23
// Name: getFibonacci.js
// Use: This function is a basic function that calculates
// Each fibonacci number up to the given function 


function getFibonacci(limit, workingNums = [0, 1], counter = 1) {
    // Input testing if its an integer
    if (!Number.isInteger(limit)) throw new Error("Element number must be an integer")

    // If statements for the first two fibonacci elements
    if (limit === 1) return 0
    if (limit === 2) return 1

    // The main work for the function,
    // this finds the sum of elements in the working array
    // pushes it to the end of the array
    // and shifts the first entry out of the array left
    counter = counter + 1
    workingNums.push(workingNums[0] + workingNums[1])
    workingNums.shift()


    // The recursive condition, this will call itself
    // until it meets the counter <= limit condition
    // meaning it has found its fibonacci number, returning it
    // from its array position
    if (counter <= limit) return getFibonacci(limit, workingNums, counter)
    return workingNums[1]


}


// Defines interface to prompt user in nodejs enviroment
const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
})



function ask() {

    // Main user prompt
    readline.question("Enter the fibonacci element number you would like to calculate: ",
        (limit) => {
            try { console.log("\nYour desired fibonacci number is: ", getFibonacci(parseFloat(limit))) }

            catch (error) {
                console.log(`\nError: ${error.message}`)

                // Request additional number or terminate process
                readline.question("Would you like to try again? [y, n]: ", 
                (option) => {
                    if (option === "y") ask()
                    else process.exit()
                    }
                )
            }
        }

    )

}


// Start program
ask()





