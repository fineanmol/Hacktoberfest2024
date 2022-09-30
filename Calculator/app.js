let screen = document.getElementById("screen"); // input/output screen
let buttons = document.querySelectorAll(".btn"); // every button
let screenVal = '';  // a variable containing screen's value to perform various operations 
for(item of buttons){ // every time when a button is clicked...
    item.addEventListener('click', (e)=>{ // click event
        buttonText = e.target.innerText; // buttonText equals to the value of the button clicked
        console.log(buttonText);
        if(buttonText=='C'){  // to clear the input/output screen
            screen.value = ""
            screenVal=''
        }

        else if(buttonText=='='){ 
            screen.value = "= "+eval(screenVal) //evaluate and display the answer when = is clicked
        }

        else{ //otherwise put the val of buttonText into the input/output screen
            screenVal+=buttonText;  
            screen.value=screenVal
        }
    })
}