// Validation password using regex

function checkValidInput(password, password2) {
  let isValid = true;
  let message = "Password changed successfully"; // Default message

  // Check minimum length
  if (password.length < 8) {
      isValid = false;
      message = "Password should be at least 8 characters long";
  }

  // Check for at least one uppercase letter
  if (!/[A-Z]/.test(password)) {
      isValid = false;
      message = "Password must contain at least 1 uppercase letter";
  }

  // Check for at least one lowercase letter
  if (!/[a-z]/.test(password)) {
      isValid = false;
      message = "Password must contain at least 1 lowercase letter";
  }

  // Check for at least one digit
  if (!/\d/.test(password)) {
      isValid = false;
      message = "Password must contain at least 1 digit";
  }

  // Check for at least one special character
  if (!/[^A-Za-z0-9]/.test(password)) {
      isValid = false;
      message = "Password must contain at least 1 special character";
  }

  // Check if password and confirmation match
  if (password !== password2) {
      isValid = false;
      message = "Password and password confirmation do not match";
  }

  return { result: isValid, message: message };
}

// Example usage:
let password = "Passw0rd!";
let password2 = "Passw0rd!";
let result = checkValidInput(password, password2);
console.log(JSON.stringify(result));
