/** 
 * This function will accept an array and
 * Sort its elements in ascending order and return the sorted array
 * @param {Array} arr array with elements of any data type
 * @returns {Array} array with elements sorted in ascending order
 */
const BubbleSort = (arr) => {
  const n = arr.length;
  let swapped;

  do {
    swapped = false;
    for (let i = 0; i < n - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        // Swap arr[i] and arr[i+1] if they are in the wrong order
        const temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        swapped = true;
      }
    }
  } while (swapped);

  return arr;
};

export { BubbleSort };
