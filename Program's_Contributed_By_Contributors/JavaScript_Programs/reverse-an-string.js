// This function takes a string as input and returns the reversed version of that string.
const reverseAString = (str) => {
  // Step 1: Split the input string into an array of individual characters.
  const splitString = str.split("") // For example, "Hello" becomes ["H", "e", "l", "l", "o"]

  // Step 2: Create an empty array to store the reversed characters.
  const reverseString = []

  // Step 3: Use a loop to iterate through the characters in reverse order.
  for (let i = splitString.length - 1; i >= 0; i--) {
    // Step 4: Push each character into the 'reverseString' array.
    reverseString.push(splitString[ i ])
  }

  // Step 5: Join the reversed characters back together into a single string.
  // This creates the final reversed string.
  return reverseString.join("")
}

// Step 6: Call the 'reverseAString' function with a sample string and log the result.
console.log(reverseAString("This is a reverse string")) // Output: "gnirts esrever a si sihT"
