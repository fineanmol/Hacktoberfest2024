let screen= document.getElementById('screen');
buttons= document.querySelectorAll('button');
let screenValue='';
for (item of buttons) {
    item.addEventListener('click',(e)=>{
        buttonText= e.target.innerText;
        console.log(buttonText);
        if(buttonText=='X'){
            buttonText='*';
            screenValue+=buttonText;
            screen.value=screenValue;
        }
        else if(buttonText=='C'){
            screenValue= "";
            screen.value=screenValue;
        }
        else if(buttonText=='B')
        {
            screen.value = screen.value.substring(0, screen.value.length - 1);
        }
        else if(buttonText=='='){
            screen.value=eval(screenValue);
        }
        else{
            screenValue+=buttonText;
            screen.value=screenValue;
        }
    })
}