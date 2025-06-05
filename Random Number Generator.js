function generateRandomNumber(min, max) {
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

// Usage:
console.log(generateRandomNumber(1, 100)); // Generates a random number between 1 and 100
