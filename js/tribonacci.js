// an algorithm to find the nth tribonacci numbers
// Example
// Input:
// tribonacci([1,1,1],10)
// Output:
// [1,1,1,3,5,9,17,31,57,105] + signature[i + 2] + signature[i + 2]);

function tribonacci(signature, n) {
  for (var i = 0; i < n - 3; i++) {
    // iterate n times
    signature.push(signature[i] + signature[i + 1] + signature[i + 2]); // add last 3 array items and push to trib
  }

  const result = signature.slice(0, n); //return trib - length of n

  console.log(result);

  return result;
}

tribonacci([1, 1, 1], 10);
