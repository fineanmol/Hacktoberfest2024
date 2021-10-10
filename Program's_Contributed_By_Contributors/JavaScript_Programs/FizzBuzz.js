/**
 * FIZZBUZZ: print numbers from 1 to 30, where multiples of 3 should print “Fizz”,
 * multiples of 5 should print “Buzz” and multiples of 3 and 5 shoud print “FizzBuzz”.
 *
 * 3 ways to solve FizzBuzz from around the world, in random order
 */

// 1
console.log(
  Array.apply(0, Array(30))
    .map(function (x, y) {
      var nb = y + 1;
      var isFizz = nb % 3 == 0;
      var isBuzz = nb % 5 == 0;
      var isFizzBuzz = isFizz && isBuzz;
      if (isFizzBuzz) return 'fizzbuzz';
      if (isFizz) return 'fizz';
      if (isBuzz) return 'buzz';
      return nb;
    })
    .join('\n')
);

// 2
for (let x = 1; x <= 30; x++)
  (function (i) {
    var output = '';
    if (i % 3 == 0) output += 'Fizz';
    if (i % 5 == 0) output += 'Buzz';
    console.log(output || i);
  })(x);

// 3
for (let i = 0; i < 30; )
  console.log((++i % 3 ? '' : 'Fizz') + (i % 5 ? '' : 'Buzz') || i);
