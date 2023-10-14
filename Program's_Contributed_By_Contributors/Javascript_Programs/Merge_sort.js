// Recursive function to perform Merge Sort on an array
function mergeSort(arr) {
    if (arr.length <= 1) return arr;
  
    const middle = Math.floor(arr.length / 2);
    const left = arr.slice(0, middle);
    const right = arr.slice(middle);
  
    return merge(mergeSort(left), mergeSort(right));
  }
  
  // Merge two sorted arrays into a single sorted array
  function merge(left, right) {
    let result = [];
    let leftIndex = 0;
    let rightIndex = 0;
  
    while (leftIndex < left.length && rightIndex < right.length) {
      if (left[leftIndex] < right[rightIndex]) {
        result.push(left[leftIndex]);
        leftIndex++;
      } else {
        result.push(right[rightIndex]);
        rightIndex++;
      }
    }
  
    // Concatenate any remaining elements from left and right arrays
    return result.concat(left.slice(leftIndex), right.slice(rightIndex));
  }
  
  const unsortedArray = [64, 25, 12, 22, 11];
  
  // Perform Merge Sort on the unsorted array
  const sortedArray = mergeSort(unsortedArray);
  