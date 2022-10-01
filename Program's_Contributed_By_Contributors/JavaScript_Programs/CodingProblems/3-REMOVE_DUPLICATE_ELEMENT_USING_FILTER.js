// Code 3: Remove Duplicate characters from array of element using filter

var myArray = ['a', 1, 'a', 2, '1'];

console.log(myArray.filter((value, index) => myArray.indexOf(value) == index))