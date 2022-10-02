let userscore = 0;
let computerscore = 0;
const whowins = document.querySelector("#whowins");
const score = document.querySelector("#score");

function startGame(e){
    let userChoice = e;
    let computerChoices = ["rock", "paper", "scissor"];
    let computerChoice = computerChoices[Math.floor(Math.random()*3)];
    console.log(computerChoice);
    let winner = compare(userChoice, computerChoice);
    whowins.classList = " ";

    if (winner == "User") {
        whowins.innerHTML = winner+" Wins";
        whowins.classList.add("win");
    }
    else if(winner == "Computer "){
        whowins.innerHTML = winner + "wins";
        whowins.classList.add("lose");
    }
    else{
        whowins.innerHTML = winner;
        whowins.classList.add("tie");
    }

    score.innerHTML = `<span class = "sides">User:${userscore}</span>
            <span class = "sides">Computer: ${computerscore}</span>`;

    

    function compare(choice1, choice2){
        if (choice1 === choice2) {
            return "Its a tie!";
        }
        else if(choice1 === "rock"){
            if(choice2 === "scissor"){
                userscore++;
                return "User";
            }
            else if(choice2 === "paper"){
                computerscore++;
                return "Computer";
            }
        }
        else if( choice1 === "paper"){
            if (choice2 === "scissor") {
                computerscore++;
                return "Computer";
            } 
            else if(choice2 === "rock") {
                userscore++;
                return "User";
            }
        }
        else if(choice1 === "scissor"){
            if(choice2 === "paper"){
                userscore++;
                return "User";
            }
            else if (choice2 === "rock"){
                computerscore++;
                return "Computer";
            }
        }
    }
}