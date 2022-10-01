// Code 19: To find a first pair whose sum is zero 

function getSumPairZero(arr) {
    for (let i in arr) {
        console.log(arr[i], arr[parseInt(i) + 1])
        if (arr[parseInt(i) + 1]) {
            if (arr[i] + arr[parseInt(i) + 1] === 0) {
                return [arr[i], arr[parseInt(i) + 1]]
            }
        } else {
            if (arr[i] + arr[0] === 0) {
                return [arr[i], arr[0]]
            }
        }

    }
}



function getSumPairZero1(arr) {
    let left = 0;
    let right = arr.length - 1
    while (left < right) {
        let sum = arr[left] + arr[right]
        console.log(sum)
        if (sum == 0) {
            return [arr[left], arr[right]]
        } else if (sum > 0) {
            right--
        } else {
            left++
        }
    }
}


const result = getSumPairZero([-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5])
const result1 = getSumPairZero1([-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5])

console.log(result) 
console.log(result1) 

