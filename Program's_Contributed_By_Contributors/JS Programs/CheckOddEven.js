function checkOddOrEven(n) { 
    if (n & 1 == 1) { 
        return "Number is odd"; 
    } 
    return "Number is even"; 
} 
  
console.log(checkOddOrEven(12)); 
console.log(checkOddOrEven(121));