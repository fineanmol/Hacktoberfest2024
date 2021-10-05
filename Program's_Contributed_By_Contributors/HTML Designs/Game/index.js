var initialTime = '01:00'
var score = 0
var intervalTimer = null
var isRunning  = false
var currentColor = null
var color = null
var colorPalette = ['Blue','Red','Yellow']


// ELEMENTS START

const CHRONOMETER = document.getElementById('chronometer')
const CURRENTEXT = document.getElementById('currentText')

// ELEMENTS END
function changeColorStyle (){
    if ( currentColor === 'Blue'){
        CURRENTEXT.style.color = '#004283'
    } else if ( currentColor === 'Red') {
        CURRENTEXT.style.color = '#ff0000'
    }else{
        CURRENTEXT.style.color = '#FFA400'
    }
}
function checkOut() {
    if (currentColor === color){
        score++
        currentColor = colorPalette[Math.floor(Math.random() * (4 - 1))]
        CURRENTEXT.innerText = currentColor
        changeColorStyle ()

    }else {
        alert(`GAME OVER YOUR SCORE IS  ${score} `);
        window.location.reload();
    }

}
function changeColor (oneColor) {
    if(isRunning){
    color = oneColor
    checkOut() 
    }
}


function startTimer (time = initialTime) {
  if (!isRunning){
    const minutesSeconds = time.split(':')  
    var minutes = parseInt(minutesSeconds[0])
    var displayMinutes = null
    var seconds = parseInt(minutesSeconds[1])
    var displaySeconds = null
    intervalTimer = setInterval(function () {
      if (seconds === 0) {
        seconds = 60
      }
      if (seconds > 0) {
        seconds = seconds - 1
      }
      if (minutes > 0 && seconds === 59) {
        minutes = minutes - 1
      }
      if (minutes < 10) {
        displayminutes = '0' + minutes
      } else {
        displayminutes = minutes
      }
      if (seconds < 10) {
        displayseconds = '0' + seconds
      } else {
        displayseconds = seconds
      }
      currentTimer = displayminutes + ':' + displayseconds
      isRunning = true
      CHRONOMETER.innerText = currentTimer
      if (minutes === 0 && seconds === 0) {
          isRunning =false
          alert(`CONGRATULATIONS  YOUR SCORE IS  ${score} `); 
          window.location.reload(); 
      }
    }, 1000)
  }
}

window.onload = function () {
    // this code add the currentTimer on the chronometer element when is kikan
    CHRONOMETER.innerText = initialTime
    currentColor = colorPalette[Math.floor(Math.random() * (4 - 1))]
    CURRENTEXT.innerText = currentColor
    changeColorStyle ()
  
}