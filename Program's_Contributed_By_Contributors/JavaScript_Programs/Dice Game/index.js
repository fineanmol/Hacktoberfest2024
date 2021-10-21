//Image 1 setting

let randomNumber1 = Math.floor(Math.random() * 6) + 1;
let randomImage = "dice" + randomNumber1 + ".png";
let randomImageSource = "images/" + randomImage;
let image1 = document.querySelectorAll("img")[0];
image1.setAttribute("src", randomImageSource);

//Image 2 setting

let randomNumber2 = Math.floor(Math.random() * 6) + 1;
let randomImage2 = "dice" + randomNumber2 + ".png";
let randomImageSource2 = "images/" + randomImage2;
let image2 = document.querySelectorAll("img")[1];
image2.setAttribute("src", randomImageSource2);

//Which of the players win

if (randomNumber1 > randomNumber2) {
  document.querySelector("h1").innerHTML = "🚩Player 1 wins!";
} else if (randomNumber1 < randomNumber2) {
  document.querySelector("h1").innerHTML = "🚩Player 2 wins!";
} else {
  document.querySelector("h1").innerHTML = "🎲It's a tie!";
}
