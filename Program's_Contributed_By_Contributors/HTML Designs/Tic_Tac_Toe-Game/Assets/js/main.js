console.log("This is a tic tac toe fun game");

// Game Logic
let play = document.getElementById("play");
// console.log(modal);
let modal = document.getElementById("modal");

//range js
var range = document.querySelector('input[type="range"]');
var rounds = document.getElementById("rounds").value;

var rangeValue = function () {
  var newValue = range.value;
  var target = document.querySelector(".value");
  target.innerHTML = newValue;
  rounds = target.innerHTML;
};

range.addEventListener("input", rangeValue);
var player1Score = document.getElementById("plrscr1");
var player2Score = document.getElementById("plrscr2");

play.addEventListener("click", () => {
  let player1 = document.getElementById("player1").value;
  let player2 = document.getElementById("player2").value;
  if (player1 && player2 != undefined) {
    document.getElementById("plr1").innerHTML = `${player1} | <i class="fa-solid fa-xmark"></i> |`;
    document.getElementById("plr2").innerHTML = `${player2} | <i class="fa-regular fa-o"></i> |`;
    document.getElementById("score-1").innerText = player1;
    document.getElementById("score-2").innerText = player2;
  }
  
  console.log("close the modal");
  modal.classList.add("modal_close");
});
var roundsWon_x = 0;
var roundsWon_o = 0;
let clicked_box = [];
let arr_x = [];
let arr_o = [];
turn = "1";
// plr1 = document.getElementById("plr1");
// plr1.classList.add("plr1_xo");
boxes = document.getElementsByClassName("box");

