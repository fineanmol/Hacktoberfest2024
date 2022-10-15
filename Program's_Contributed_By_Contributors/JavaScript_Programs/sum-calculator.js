function calcSum() {
  let number1 = Number(prompt('Type the first number here: '));
  let number2 = Number(prompt('Type the second number here: '));

  if (isNaN(number1) || isNaN(number2)) {
    alert('[ERROR] Value not accepted!');
    calcSum();

  } else {
    let result = number1 + number2;
    alert(`${number1} plus ${number2} is: ${result}`);
  };
};

calcSum();

// MADE BY CRISTIAN :)