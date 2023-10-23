"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var binary_search = function (arr, target) {
    var left = 0;
    var right = arr.length - 1;
    while (left <= right) {
        var mid = Math.floor((left + right) / 2);
        if (arr[mid] === target) {
            return mid; // Target found, return its index
        }
        else if (arr[mid] < target) {
            left = mid + 1; // Adjust the left bound
        }
        else {
            right = mid - 1; // Adjust the right bound
        }
    }
    return -1; // Target not found in the array
};
// Example usage:
var sortedArray = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
var target = 6;
var result = binary_search(sortedArray, target);
if (result !== -1) {
    console.log("Target ".concat(target, " found at index ").concat(result));
}
else {
    console.log("Target ".concat(target, " not found in the array."));
}
exports.default = binary_search;
