// Swapping of 2 numbers with third variable 

let a= 2; 
let b = 3;
[a,b] = [b,a]
console.log(a,b)

function swap(x,y){
    x = x+y
    y = x-y
    x = x-y
    return [x,y]
}

console.log(swap(10, 13))