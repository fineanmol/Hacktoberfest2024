function coinChange(changeArray, amount) {
  const change = [];

  for (let i = 0; i < changeArray.length; i++) {
    let changeAmount = Math.floor(amount / changeArray[i]);
    amount -= (changeArray[i] * changeAmount);
    change.push(changeAmount);
  }
  
  return result;
}
