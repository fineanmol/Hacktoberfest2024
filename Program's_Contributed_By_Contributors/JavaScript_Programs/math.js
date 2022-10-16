function suma(a, b) {
    return a + b;
}

function multipli(a, b) {
    if (b === 0) {
        return null;
    }
    return a * b;
}

function divide(a, b) {
    return a / b;
}

module.exports = {
    suma,
    multipli,
    divide
};