function makeChange(arr, target) {
  arr.sort((a, b) => b - a);
  let bills = 0;
  arr.forEach((e) => {
    if (target % e == 0) {
      bills += target / e;
      target = 0;
    } else {
      bills += Math.floor(target / e);
      target = target % e;
    }
  });
  return bills;
}

function makeChangeB(arr, target) {
  arr.sort((a, b) => b - a);
  let coins = 0;
  let i = 0;
  while (target > 0) {
    if (arr[i] <= target) {
      target -= arr[i];
      coins++;
    } else {
      i++;
    }
  }
  return coins;
}
console.log(makeChangeB([10, 5, 25], 120));
