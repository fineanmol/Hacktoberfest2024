// Code 1: Remove Duplicate characters from String

let string = 'priya riya supriya'
let arr = [];
string.trim().split('').forEach((value, index) =>{
    if(!arr.includes(value)){
        arr.push(value)
    }
})
console.log(arr.join(''))
