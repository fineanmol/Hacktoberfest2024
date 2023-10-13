const prompt = require("prompt-sync")()

const target = 10 + Math.round(Math.random() * 90)

let guesses = 1


while(true) {
    const guess = Number(prompt("Guess the number(10-100): "))

    if (guess > target) {
        console.log("Too High!")
        guesses++
    } else if (guess < target) {
        console.log("Too Low!")
        guesses++
    } else {
        console.log("Nice! You got it in", guesses, "tries!")
        break
    }
}