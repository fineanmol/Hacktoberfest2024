// To find vowels and its count in a given string

let vowels = ['a', 'e', 'i', 'o', 'u']

function vowelsCount(){
    let str ="priya".toLowerCase()
    let count = 0
    for(let i of str.split('')){
        if(vowels.includes(i)){
            count += 1
        }
    }
    return count
}
console.log(vowelsCount())