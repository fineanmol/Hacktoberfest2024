function* fibonacci() {
    let a = 0, b = 1;

    while (true) {
        yield a;
        [a, b] = [b, a + b];
    }
}


const fibGenerator = fibonacci();

console.log(fibGenerator.next().value); // 0
console.log(fibGenerator.next().value); // 1
console.log(fibGenerator.next().value); // 1
console.log(fibGenerator.next().value); // 2
console.log(fibGenerator.next().value); // 3
console.log(fibGenerator.next().value); // 5
