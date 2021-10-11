let randomnumber1 = Math.floor(Math.random() * 6) + 1;
let randomdice = "images/" + "dice" + randomnumber1 + ".png";
let image1 = document.querySelectorAll("img")[0];
image1.setAttribute("src",randomdice);
let image2 = document.querySelectorAll("img")[1];
image2.setAttribute("src",randomdice);