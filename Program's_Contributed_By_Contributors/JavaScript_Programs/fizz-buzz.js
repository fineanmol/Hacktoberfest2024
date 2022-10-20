for (let i = 1; i <= 100; i++) {

    for (let i = 1; i <= 100; i++) {
        if (i % 3 == 0 && i % 6 == 0) console.log("FizzBuzz");
        else if (i % 3 == 0) console.log("Fizz");
        else if (i % 6 == 0) console.log("Buzz");
        else console.log(i);
    }

}
