var randomNumber1 = Math.floor(Math.random()*6) + 1;

var randomDiceImage = "dice"+randomNumber1+".png";

var randomImageSource = "images/" + randomDiceImage;

var image1 = document.querySelectorAll("img")[0];
image1.setAttribute("src", randomImageSource);


var randomNumber2 = Math.floor(Math.random()*6) + 1;
var randomDiceImage2 = "dice"+randomNumber2+".png";
var randomImageSource2 = "images/" + randomDiceImage2;
var image2 = document.querySelectorAll("img")[1];
image2.setAttribute("src", randomImageSource2);


if (randomNumber1 > randomNumber2){
  document.querySelector("h1").innerHTML = "Player 1 Wins!🚩";
}
else if(randomNumber1 < randomNumber2){
  document.querySelector("h1").innerHTML = "Player 2 Wins!🚩";
}

else if (randomNumber1 = randomNumber2){
  document.querySelector("h1").innerHTML = "Draw!";
}











// function random(num){
//   return Math.floor( Math.random()*num);
// }
// var randomNumber1 = random(6);
// console.log(randomNumber1);

// randomImages = ["images\dice1.png","images/dice2.png","images/dice3.png","images/dice4.png","images/dice5.png","images/dice6.png"];
// var randomNumber1 = Math.floor(Math.random()*randomImages.length);
//
// document.querySelector(".img1").setAttribute("src", randomNumber1);
//
// //randomImages = ["images/dice1.png","images/dice2.png","images/dice3.png","images/dice4.png","images/dice5.png","images/dice6.png"];
// var randomNumber2 = Math.floor(Math.random()*randomImages.length);
//
// document.querySelector(".img2").setAttribute("src", randomNumber2);

// function whosPaying(names) {
//
//     var numberOfPeople  = names.length;
//     var ran = Math.floor(Math.random() * numberOfPeople);
//     var randomPerson = names[ran];
//     return randomPerson+ " is going to buy lunch today!";
// }
