function printPerm(str, permutation) {
    if (str.length === 0) {
        console.log(permutation);
        return;
    }
    for (let i = 0; i < str.length; i++) {
        const currChar = str.charAt(i);
        const newStr = str.substring(0, i) + str.substring(i + 1);
        printPerm(newStr, permutation + currChar);
    }
}

function main() {
    const str = "abc";
    printPerm(str, "");
}

main();


