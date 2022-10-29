/**
 * @param {number[]} nums
 * @return {number[]}
 */
var runningSum = function(nums) {
    let runningSumArray = [];
    runningSumArray[0] = nums[0];

    for (let i = 1; i < nums.length; i++) {
      runningSumArray[i] = runningSumArray[i-1] + nums[i]
    }
    
    return runningSumArray
};