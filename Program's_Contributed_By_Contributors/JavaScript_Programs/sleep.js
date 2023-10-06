// A custom implementation of Python's time.sleep() function in JavaScript

function sleep(seconds){
    return new Promise(resolve => setTimeout(resolve, seconds*1000));
}

const call = async () => {
    await sleep(2);
    console.log("printed after 2 seconds")
    await sleep(1)
    console.log("printed after 1 second after previous output")
}

call();