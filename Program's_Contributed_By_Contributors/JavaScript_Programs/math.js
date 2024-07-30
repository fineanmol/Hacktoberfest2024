const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const question = (query) =>
  new Promise((resolve) => rl.question(query, resolve));

const plus = (a, b) => {
  return a + b;
};

const multiply = (a, b) => {
  return a * b;
};

const divided = (a, b) => {
  return a / b;
};

const mins = (a, b) => {
  return a - b;
};

module.exports = { plus, question, rl, multiply, divided, mins };
