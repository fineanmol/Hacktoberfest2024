// Javascript code to linearly search x in arr[]. 

  

function search(arr, n, x) 
{ 

    for (let i = 0; i < n; i++) 

        if (arr[i] == x) 

            return i; 

    return -1; 
} 

  
// Driver code 

  

    let arr = [ 2, 3, 4, 10, 40 ]; 

    let x = 10; 

    let n = arr.length; 

  

    // Function call 

    let result = search(arr, n, x); 

    (result == -1) 

        ? console.log("Element is not present in array") 

        : console.log("Element is present at index " + result); 
