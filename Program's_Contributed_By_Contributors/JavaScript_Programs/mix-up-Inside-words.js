
//If you mix up the order of letters in a word, many people can slitl raed and urenadnstd tehm. Write a function that takes an input sentence, and mixes up the insides of words (anything longer than 3 letters).

//Example:

// scramble(["A quick brown fox jumped over the lazy dog."])
// "A qciuk bwron fox jmepud oevr the lzay dog."

const mixUpInsideWords = (sentence) => {
	const words = sentence.split(" ");

	const mixedUpWords = words.map((word) => {
	  if (word.length <= 3) {
		return word;
	  }
	  
	  const firstLetter = word.charAt(0);
	  const lastLetter = word.charAt(word.length - 1);
	  const middleLetters = word.slice(1, -1).split("");

	  for (let i = middleLetters.length - 1; i > 0; i--) {
		const j = Math.floor(Math.random() * (i + 1));
		[middleLetters[i], middleLetters[j]] = [middleLetters[j], middleLetters[i]];
	  }
	  return `${firstLetter}${middleLetters.join("")}${lastLetter}`;
	});
  
	return mixedUpWords.join(" ");
  };
  
  const sentence = "A quick brown fox jumped over the lazy dog.";
  const mixedUpSentence = mixUpInsideWords(sentence);
  console.log(mixedUpSentence);