//algorithm for checking password complexity
// input: password type string
// output: weak - medium - strong - very strong
/*
Example:  "password123+"
output : strong
*/

function passwordCheck(password) {
  const characters = /[!@#$%^&*()_+\-=\[\]{};':"\\|,.<>\/?]+/;
  var complexity = 0;
  var uppercase = false;
  var lowercase = false;
  var specialChar = false;
  var numbers = false;
  for (var i = 0; i < password.length; i++) {
    if (uppercase && lowercase && specialChar && numbers) break;
    if (characters.test(password[i])) {
      if (!specialChar) {
        complexity += 1;
        specialChar = true;
      }
    } else if (!isNaN(Number(password[i]))) {
      if (!numbers) {
        complexity += 1;
        numbers = true;
      }
    } else if (password[i].toUpperCase() === password[i]) {
      if (!uppercase) {
        complexity += 1;
        uppercase = true;
      }
    } else {
      if (!lowercase) {
        complexity += 1;
        lowercase = true;
      }
    }
  }
  return complexity === 1
    ? "weak"
    : complexity === 2
    ? "medium"
    : complexity === 3
    ? "strong"
    : "very strong";
}
console.log(passwordCheck("password123+"));
