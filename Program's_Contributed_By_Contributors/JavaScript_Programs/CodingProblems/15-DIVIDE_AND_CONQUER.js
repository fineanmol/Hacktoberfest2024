//DIVIDE & CONQUER

// At which index the input data is located
//Binary search works on sorted array 


function search(arr, val) {
    let min = 0
    let max = arr.length - 1
    while (min <= max) {
        let middleElement = Math.floor((max + min) / 2) 
        console.log(arr[middleElement] , val, "min", min ,"max",max , 'middleelement', middleElement)
        if (val > arr[middleElement]) {  // when searched value greater than middle element
            min = middleElement + 1
        } else if (val < arr[middleElement]) { //when searched value less than middle element 
            max = middleElement - 1
        } else {
            return middleElement
        }

        //looop goes on until it finds the element 
    }
    return -1 

}
console.log(search([1, 2, 3, 4, 5, 6, 7], 2))