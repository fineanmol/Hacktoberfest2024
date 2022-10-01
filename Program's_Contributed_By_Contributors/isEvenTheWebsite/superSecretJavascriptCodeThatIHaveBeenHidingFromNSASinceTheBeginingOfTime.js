//Super secret dont leak this code
const isEven = (number) => number % 2 == 0;

const submit = () => {
  const reg = /^\d+$/;
  const number = document.getElementById("input").value;
  if (reg.test(number)) {
    document.getElementById(
      "result"
    ).innerText = `Result : number ${number} is ${
      isEven(number) ? "Even" : "Odd"
    }`;
  } else if(number.length < 1){
    document.getElementById(
        "result"
      ).innerText = `Result : put something please, i don't know what number you are thinking`;
  } else {
    document.getElementById(
      "result"
    ).innerText = `Result : pretty sure "${number}" is not a number`;
  }
};
