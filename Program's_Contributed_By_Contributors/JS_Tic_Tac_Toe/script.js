let currentPlayer = 'X';
const cells = document.querySelectorAll( '.cell' );
const status = document.querySelector( '.status' );

/**
 * function to check if there is a winner
 * @returns 
 */
function checkWinner()
{
    const winningCombos = [
        [ 0, 1, 2 ],
        [ 3, 4, 5 ],
        [ 6, 7, 8 ],
        [ 0, 3, 6 ],
        [ 1, 4, 7 ],
        [ 2, 5, 8 ],
        [ 0, 4, 8 ],
        [ 2, 4, 6 ]
    ];

    for ( const combo of winningCombos )
    {
        const [ a, b, c ] = combo;
        if ( cells[ a ].innerHTML && cells[ a ].innerHTML === cells[ b ].innerHTML && cells[ a ].innerHTML === cells[ c ].innerHTML )
        {
            return cells[ a ].innerHTML;
        }
    }

    if ( [ ...cells ].every( cell => cell.innerHTML !== '' ) )
    {
        return 'Draw';
    }

    return null;
}

/**
 * function to update the status
 */
function updateStatus()
{
    const winner = checkWinner();
    if ( winner )
    {
        if ( winner === 'Draw' )
        {
            status.textContent = "It's a Draw!";
        } else
        {
            status.textContent = `Player ${ winner } wins!`;
        }
    } else
    {
        status.textContent = `Player ${ currentPlayer }'s turn`;
    }
}

/**
 * function to make a move
 * @param {*} cellIndex 
 */
function makeMove( cellIndex )
{
    if ( cells[ cellIndex ].innerHTML === '' && !checkWinner() )
    {
        cells[ cellIndex ].innerHTML = currentPlayer;
        currentPlayer = currentPlayer === 'X' ? 'O' : 'X';
        updateStatus();
    }
}

function resetBoard()
{
    cells.forEach( cell => cell.innerHTML = '' );
    currentPlayer = 'X';
    updateStatus();
}

updateStatus();
