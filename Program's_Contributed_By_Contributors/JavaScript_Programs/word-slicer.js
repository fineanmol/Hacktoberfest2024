function WordSlicer(strArr) {
  const word = strArr[0];
  const dictionary = strArr[1];

  const wordsDictionaryArr = dictionary.split(",");

  for (let i = 1; i < word.length; i++) {
    const firstWord = word.slice(0, i);
    if (wordsDictionaryArr.includes(firstWord)) {
      const secondWord = word.slice(i, word.length);
      if (wordsDictionaryArr.includes(secondWord)) {
        return `${firstWord} ${secondWord}`;
      }
    }
  }

  return "not found";
}

const list = ["baseball", "b,ba,bas,base,ball"];

console.log(WordSlicer(list));
