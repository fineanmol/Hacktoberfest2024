const cells = document.querySelectorAll('.cell');
const result = document.querySelector('.result');
const newGameBtn = document.getElementById('new-game');  

// Defining the states that will define victory
const winStates = 
[
    ["a1", "b1", "c1"],
    ["a2", "b2", "c2"],
    ["a3", "b3", "c3"],
    ["a1", "a2", "a3"],
    ["b1", "b2", "b3"],
    ["c1", "c2", "c3"],
    ["a1", "b2", "c3"],
    ["a3", "b2", "c1"]
];

// Initializing some dynamic values
let symbol = "X";
let color = "#066de2";
let gameOver = false;
let count = 0;

// Adding an event listener to all the cells
cells.forEach(cell => 
    {
        cell.addEventListener('click', () =>
        {
            if(cell.textContent === "" && !gameOver)
            {
                cell.textContent = symbol;
                cell.style.color = color;
                if(symbol === "X")
                {
                    color = "green";
                    symbol = "O";
                }
                else
                {
                    color = "#066de2";
                    symbol = "X";
                }
                evaluate();
                count++;

                // Checking for a draw
                if(count === 9 && !gameOver)
                {
                    displayWinner("Nobody");
                }
            }
        });
    });

// Adding an event listener to the new game button
newGameBtn.addEventListener('click', () =>
{
    location.reload();
});

// Function to decide victory
function evaluate()
{
    winStates.forEach(winState => 
        {
            let cell1 = document.getElementById(winState[0]).textContent;
            let cell2 = document.getElementById(winState[1]).textContent;
            let cell3 = document.getElementById(winState[2]).textContent;

            if(cell1 && cell2 && cell3)
            {
                if((cell1 === cell2) && (cell2 === cell3))
                {
                    displayWinner(cell1);
                    console.log(cell1 + " Won!");
                    gameOver = true;
                    return;
                }
            }
        });
}

// Function to display winner
function displayWinner(cell)
{
    result.querySelector('h1').textContent = cell + " Won!";
}