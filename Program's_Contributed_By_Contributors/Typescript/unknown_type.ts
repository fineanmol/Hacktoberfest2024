let vAny: any = 10
let vUnknown: unknown = 20

let s1: string = vAny
let s2: string = vUnknown //error because s2 is a string and vUnknown cannot be assigned to it since its an unknown number

console.log(vAny.foo())
console.log(vUnknown.foo()) // error because unknown is a number and not an object
