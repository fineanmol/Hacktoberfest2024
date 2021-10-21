//check if every row in a matrix has the same length
function checkLength(matrix){
    let length = matrix[0].length;
    let result = true
    matrix.forEach((v)=>{
        if(v.length != length){
            result = false
        }
    })
    return result
}

function matrixMultiplier(matrixA,matrixB){
    if(!checkLength(matrixA)){
        throw new Error('The matrixA is not a matrix');
    }
    if(!checkLength(matrixB)){
        throw new Error('The matrixB is not a matrix');
    }
    if(matrixA[0].length!=matrixB.length){
        throw new Error('The number of columns in matrixA must be equal to the number of rows in matrixB')
    }
    let result = [];
    matrixA.forEach(()=>{
        result.push([])
    });
    matrixA.forEach((v,i)=>{
        for(i2=0;i2<matrixB[0].length;i2++){
            let total = 0;
            v.forEach((v3,i3)=>{
                total+=v3*matrixB[i3][i2]
            })
            result[i][i2] = total;
        }
    })
    return result;
}