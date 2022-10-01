let Celsius = document.getElementById("celsius");
let Fahrenheit = document.getElementById("fahrenheit");

function CelToFar() {
    let output = (parseFloat(Celsius.value) * 9 / 5) + 32;
    Fahrenheit.value = parseFloat(output.toFixed(2));
}

function FarToCel() {
    let output = (parseFloat(Fahrenheit.value) - 32) * 5 / 9;
    Celsius.value = parseFloat(output.toFixed(2));
    console.log(output);
}
