const binary_search=(arr:number[], target:number)=>{
    let left:number = 0;
    let right:number = arr.length - 1;
  
    while (left <= right) {
      const mid:number = Math.floor((left + right) / 2);
  
      if (arr[mid] === target) {
        return mid; // Target found, return its index
      } else if (arr[mid] < target) {
        left = mid + 1; // Adjust the left bound
      } else {
        right = mid - 1; // Adjust the right bound
      }
    }
  
    return -1; // Target not found in the array
  }
  // Example usage:
const sortedArray: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
const target: number = 6;
const result: number = binary_search(sortedArray, target);

if (result !== -1) {
  console.log(`Target ${target} found at index ${result}`);
} else {
  console.log(`Target ${target} not found in the array.`);
}

  export default binary_search