Array.from(boxes).forEach((item) => {
  item.addEventListener("click", () => {
    console.log("box clicked");

    //here if turn is 1, then adding that box's id to arr_x array
    if (turn == "1" && clicked_box.includes(item.id) == false) {
      item.classList.add("fa-solid", "fa-xmark", "fa-3x", "color_x");
      arr_x.push(item.id);
      clicked_box.push(item.id);
      plr1 = document.getElementById("plr1");
      plr1.classList.remove("plr1_xo");
      plr2 = document.getElementById("plr2");
      plr2.classList.add("plr1_xo");


      //now for each box checking if its' complimentary boxes are in arr_x or not || if yes then that entry won
      if (item.id == "box1") {
        console.log("box 1 clicked");
        if (
          (arr_x.includes("box2") == true && arr_x.includes("box3") == true) ||
          (arr_x.includes("box4") == true && arr_x.includes("box7") == true) ||
          (arr_x.includes("box5") == true && arr_x.includes("box9") == true)
        ) {
          roundsWon_x++;
          player1Score.innerHTML = roundsWon_x;
          if (roundsWon_x == rounds) {
            win_modal();
          } else {
            reset_modal();
          }
        } else if (clicked_box.length == 9)  {
            draw_reset_modal();
          }
        
      } else if (item.id == "box2") {
        if (
          (arr_x.includes("box1") == true && arr_x.includes("box3") == true) ||
          (arr_x.includes("box5") == true && arr_x.includes("box8") == true)
        ) {
          roundsWon_x++;
          player1Score.innerHTML = roundsWon_x;
          if (roundsWon_x == rounds) {
            win_modal();
          }  else {
            reset_modal();
          }
          
        } else if (clicked_box.length == 9) {
          draw_reset_modal();
        }
      } else if (item.id == "box3") {
        if (
          (arr_x.includes("box2") == true && arr_x.includes("box1") == true) ||
          (arr_x.includes("box5") == true && arr_x.includes("box7") == true) ||
          (arr_x.includes("box6") == true && arr_x.includes("box9") == true)
        ) {
          roundsWon_x++;
          player1Score.innerHTML = roundsWon_x;
          if (roundsWon_x == rounds) {
            win_modal();
          } else {
            reset_modal();
          }
        } else if (clicked_box.length == 9) {
          draw_reset_modal();
        }
      } else if (item.id == "box4") {
        if (
          (arr_x.includes("box1") == true && arr_x.includes("box7") == true) ||
          (arr_x.includes("box5") == true && arr_x.includes("box6") == true)
        ) {
          roundsWon_x++;
          player1Score.innerHTML = roundsWon_x;
          if (roundsWon_x == rounds) {
            win_modal();
          } else {
            reset_modal();
          }
        } else if (clicked_box.length == 9) {
          draw_reset_modal();
        }
      } else if (item.id == "box5") {
        if (
          (arr_x.includes("box1") == true && arr_x.includes("box9") == true) ||
          (arr_x.includes("box2") == true && arr_x.includes("box8") == true) ||
          (arr_x.includes("box3") == true && arr_x.includes("box7") == true) ||
          (arr_x.includes("box4") == true && arr_x.includes("box6") == true)
        ) {
          roundsWon_x++;
          player1Score.innerHTML = roundsWon_x;
          if (roundsWon_x == rounds) {
            win_modal();
          } else {
            reset_modal();
          }
        } else if (clicked_box.length == 9) {
          draw_reset_modal();
        }
      } else if (item.id == "box6") {
        if (
          (arr_x.includes("box5") == true && arr_x.includes("box4") == true) ||
          (arr_x.includes("box3") == true && arr_x.includes("box9") == true)
        ) {
          roundsWon_x++;
          player1Score.innerHTML = roundsWon_x;
          if (roundsWon_x == rounds) {
            win_modal();
          } else {
            reset_modal();
          }
        } else if (clicked_box.length == 9) {
          draw_reset_modal();
        }
      } else if (item.id == "box7") {
        if (
          (arr_x.includes("box5") == true && arr_x.includes("box3") == true) ||
          (arr_x.includes("box4") == true && arr_x.includes("box1") == true) ||
          (arr_x.includes("box8") == true && arr_x.includes("box9") == true)
        ) {
          roundsWon_x++;
          player1Score.innerHTML = roundsWon_x;
          if (roundsWon_x == rounds) {
            win_modal();
          } else {
            reset_modal();
          }
        } else if (clicked_box.length == 9) {
          draw_reset_modal();
        }
      } else if (item.id == "box8") {
        if (
          (arr_x.includes("box2") == true && arr_x.includes("box5") == true) ||
          (arr_x.includes("box7") == true && arr_x.includes("box9") == true)
        ) {
          roundsWon_x++;
          player1Score.innerHTML = roundsWon_x;
          if (roundsWon_x == rounds) {
            win_modal();
          } else {
            reset_modal();
          }
        } else if (clicked_box.length == 9) {
          draw_reset_modal();
        }
      } else if (item.id == "box9") {
        if (
          (arr_x.includes("box7") == true && arr_x.includes("box8") == true) ||
          (arr_x.includes("box6") == true && arr_x.includes("box3") == true) ||
          (arr_x.includes("box5") == true && arr_x.includes("box1") == true)
        ) {
          roundsWon_x++;
          player1Score.innerHTML = roundsWon_x;
          if (roundsWon_x == rounds) {
            win_modal();
          } else {
            reset_modal();
          }
        } else if (clicked_box.length == 9) {
          draw_reset_modal();
        }
      }
      turn = "0";
      //here if turn is 1, then adding that box's id to arr_x array
    } else if (turn == "0" && clicked_box.includes(item.id) == false) {
      item.classList.add("fa-regular", "fa-o", "fa-3x", "color_o");
      arr_o.push(item.id);
      clicked_box.push(item.id);
      plr1 = document.getElementById("plr1");
      plr1.classList.add("plr1_xo");
      plr2 = document.getElementById("plr2");
      plr2.classList.remove("plr1_xo");

      //now for each box checking if its' complimentary boxes are in arr_x or not || if yes then that entry won
      if (item.id == "box1") {
        if (
          (arr_o.includes("box2") == true && arr_o.includes("box3") == true) ||
          (arr_o.includes("box4") == true && arr_o.includes("box7") == true) ||
          (arr_o.includes("box5") == true && arr_o.includes("box9") == true)
        ) {
          roundsWon_o++;
          player2Score.innerHTML = roundsWon_o;
          if (roundsWon_o == rounds) {
            win_modal();
          } else {
            reset_modal();
          }
        } else if (clicked_box.length == 9) {
          draw_reset_modal();
        }
      } else if (item.id == "box2") {
        if (
          (arr_o.includes("box1") == true && arr_o.includes("box3") == true) ||
          (arr_o.includes("box5") == true && arr_o.includes("box8") == true)
        ) {
          roundsWon_o++;
          player2Score.innerHTML = roundsWon_o;
          if (roundsWon_o == rounds) {
            win_modal();
          } else {
            reset_modal();
          }
        } else if (clicked_box.length == 9) {
          draw_reset_modal();
        }
      } else if (item.id == "box3") {
        if (
          (arr_o.includes("box2") == true && arr_o.includes("box1") == true) ||
          (arr_o.includes("box5") == true && arr_o.includes("box7") == true) ||
          (arr_o.includes("box6") == true && arr_o.includes("box9") == true)
        ) {
          roundsWon_o++;
          player2Score.innerHTML = roundsWon_o;
          if (roundsWon_o == rounds) {
            win_modal();
          } else {
            reset_modal();
          }
        } else if (clicked_box.length == 9) {
          draw_reset_modal();
        }
      } else if (item.id == "box4") {
        if (
          (arr_o.includes("box1") == true && arr_o.includes("box7") == true) ||
          (arr_o.includes("box5") == true && arr_o.includes("box6") == true)
        ) {
          roundsWon_o++;
          player2Score.innerHTML = roundsWon_o;
          if (roundsWon_o == rounds) {
            win_modal();
          } else {
            reset_modal();
          }
        } else if (clicked_box.length == 9) {
          draw_reset_modal();
        }
      } else if (item.id == "box5") {
        if (
          (arr_o.includes("box1") == true && arr_o.includes("box9") == true) ||
          (arr_o.includes("box2") == true && arr_o.includes("box8") == true) ||
          (arr_o.includes("box3") == true && arr_o.includes("box7") == true) ||
          (arr_o.includes("box4") == true && arr_o.includes("box6") == true)
        ) {
          roundsWon_o++;
          player2Score.innerHTML = roundsWon_o;
          if (roundsWon_o == rounds) {
            win_modal();
          } else {
            reset_modal();
          }
        } else if (clicked_box.length == 9) {
          draw_reset_modal();
        }
      } else if (item.id == "box6") {
        if (
          (arr_o.includes("box5") == true && arr_o.includes("box4") == true) ||
          (arr_o.includes("box3") == true && arr_o.includes("box9") == true)
        ) {
          roundsWon_o++;
          player2Score.innerHTML = roundsWon_o;
          if (roundsWon_o == rounds) {
            win_modal();
          } else {
            reset_modal();
          }
        } else if (clicked_box.length == 9) {
          draw_reset_modal();
        }
      } else if (item.id == "box7") {
        if (
          (arr_o.includes("box5") == true && arr_o.includes("box3") == true) ||
          (arr_o.includes("box4") == true && arr_o.includes("box1") == true) ||
          (arr_o.includes("box8") == true && arr_o.includes("box9") == true)
        ) {
          roundsWon_o++;
          player2Score.innerHTML = roundsWon_o;
          if (roundsWon_o == rounds) {
            win_modal();
          } else {
            reset_modal();
          }
        } else if (clicked_box.length == 9) {
          draw_reset_modal();
        }
      } else if (item.id == "box8") {
        if (
          (arr_o.includes("box2") == true && arr_o.includes("box5") == true) ||
          (arr_o.includes("box7") == true && arr_o.includes("box9") == true)
        ) {
          roundsWon_o++;
          player2Score.innerHTML = roundsWon_o;
          if (roundsWon_o == rounds) {
            win_modal();
          } else {
            reset_modal();
          }
        } else if (clicked_box.length == 9) {
          draw_reset_modal();
        }
      } else if (item.id == "box9") {
        if (
          (arr_o.includes("box7") == true && arr_o.includes("box8") == true) ||
          (arr_o.includes("box6") == true && arr_o.includes("box3") == true) ||
          (arr_o.includes("box5") == true && arr_o.includes("box1") == true)
        ) {
          roundsWon_o++;
          player2Score.innerHTML = roundsWon_o;
          if (roundsWon_o == rounds) {
            win_modal();
          } else {
            reset_modal();
          }
        } else if (clicked_box.length == 9) {
          draw_reset_modal();
        }
      }

      turn = "1";
    }
    
  });
});

