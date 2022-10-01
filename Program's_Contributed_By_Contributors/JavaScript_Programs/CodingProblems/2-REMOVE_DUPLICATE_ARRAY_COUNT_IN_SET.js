// Code 2: Remove Duplicate characters from array of element and find the count of an 
// elements using set object
var arr = [55, 44, 55,67,67,67,67,8,8,8,8,8,65,1,2,3,3,34,5]; 
let data = [...new Set(arr)].sort((a,b) => a-b)
console.log(data)
console.log(data.length)
