'use strict'
let secretNumber = Math.trunc(Math.random() * 20) + 1
let score = 20;
let highscore = 0;
let message = document.querySelector('.message')
let scoreValue = document.querySelector('.score-point')
let highscoreValue = document.querySelector('.highscore-point')

// Display Message
function displayMessage(messages)
{
    document.querySelector('.message').textContent = messages
}
function changeColor(){
    document.querySelector('.random-value').style.color = '#F2F5FD'
    document.querySelector('.title').style.color = '#F2F5FD'
    document.querySelector('.message').style.color = '#F2F5FD'
    document.querySelector('.score').style.color = '#F2F5FD'
    document.querySelector('.highscore').style.color = '#F2F5FD'
    document.querySelector('.githubprofile').style.color = '#FFCE61'
}
function resetColor(){
    document.querySelector('.random-value').style.color = '#7391B4'
    document.querySelector('.title').style.color = '#7391B4'
    document.querySelector('.message').style.color = '#7391B4'
    document.querySelector('.score').style.color = '#7391B4'
    document.querySelector('.highscore').style.color = '#7391B4'
    document.querySelector('.githubprofile').style.color = '#FFCE61'

}
// Decrease Score
function decreaseScore(){
    score--
    console.log(score)
    scoreValue.textContent = score
}
// Check Button
document.querySelector('.check').addEventListener('click',() =>{
    let guess = Number(document.querySelector('.guess').value)

    // When there is no input
    if(score > 1)
    {
        if(!guess)
        {
            displayMessage('⛔ Cannot be Empty!')
            decreaseScore()
        }
        else if(guess !== secretNumber)
        {
            guess > secretNumber ? displayMessage('⬆️ Higher Guess') : displayMessage('⬇️ Lower Guess')
            decreaseScore()
        }
    else{
        displayMessage('🎉 Correct Answer')
        document.querySelector('.random-value').textContent = secretNumber

        highscore = score
        highscoreValue.textContent = highscore
        document.body.style.backgroundColor = 'green'
        document.body.style.color = 'whitesmoke'


    }
}
else {
    scoreValue.textContent = 0;
    displayMessage('☠️ Game Over!!')
    document.body.style.backgroundColor = 'red'

}
})
// Reset Button
document.querySelector('.reset').addEventListener('click',()=>{
    message.textContent = 'Start Guessing...'
    document.querySelector('.random-value').textContent = '?';
    document.querySelector('.guess').value = '';
    score = 20
    scoreValue.textContent = 20
    highscoreValue.textContent = 0
    document.body.style.backgroundColor = ''
    document.body.style.color = '#7391B4'
	 secretNumber = Math.trunc(Math.random() * 20) + 1
})
