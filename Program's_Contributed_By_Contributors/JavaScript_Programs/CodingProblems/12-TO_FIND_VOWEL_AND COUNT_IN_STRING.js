// : To find vowels and its count in a given string

let str ="priya" 
function vowelsCheck(){
    let vowels = ['a', 'e', 'i', 'o', 'u']
    let count = 0 
    for(let i of str.split('')){
        if(vowels.includes(i)){
            count++
        }
    }
    return count
}
console.log(vowelsCheck())