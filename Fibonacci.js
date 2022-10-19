// Kaustav-04

const num = prompt("Enter a Number");

let a = 0, b = 1;

console.log(a);
console.log(b);
let n = a+b;
while (n < num) {
    console.log(n);
    a = b;
    b = n;
    n = a + b;
}