// Code 4:String reverse without reversing of individual words
let string = 'India is my country'

function x() {
    let data = string.split('').reverse().join('').split(' ').reverse().join(' ')
    return data;
}
console.log(x())

function y() {
    let data = string.split('').reverse().join('')
    return data
}
console.log(y())

//WITHOUT INBUILT
function wOInbuilt() {
    let newStr = '';
    for (let i = string.length - 1; i >=0; i--) {
        console.log(i)
        newStr += string[i]
    }
    return newStr;
}

console.log(wOInbuilt())