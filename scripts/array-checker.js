/**
 *
 * @param {array} firstArr first array
 * @param {array} secondArr second array
 * @returns {array} duplicate array
 */
 function validate(firstArr, secondArr) {
  let duplicate = [];

  for (let i = 0; i < firstArr.length; i++) {
    const firstEl = firstArr[i];

    for (let j = 0; j < secondArr.length; j++) {
      const secondEl = secondArr[j];

      if (firstEl === secondEl) {
        duplicate.push(firstEl);
      }
    }
  }
  return duplicate;
}

const myArr = [
  'a',
  'b',
  'c',
  'd',
  'e',
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  'kita',
  'bisa',
  'kitabisa',
  '1',
  '2',
  '3',
];
const myArr2 = ['a', 'c', 'e', 'a', 8, 1, 1, '3', 'kita', 'hello', 'kita'];

const result = validate(myArr, myArr2);
console.log(result);
