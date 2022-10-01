// : To find longest word from a string using (
let string = "supriya8888888888888888888 is a masooooom good girl"

function longestWord() {
    let splitData = string.split(' ')
    let max = 0
    let longestStr = '';
    // console.log(splitData)
    for (let i of splitData) {
        if (i.length > max) {
            max = i.length
            longestStr = i
        }
    }
    return {longestStr}
}

console.log(longestWord())