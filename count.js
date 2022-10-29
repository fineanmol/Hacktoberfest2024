function findNumberOfTriangles(arr, n)
{
 
    // Count of triangles
    let count = 0;
 
    // The three loops select three
    // different values from array
    for (let i = 0; i < n; i++)
    {
        for (let j = i + 1; j < n; j++)
        {
 
            // The innermost loop checks for
            // the triangle property
            for (let k = j + 1; k < n; k++)
 
                // Sum of two sides is greater
                // than the third
                if (
                    arr[i] + arr[j] > arr[k]
                    && arr[i] + arr[k] > arr[j]
                    && arr[k] + arr[j] > arr[i])
                    count++;
        }
    }
    return count;
}
 
// Driver Code
    let arr = [ 10, 21, 22, 100, 101, 200, 300 ];
    let size = arr.length;
     
    document.write( "Total number of triangles possible is "+
      findNumberOfTriangles(arr, size));
