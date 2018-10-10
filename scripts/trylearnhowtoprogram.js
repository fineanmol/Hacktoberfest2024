//Sieve Logic
//Back-end Logic
function ancientSieve(numberToCheck) {
  //Sieve of Eratosthenes. First establish numbers list as empty array. Set the upper limit to the square root of whatever
  //the number that you're checking is. Set the output(list of primes) to start with the first prime number (2).
  let numbersList = []
  let upperLimit = Math.sqrt(numberToCheck)
  let output = []

  //Make an array from  to the number you're checking and set its boolean value to TRUE
  for(let index = 0; index < numberToCheck; index++) {
    numbersList.push(true)
  }
  //Now we're going to loop through the prime numbers starting with 2
  for (let prime = 2; prime <= upperLimit; prime += 1) {
    //If the number is on the list of numbers we're(this if will return true every time until we reach the limit of the list) going to go into another loop
    if(numbersList[prime]) {
      //This loop checks all multiples of that number and sets all of their boolean values to FALSE (if the base number is a factor of another number, then that other number cannot be prime)
      for (let multiplierOfPrime = prime * prime; multiplierOfPrime < numberToCheck; multiplierOfPrime += prime) {
        numbersList[multiplierOfPrime] = false;
      }
    }
  }
  //Now we're going to check through every number that's in our list, and push all the ones with the
  //boolean value TRUE to the empty array output.
  for (let index = 2; index < numberToCheck; index+= 1) {
    if(numbersList[index]) {
      output.push(index);
    }
  }
  return output;
}
//Palindrome Logic

//Store the message for a positive outcome as a variable.
var isPalindromeMessage = "Yes! Yes!<br>You've done it!<br>Wow! Now <em>that's </em> what I call a palindrome!"
//store the message for a negative outcome as a variable.
var notPalindromeMessage = "Boooo! We're sorry, but that's <em> not </em>a palindrome!"
//A custom function to remove punctuation marks.
function punctuationless(stringToStrip) {
  return stringToStrip.replace(/[^A-z0-9_]/g,"");
}
//A custom function that splits a string before reversing it and joining it back into a string.
function reversedString(string) {
  let lettersAsArray = string.split("");
  return lettersAsArray.reverse().join("");
}
function colorControl(color) {
  $('#palindrome_results').empty();
  $('#output').removeClass();
  $('#output').addClass(color)
}
//A custom function that strips the original string, saves it for comparison, converts it into an array
//then reverses that array before joining it back into a string to compare with the original string.
//The results of this comparison are printed in the output div on the document.
function stringAnalyzer(string) {
  let wordArray = []
  let cleanString = punctuationless(string);
  let original = cleanString;
  let reversed = reversedString(cleanString);
  $('#originalInput').text($('#user_string').val());
  if (original === reversed) {
    colorControl('correct');
    $('#palindrome_results').html(isPalindromeMessage);
  } else if (original != reversed) {
    colorControl('incorrect');
    $('#palindrome_results').html(notPalindromeMessage);
  }
}

//Factoiral Calculator

//Assign the error message to a variable so it's easier to use.
errorMessage = 'Please make sure that you enter an integer (whole number) that is not negative'
//Take user input and parse it.
function gatherAndParse() {
  let number = parseInt($('#user_factorial').val(), 10);
  return number;
}
//Take user inputted number, make sure it isn't negative or a non-integer, then use a for loop to create an array of all the numbers to be used in the factorial calculation
//and then reduce the array they are pushed to by multiplying them thus calculating the factorial.
function factorial(numberToMakeFactorial) {
  if (numberToMakeFactorial < 0 || Number.isInteger(numberToMakeFactorial) === false) {
    $('#error').text(errorMessage);
  } else {
    $('#error').empty();
    let factorialArray = []
    for (let currentNum = 1 ; currentNum <= numberToMakeFactorial; currentNum += 1) {
      factorialArray.push(currentNum);
    }
    let output = factorialArray.reduce(function(total, currentNum) {
      return total * currentNum;
    },)
    $('#factorial_results').text(output);
  }
}

//Front-end Logic
$(document).ready(function() {
  $('#sieve_form').submit(function(event) {
    event.preventDefault();
    let userNumber = $('#user_number').val();
    $('#sieve_results').text(ancientSieve(userNumber).join(" "));
  });
  $('#palindrome_form').submit(function(event) {
    event.preventDefault();
    stringAnalyzer($('#user_string').val());
  });
  $('#factorial_form').submit(function(event) {
    event.preventDefault();
    let userFactorial = gatherAndParse();
    factorial(userFactorial);
  });
});
