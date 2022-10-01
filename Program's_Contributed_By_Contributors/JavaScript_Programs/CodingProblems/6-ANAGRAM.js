let string1 = 'listen'
let string2 = 'slient'


function checkAnagram() {
    if (string1.toLowerCase().split('').sort().join('') === string2.toLowerCase().split('').sort().join('')) {
        console.log('Is An Anagram')

    } else {
        console.log('Is Not Anagram')
    }
}
checkAnagram()