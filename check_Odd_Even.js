function checkOddEven(n) { 
    if (n & 1 == 1) { 
        return "Number is odd"; 
    } 
    return "Number is even"; 
} 

console.log(checkOddEven(12)); 
console.log(checkOddEven(121));