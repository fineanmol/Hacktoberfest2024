// array.reduce pollyfill
Array.prototype.myReduce = function(callback, res) {
    if(!!Array.prototype.myReduce) {
        for(let i = 0; i < this.length; i++) {
            res = callback(res, this[i]);
        }
    }
    return res;
}
// const arr = [1,2,3,4]
// let sum = arr.myReduce((acc, curr) => acc * curr, 1)
// console.log(sum);


// array.filter polyfill
Array.prototype.myFilter = function(callback){
    const res = [];
    for(let i = 0; i < this.length; i++) {
        if(callback(this[i]) === true){
            res.push(this[i]);
        }
    }
    return res;
}

// const arr = [1,2,3,4]
// let even = arr.myFilter((x) => x%2 === 0)
// console.log(even);



// array.map polyfill
Array.prototype.myMap = function(callback){
    const res = []
    for(let i=0; i<this.length; i++){
        if(i in this){
            res[i] = callback(this[i], i, this);
        }
    }
    return res;
}

const arr = [1,2,3,4,,4]
let double = arr.myMap((a) => a % 2 )
console.log(double);
