// To check the string or number is palindrome or not( ex: 121,madam,anna) using 
// reverse method

const string = "anmnaa"
function checkPalindrome() {
    let str = string.split('').reverse().join('')
    if (str == string) {
        return `Its Palindrome`
    } else {
        return `Its  not Palindrome`
    }

}
// console.log(checkPalindrome())

function checkPalindrome1() {
    const string = "12321"
    let len = string.length;
    let count = 0;
    for (i = 0; i < len / 2; i++) {
        if (string[i] !== string[len - 1 - i]) {
            count++
        }
    }
     
}
console.log(checkPalindrome1())




