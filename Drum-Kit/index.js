/* document.querySelectorALL("button")[0].addEventListener("click",handleClick);
/ document.querySelectorALL("button")[1].addEventListener("click",handleClick);
/ document.querySelectorALL("button")[2].addEventListener("click",handleClick);
/ document.querySelectorALL("button")[3].addEventListener("click",handleClick);
/ document.querySelectorALL("button")[4].addEventListener("click",handleClick);
/ document.querySelectorALL("button")[5].addEventListener("click",handleClick);
/ document.querySelectorALL("button")[6].addEventListener("click",handleClick);
                        ||
                        ||
                        ||
                        ||
                        \/

*/
    


var numberOfButtons = document.querySelectorAll(".drum").length;
for (var i = 0; i < numberOfButtons; i++) {
    document.querySelectorAll(".drum")[i].addEventListener("click",function(){
        var buttonInnerHTML = this.innerHTML;
       makeSound(buttonInnerHTML);
       buttonAnimation(buttonInnerHTML);
    });
};

document.addEventListener("keypress",function(event) {
    makeSound(event.key);
    buttonAnimation(event.key);
});

function makeSound(key) {
    // var key = this.innerHTML;
    switch (key) {
        case "w":
            var tom1 = new Audio('sounds/tom-1.mp3');
            tom1.play();
            break;
        case "a":
            var tom2 = new Audio('sounds/tom-2.mp3');
            tom2.play();
            break;
        case "s":
            var tom3 = new Audio('sounds/tom-3.mp3');
            tom3.play();
            break;
        case "d":
            var tom4 = new Audio('sounds/tom-4.mp3');
            tom4.play();
            break;
        case "j":
            var snare = new Audio('sounds/snare.mp3');
            snare.play();
            break;
        case "k":
            var crash = new Audio('sounds/crash.mp3');
            crash.play();
            break;
        case "l":
            var kick = new Audio('sounds/kick-bass.mp3');
            kick.play();
            break;
        default :
            console.log("Not pressed");
            break;
    }
}

function buttonAnimation(currerntKey) {
    activeKey = document.querySelector("." + currerntKey);
    activeKey.classList.add("pressed");
    setTimeout(function(){
        activeKey.classList.remove("pressed");
    },100);
}



// var audio = new Audio('sounds/tom-1.mp3');
// audio.play();


// Event AudioListener : 
/*
First finds the first button in the whole document and then it adds event listener to that
button so that it listens for click that happen on that button and when it does it runs the 
code inside the function and that is "handleClick".

----------
document.querySelector("button").addEventListener("click",handleClick);
function handleClick(){
    alert("I got clicked!");
}
----------
*Important point* -- > if we had written this document.querySelector("button").addEventListener("click",handleClick());
                                                                                                            ^
                                                                                                            |
                                                                This is straight up method call-------  ----
                                It will call this method straight away while adding eventListener.


Above code can also be written as--
document.querySelector("button").eventListener("click",function(){
    alert("I got clicked");
});
*/