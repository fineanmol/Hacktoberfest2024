function bubbleSort(arr) {
  for (let i = 0; i < arr.length; i++) {
    for (let j = 1; j < arr.length; j++) {
      if (arr[j - 1] > arr[j]) swap(arr, j - 1, j);
    }
  }
  return arr;
}

function swap(array, i, j) {
  let temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

console.log(bubbleSort([5, 2, 1, 13, 7]));

//////optimized
function bubbleSort(array) {
  var countOuter = 0;
  var countInner = 0;
  var countSwap = 0;

  var swapped;
  do {
    countOuter++;
    swapped = false;
    for (var i = 0; i < array.length; i++) {
      countInner++;
      if (array[i] && array[i + 1] && array[i] > array[i + 1]) {
        countSwap++;
        swap(array, i, i + 1);
        swapped = true;
      }
    }
  } while (swapped);

  console.log("outer:", countOuter, "inner:", countInner, "swap:", countSwap);
  return array;
}
