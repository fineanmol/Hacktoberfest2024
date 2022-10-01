// : Fibonacci Series (0,1,1,2,3,5,8,13....) 

function fibonacci(N) {
    let arr = []
    let n1 = 0 
    let n2 = 1
    arr.push(n1,n2) 
    let nextTerm;
    for (let i = 0; i <=N; i++) {
        nextTerm = n1 + n2
        n1 = n2
        n2 = nextTerm
        arr.push(nextTerm)
    }
    return arr.join(' , ');
}

////////

console.log(fibonacci(100))