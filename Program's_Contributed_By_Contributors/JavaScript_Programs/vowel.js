const vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'];

function countVowels(sentence) {
    let counts = 0;
    for (let i = 0; i < vowels.length; i++) {
        if (vowels.includes(sentence[i])) {
            counts++;
        }
    }
    return console.log(counts);
}

countVowels('Hello World');