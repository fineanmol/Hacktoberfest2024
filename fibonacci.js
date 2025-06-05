// we have 3 variables a,b and result
//[0,1,1,2,3,5,8,13,21,34]
// var a = 0;
// var b = 0
// var result = b

//Method 1

function fib (n){
    const result = [0,1];
    for (let i = 2; i <= n; i++){
        const a = result[i - 1];
        const b = result [i - 2];
        result.push(a + b) //adds an element at the end of the array.
        
    }

    var data = result.map((data)=>{
        return data;
    })

    console.log(data);
}
console.log(fib("8"))

//fibonacci accepts strings
//fibonacci does not accept negatives.
//works with positive number

//Method 2 using a recursive function
function fib(n) {

    if (n < 0) {
      throw new Error(
        'Index was negative. No such thing as a negative index in a series.');
    }
  
    // Base cases
    if (n === 0 || n === 1) {
      return n;
    }
  
    console.log(`computing fib(${n})`);
    return fib(n - 1) + fib(n - 2);
}

//Method 3 using memoization.

class Fibber {
    constructor() {
        this.memo = {};
    }

    fib(n) {
        if(n < 0) {
            throw new Error('Index was negative. No such thing as a negative index in a series.');

        //Base cases
        } else if (n === 0 || n === 1) {
            return n;
        }
        //See if we've already calculated this
        if (this.memo.hasOwnProperty(n)) {
            console.log(`grabbing memo[${n}]`);
            return this.memo[n];
        }
        console.log(`computing fib(${n})`);
        const result = this.fib(n - 1) + fib(n - 2);

        //Memoize
        this.memo[n] = result;

        return result;        
    }
}
 new Fibber().fib(5)