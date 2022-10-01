// To find character occurance fro the string 

let string = 'dhsfhskdjosdkk,c,ca,ckdsoddbddjsdodowe'
let obj = {}
for (let i of string.split('').sort((a, b) => a - b)) {
    if (obj[i]) {
        obj[i] += 1
    } else {
        obj[i] = 1
    }
}
console.log(obj)


// :To find character occurance fro the string 

function charOcc(str, char) {
    let obj = {}
    let splittedData = str.split('')
    console.log(splittedData, char)
    for (let i in splittedData) {
        if (!obj[splittedData[i]] && splittedData[i] === char) {
            obj[splittedData[i]] = 1
        } else {
            obj[splittedData[i]] += 1
        }
    }
    return obj[char]
}


console.log("CHAR OCC",charOcc('priyaaaaaaa', 'i'))