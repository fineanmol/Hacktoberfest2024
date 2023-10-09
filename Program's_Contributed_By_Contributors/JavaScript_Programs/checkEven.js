// Even Number
// An even number is an integer that is divisible by 2. For example, 2,4,6,8,10,12  are the first few even numbers.


//take input from the user
const number = parseInt(prompt("Enter a positive number: "));
let isEvene = true;

//Check if it is divisible by 2 

if(number%2===0){
    console.log("It is an even number");
}
else{
    console.log('It is an odd number');
}
