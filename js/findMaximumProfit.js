// Provided an arr which contains the stock price per day, find the price to buy and price to sell such that max profit is achieved.
// Input arr = [2,10,1,3]
// Ouput = [2,10] -> max profit of 8.

const arr = [2, 10, 1, 3];

function findBuySellPrice(arr) {
  let buyPrice = arr[0] < arr[1] ? arr[0] : arr[1];
  let sellPrice = arr[0] > arr[1] ? arr[0] : arr[1];

  for (let i = 2; i < arr.length; i++) {
    if (buyPrice > arr[i]) {
      if (i < arr.indexOf(buyPrice)) {
        buyPrice = arr[i];
      }
    }
    if (sellPrice < arr[i]) {
      if (i > arr.indexOf(sellPrice)) {
        sellPrice = arr[i];
      }
    }
  }
  let maxProfit = sellPrice - buyPrice;
  return [buyPrice, sellPrice, maxProfit];
}

console.log(findBuySellPrice(arr));
// Output: [ 2, 10, 8 ]
