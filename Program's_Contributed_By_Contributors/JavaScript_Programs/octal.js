const octal = (binary) => {
    return parseInt(binary, 2).toString(8);
}

console.log(octal("11110000")); //360