var userClickedPattern = [];
var buttonColours = ["red", "blue", "green", "yellow"];
var gamePattern = [];
var userClickedPattern = [];
var started = false;
var lvl = 0;

// DETECTING KEYPRESS FOR GAME START AND CHANGING H1 TEXT TO LEVELS
$(document).keypress(function() {
  if (!started) {
    $("#level-title").text("Level " + lvl);
    nextSequence();
    started = true;
  }
});

// USER SELECTED PATTERN IN AN ARRAY
$(".btn").click(function() {
  var userChosenColor = $(this).attr("id");
  userClickedPattern.push(userChosenColor);
  // console.log(userClickedPattern);

  playSound(userChosenColor);
  animatePress(userChosenColor);
  checkAnswer(userClickedPattern.length - 1);
});

// CHECKING ANSWERS OF USERS
function checkAnswer(currentLevel) {

  if (gamePattern[currentLevel] === userClickedPattern[currentLevel]) {

    //4. If the user got the most recent answer right in step 3, then check that they have finished their sequence with another if statement.
    if (userClickedPattern.length === gamePattern.length) {
      setTimeout(function() {
        nextSequence();
      }, 1000);
    }
  } else {
    playSound("wrong");
    $("body").addClass("game-over");
    $("#level-title").text("Game Over, Press any key to restart").css("font-size", "2rem");
    setTimeout(function() {
      $("body").removeClass("game-over");
    }, 200);
    startOver();
  }
}

// RANDOMLY GENERATED PATTERN IN AN ARRAY
function nextSequence() {
  userClickedPattern = [];
  lvl++;
  $("#level-title").text("Level " + lvl);
  var randomNumber = Math.floor(Math.random() * 4);
  var randomChosenColor = buttonColours[randomNumber];
  gamePattern.push(randomChosenColor);

  $("#" + randomChosenColor).fadeIn(100).fadeOut(100).fadeIn(100);

  playSound(randomChosenColor);
}

// PLAYING SOUND COMMON FOR BOTH
function playSound(name) {
  var audio = new Audio("sounds/" + name + ".mp3");
  audio.play();
}

// ANIMATING PRESS BUTTON AND ADDING DELAY
function animatePress(currentColor) {
  $("#" + currentColor).addClass("pressed");
  setTimeout(function() {
    $(".btn").removeClass("pressed");
  }, 100);
}

// Reset every variable -------------
function startOver() {
  lvl = 0;
  gamePattern = [];
  started = false;
}
