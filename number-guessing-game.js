// Number Guessing Game
console.log('WELCOME TO NUMBER GUESSING GAME!!!')
let no_of_guess = 0
let user_guess = 0
let actual_no = Math.floor((Math.random() * 100) + 1);
while (user_guess != actual_no) {
  user_guess = parseInt(prompt("ENTER ANY NUMBER BETWEEN 1-100"));
  no_of_guess++
  if (user_guess < actual_no) {
    console.log("Oops!! Your guessed number is smaller than the actual number")
  }
  else if (user_guess > actual_no) {
    console.log("Oops!! Your guessed number is greater than the actual number")
  }
  else {
    console.log("\nYay🥳🥳 You have guessed the right number and you have scored", 100 - no_of_guess);
  }
}
console.log("The actual number was", actual_no)
console.log("You took", no_of_guess, "chances to guess right")
