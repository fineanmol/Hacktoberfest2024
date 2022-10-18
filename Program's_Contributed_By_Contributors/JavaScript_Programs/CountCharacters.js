//program to find the count of very character in a string
let str = "HELLO";
let result = {};
let strarr = str.split('');
for (let i = 0; i < strarr.length; i++) {

    result[str[i]] = (result[str[i]] + 1) || 1;

}

console.log(result)