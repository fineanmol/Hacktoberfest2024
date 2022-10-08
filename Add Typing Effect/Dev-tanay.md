# HTML

<button onClick='typeWriter()' id='1'>typewritter 1</button>

<p id="demo"></p>

# JS

let i = 0;
let text = "This is text for section 3!";
let speed = 175;

function typeWriter(button) {
  // console.log(button.id);
  
   if(i < text.length) {
       document.getElementById("demo").innerHTML += text.charAt(i);
       i++;
       setTimeout(typeWriter, speed);
   }
}
