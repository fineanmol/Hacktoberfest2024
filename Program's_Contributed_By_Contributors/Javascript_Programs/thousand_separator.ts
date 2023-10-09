

function thousandsWithRegex (num: number) {
  return num.toString().replace(/\B(?=(\d{3})+(?!\d))/g, ",");
}

function thousandsWithLocale (num: number) {
  return num.toLocaleString()
}

const MinusFiveMillions = -5000000;
const FiftyThousands = 50000;
const FiveHundredThousands = 500000;
const EightMillions = 8000000;

console.log(thousandsWithRegex(MinusFiveMillions))
console.log(thousandsWithLocale(MinusFiveMillions))
console.log(thousandsWithRegex(FiftyThousands))
console.log(thousandsWithLocale(FiftyThousands))
console.log(thousandsWithRegex(FiveHundredThousands))
console.log(thousandsWithLocale(FiveHundredThousands))
console.log(thousandsWithRegex(EightMillions))
console.log(thousandsWithLocale(EightMillions))