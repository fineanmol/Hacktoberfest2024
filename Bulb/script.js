// var a = document.querySelector("h1");
// console.log(a);

// a.innerHTML = "Hattt Ben Stokes😒";

// a.style.color = "red";

// a.addEventListener("click",function(){
//     // console.log("Viraaaat KOHHHHHLIIIII");
//     a.innerHTML = "Viraaaat KOHHHHHLIIIII";
// })

var bulb = document.querySelector(".bulb")
var btn = document.querySelector("button")
var flag = 0

btn.addEventListener("click",function(){
    if(flag==0){
        bulb.style.backgroundColor = "yellow"
        btn.innerHTML = "OFF"
        flag = 1
    }
    else{
        bulb.style.backgroundColor = "transparent"
        btn.innerHTML = "ON"
        flag = 0
    }
})
