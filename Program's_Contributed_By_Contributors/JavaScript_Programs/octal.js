const octal = (binary) => {
    return parseInt(binary, 2).toString(8);
}

console.log(octal("1111000")); 