const reset_btn = document.getElementById("reset");
reset_btn.addEventListener("click", reset_function);

const exit_btn = document.getElementById("exit");
exit_btn.addEventListener("click", () => {
  arr_x = [];
  arr_o = [];
  window.location.reload();
});


// reset function

function reset_function() {
  Array.from(boxes).forEach((item) => {
    item.classList.remove(
      "fa-solid",
      "fa-xmark",
      "fa-5x",
      "fa-regular",
      "fa-o",
      "fa-5x",
      "color_x",
      "color_o"
    );
  });
  turn = "1";
  arr_x = [];
  arr_o = [];
  clicked_box = [];
  plr1 = document.getElementById("plr1");
  plr1.classList.remove("plr1_xo");
  plr2 = document.getElementById("plr2");
  plr2.classList.remove("plr1_xo");
  let reset_modal = document.getElementById("end");
  reset_modal.classList.add("end_hidden");
  let draw_reset_modal = document.getElementById("draw");
  draw_reset_modal.classList.add("end_hidden");
  let win_modal = document.getElementById("win_modal");
  let message_box = document.getElementById("message_box");
  win_modal.classList.add("win_modal_hidden");
  message_box.classList.add("message_box_hidden");
}
//reset after win
function reset_modal() {
  let reset_modal = document.getElementById("end");
  reset_modal.classList.remove("end_hidden");
  reset_modal.addEventListener("click", () => {
    reset_function();
  });
}

function draw_reset_modal() {
  let draw_reset_modal = document.getElementById("draw");
  draw_reset_modal.classList.remove("end_hidden");
  draw_reset_modal.addEventListener("click", () => {
    reset_function();
  });
}

// winning modal

function win_modal() {
  let win_modal = document.getElementById("win_modal");
  let message_box = document.getElementById("message_box");
  var plr1Won = document.getElementById("score-1").innerText;
  var plr2Won = document.getElementById("score-2").innerText;
  if(turn == "1"){
    var winner = document.getElementById("winner");
    winner.innerHTML = `Yay ! ${plr1Won} <i class='bx bx-crown bx-tada' ></i>  won`
  }
  else if(turn == "0"){
    var winner = document.getElementById("winner");
    winner.innerHTML = `Yay! ${plr2Won}  <i class='bx bx-crown bx-tada' ></i> won`
  };
  message_box.classList.remove("message_box_hidden");
  win_modal.classList.remove("win_modal_hidden");
  let won = document.getElementById("won");
  won.addEventListener("click", () => {
    window.location.reload();
  });
}
