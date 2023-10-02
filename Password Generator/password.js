// Variables to access HTML
let content = document.querySelector("[password-display]"); 
const copyMsg = document.querySelector("[datacopy-msg]"); 
const copyButton = document.querySelector("[copy-button]"); 

let passwordNo = document.querySelector("[pass-len]"); 
let slideTag = document.querySelector("[slider]"); 

let uppercase = document.querySelector("#uppercase"); 
let lowerCase = document.querySelector("#lowercase"); 
let numberInput = document.querySelector("#number"); 
let symbol = document.querySelector("#symbol"); 

let indicator = document.querySelector("[strength-indicator]"); 

const generate = document.querySelector("#generate"); 




let passWord = ""; 
let passWordLen = 10; // Default
let color = '#b4b4b4'; 

handleSlider(); // Call for first time after reload page
function handleSlider(){
    slideTag.value = passWordLen; 
    passwordNo.textContent  = passWordLen; 
}

slideTag.addEventListener('input', (event)=>{
    passWordLen = event.target.value; 
    handleSlider(); 
})

indicatorfun(color); //call
indicatorfun(color); 
function indicatorfun(color){
    indicator.style.backgroundColor = color; 
    indicator.style.boxShadow = "100px 200px 2px color"; 

}

// Universal formula to get any random no. [min, max}
function getRandomInt(min, max){
   return  Math.floor( Math.random()*(max-min) ) + min ; 
}

function getRandomNumber(){
    return getRandomInt(0, 9); 
}

function getRandomLowerCase(){
    return String.fromCharCode(getRandomInt(97, 123)); 
}

function getRandomUpperCase(){ 
    return String.fromCharCode(getRandomInt(65, 91)); 
}

const symbolArr = "\|<`(>,.?{~!@#[+-=^&*)/$%_}]";
function getRandomSymbol(){ 
    return symbolArr.charAt((getRandomInt(0, symbolArr.length))); 
}

// Calculation of strength of a password and calls for indicator
function calcStrength(){
    let upperVar = uppercase.checked; 
    let lowerVar = lowerCase.checked; 
    let numberVar = number.checked; 
    let symbolVar = symbol.checked; 

    // Own Logic
    if(upperVar && lowerVar && numberVar && symbolVar){
        indicatorfun('#3cb371'); 
    }else if((upperVar && lowerVar && numberVar) || (upperVar && lowerVar &&  symbolVar) || (upperVar && numberVar && symbolVar)){
        indicatorfun('#3cb371')
    }else if((upperVar && lowerVar && !numberVar && !symbolVar) || (upperVar && !lowerVar && !numberVar && symbolVar) || (!upperVar && !lowerVar && numberVar && symbolVar) || (!upperVar && lowerVar && numberVar && !symbolVar)){
        indicatorfun('#ffa500'); 
    }else{
        indicatorfun('#ff0000'); 
    }
}


// Clipboard API fetched function. [WriteText]
async function copyToClipboard(){
    try{
        await navigator.clipboard.writeText(content.textContent);
        copyMsg.textContent = "Copied"; 
    } 
    catch(e){
        copyMsg.textContent = "Failed to copy"; 
    }
    copyMsg.classList.remove("hidden"); 
    // For disappering
    setTimeout(()=>{
        copyMsg.classList.add("hidden"); 
    }, 2000); 
}

copyButton.addEventListener('click', (event) =>{
    if(content.value) copyToClipboard(); // only is password is generated
}); 


// For final output + suffle array - [Protection algo]
// function suffleArr(array){
//     let pass = ""; 
//     for(let i = array.length-1; i>0; i--){
//         let randomInd = getRandomInt(0,array.length); 
//         let temp = array[randomInd]; 
//         array[randomInd] = array[i]; 
//         array[i] = temp; 
//         pass = array[i] + pass ; 
//     }
//     return pass; 
// }


// Actual Brain
function generatePassword(){
    let arr = []; 
    passWord = ""; 
    if(uppercase.checked){
        passWord+= getRandomUpperCase(); 
        arr.push(getRandomUpperCase); 
    }
    if(lowerCase.checked){
        passWord+= getRandomLowerCase(); 
        arr.push(getRandomLowerCase); 
    }
    if(numberInput.checked){
        passWord+= getRandomNumber(); 
        arr.push(getRandomNumber); 
    }
    if(symbol.checked){
        passWord+= getRandomSymbol(); 
        arr.push(getRandomSymbol); 
    }
    // If any check box is not checked.
    if(passWord.length<=0) {
        content.placeholder = "Choose atleast one box";
        return ; 
    }

    for(let i=passWord.length; i<passWordLen; i++){
        let fun = arr[getRandomInt(0, arr.length)](); 
        passWord+= fun; 
    }
    //passWord = suffleArr(Array.from(passWord)); 
    content.value = passWord;
    calcStrength(); 
}

generate.addEventListener('click', generatePassword); 
