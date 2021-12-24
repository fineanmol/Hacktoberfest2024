const btnAction = document.querySelector(".action");
const customer = document.querySelector(".customer");
const cash = document.querySelector("#cash");
const bill = document.querySelector("#bill");
const table = document.querySelector(".table");
const resultText = document.querySelector(".resultText");
const returnDiv = document.querySelector(".returnDiv");
const notes = [2000, 500, 100, 50, 20, 10, 5, 1];
let returnArr = [0, 0, 0, 0, 0, 0, 0];

btnAction.addEventListener("click", generateCash);

function generateCash() {
  //checks for the text on button
  if (btnAction.innerText === "Next") {
    //if Next, hide the rest of elements
    if (bill.value) {
      customer.classList.remove("hidden"); //after next is clicked, show the textfield
      btnAction.innerHTML = "Check"; //change the name to Check
    } else {
      alert("Amount of bill cannot be less than 0!")
      
    }
  }
  //check if the button is Check
  else if (btnAction.innerText === "Check") {
    if (bill.value && cash.value) {
      //if the values are present
      const balance = cash.value - bill.value; //difference of cash and bill
      if (balance === 0) {
        returnDiv.classList.add("hidden");
        resultText.innerText = "There's no money to return"; //customer gave the exact amount
      } else if (balance > 0) {
        //if balance exists
        let remainingAmount = balance;
        for (var i = 0; i < notes.length; i++) {
          returnArr[i] = Number.parseInt(remainingAmount / notes[i]); //generating the number of notes
          remainingAmount -= returnArr[i] * notes[i];
        }
        updateTable(returnArr);
        returnDiv.classList.remove("hidden");
        resultText.innerHTML=" ";
      } else {
        returnDiv.classList.add("hidden");
        resultText.innerText = `Cash given by customer is less ${
          bill.value - cash.value
        }`;
      }
    } else {
      alert("Invalid characters entered!")
      
    }
  }
}

function updateTable(givenArr) {
  tbody = table.tBodies[0];
  for (var i = 0; i < givenArr.length; i++) {
    tbody.rows[i].cells[1].innerText = givenArr[i];
  }
}
