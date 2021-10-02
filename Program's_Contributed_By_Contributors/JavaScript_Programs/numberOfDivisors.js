// Count the divisors of a number
function getDivisorsCnt(n) {
    let  d = 1;
    for (var i = 0; i <= n / 2; ++i){
      if (n % i == 0){
          ++d;
      }
    }

    return d;
}

console.log(getDivisorsCnt(40));
