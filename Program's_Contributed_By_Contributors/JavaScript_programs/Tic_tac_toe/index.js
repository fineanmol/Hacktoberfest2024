const gameContainer = document.querySelector('.game-container')
const gameTitle = document.querySelector('[game-title]')


const gameObject = {
    playerTurn: 'X',
    changePlayerTurn: () => {
        const playerTurn = gameObject.playerTurn === 'X' ? 'O' : 'X'
        gameObject.playerTurn = playerTurn
        gameTitle.innerHTML = `Player ${playerTurn} time`
    }
}

function checkVictory(innerArray, player) {
    const winHorizontal = innerArray[0] == player && innerArray[1] == player && innerArray[2]== player || 
        innerArray[3] == player && innerArray[4] == player && innerArray[5]== player ||
        innerArray[6] == player && innerArray[7] == player && innerArray[8] == player
    
    const winVertical = innerArray[0] == player && innerArray[3] == player && innerArray[6]== player || 
        innerArray[1] == player && innerArray[4] == player && innerArray[7]== player ||
        innerArray[2] == player && innerArray[5] == player && innerArray[8]== player
    
    const winDiagonal =  innerArray[0] == player && innerArray[4] == player && innerArray[8]== player || 
        innerArray[2] == player && innerArray[4] == player && innerArray[6]== player

    return winHorizontal || winVertical || winDiagonal
}

function checkForEnd() {
    const gameParts = [...gameContainer.children]
    const innerArray = gameParts.map(part => part.innerHTML)
    const playerXwin = checkVictory(innerArray, 'X')
    const playerOwin = checkVictory(innerArray, 'O')
    if (playerXwin || playerOwin) {
        divRemoveOnClick()
        gameTitle.innerHTML = `Player ${playerXwin ? 'X' : 'O'} wins!`
    } else {
        const innerReduced = innerArray.reduce((prev, curr) => prev += curr, '')
        if(innerReduced.length === 9) {
            divRemoveOnClick()
            gameTitle.innerHTML = `Draw!`
        }
    }
}

function divRemoveOnClick() {
    const gameParts = [...gameContainer.children]
    gameParts.forEach( element => element.removeEventListener('click', divSetOnClick))
}

function divSetOnClick(event) {
    const div = event.srcElement
    div.innerHTML = gameObject.playerTurn === 'X' ? 'X' : 'O'
    div.removeEventListener('click', divSetOnClick)
    gameObject.changePlayerTurn()
    checkForEnd()
}

function setOnClickGameDivs() {
    const gameParts = [...gameContainer.children]
    gameParts.forEach(element => {
        element.addEventListener('click', divSetOnClick)
    })
}

setOnClickGameDivs()