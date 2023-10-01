const butEl = document.getElementById("calculate");
const billInput = document.getElementById("bill");
const tipInput = document.getElementById("tip");
const totalSpan = document.getElementById("total");


function calculateTotal(){
    const billValue = billInput.value;
    const tipValue = tipInput.value;
    const totalValue = billValue * (1 + tipValue/100);
    console.log(totalValue);
    totalSpan.innerText = totalValue.toFixed(2);
}

butEl.addEventListener("click",calculateTotal);