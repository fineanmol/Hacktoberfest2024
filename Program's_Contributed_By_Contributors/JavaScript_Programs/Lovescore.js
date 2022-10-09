//using random number generation


prompt("What is your name?");
prompt("What is their name?");

var lovescore = Math.random()*100;
lovescore = Math.floor(lovescore)+1;

alert("Your lovescore is " + lovescore+"% .");

//using conditional statements

if (lovescore===100){
    alert("Your lovescore is " + lovescore + "% .  You both are made for each other.");
}

if (lovescore>=70){
    alert("Your lovescore is " + lovescore + "% .  You both love each other like Kanye loves Kanye.");
}
 if(lovescore>30 && lovescore<70){
      alert("Your lovescore is " + lovescore + "% . You love them more.");
}

if (lovescore<30){
    alert("Your lovescore is " + lovescore+"% .");
}
