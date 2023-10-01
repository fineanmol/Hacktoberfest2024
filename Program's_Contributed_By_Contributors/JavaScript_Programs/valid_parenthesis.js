// function that determines if a given string containing only parentheses is valid. Valid strings must have matching open and close parentheses.
// Example:
// Input: "((()))"
// Output: true

var isValid = function(s) {
  const stack = [];
  const brackets = {
    '(': ')',
    '[': ']',
    '{': '}',
  };

  for (let i = 0; i < s.length; i++) {
    const currentChar = s[i];

    if (brackets.hasOwnProperty(currentChar)) {
      stack.push(currentChar);
    } else {
      const topOfStack = stack.pop();
      if (brackets[topOfStack] !== currentChar) {
        return false;
      }
    }
  }

  return stack.length === 0;

};
        
const check = isValid("[}") ? "valid" : "invalid"
console.log(check)
