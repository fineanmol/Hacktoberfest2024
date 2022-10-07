

var player1 = prompt("Player One: Enter Your Name , You will be Blue");
console.log("Player One is :- " + player1)
var player1Color = 'rgb(86, 151, 255)';
var player2 = prompt("Player Two: Enter Your Name , You will be Red");
console.log("Player Two is :- " + player2)
var player2Color = 'rgb(237, 45, 73)';
var game_on = true;
var table = $('table tr');

function reportwin(rowNum, colNum) {
    console.log(currentName + " You won starting at this row,col :- (" + (rowNum + 1) + "," + (colNum + 1) + ")");

}

function changeColor(rowIndex, colIndex, color) {
    return table.eq(rowIndex).find('td').eq(colIndex).find('button').css('background-color', color);
}

function returnColor(rowIndex, colIndex) {
    return table.eq(rowIndex).find('td').eq(colIndex).find('button').css('background-color');
}
function checkBottom(colIndex) {
    var colorReport = returnColor(5, colIndex)
    for (var row = 5; row > -1; row--) {
        colorReport = returnColor(row, colIndex);
        if (colorReport === 'rgb(128, 128, 128)') {
            return row
        }
    }
}
function colorMatchCheck(one, two, three, four) {
    return (one === two && one === three && one === four && one !== 'rgb(128, 128, 128)' && one !== undefined)
}
function horizontalWinCheck() {
    for (var row = 0; row < 6; row++) {
        for (var col = 0; col < 4; col++) {
            if (colorMatchCheck(returnColor(row, col), returnColor(row, col + 1), returnColor(row, col + 2), returnColor(row, col + 3))) {
                console.log('Horizontal Win');
                reportwin(row, col);
                return true;
            } else {
                continue;
            }
        }
    }
}
function verticalWinCheck() {
    for (var col = 0; col < 7; col++) {
        for (var row = 0; row < 3; row++) {
            if (colorMatchCheck(returnColor(row, col), returnColor(row + 1, col), returnColor(row + 2, col), returnColor(row + 3, col))) {
                console.log('Vertical Win');
                reportwin(row, col);
                return true;
            } else {
                continue;
            }
        }
    }
}
function diagonalWinCheck() {
    for (var col = 0; col < 5; col++) {
        for (var row = 0; row < 7; row++) {
            if (colorMatchCheck(returnColor(row, col), returnColor(row + 1, col + 1), returnColor(row + 2, col + 2), returnColor(row + 3, col + 3))) {
                console.log('Diagonal Win');
                reportwin(row, col);
                return true;
            } else if (colorMatchCheck(returnColor(row, col), returnColor(row - 1, col + 1), returnColor(row - 2, col + 2), returnColor(row - 3, col + 3))) {

                reportwin(row, col);
                return true;
            } else {
                continue;
            }
        }
    }
}
var currentPlayer = 1;
var currentName = player1;
var currentColor = player1Color;

$('h3').text(player1 + " it is your turn, pick a column to drop in!")

$('.board button').on('click', function () {
    var col = $(this).closest('td').index();
    var bottomAvail = checkBottom(col);
    changeColor(bottomAvail, col, currentColor);
    if (horizontalWinCheck() || verticalWinCheck() || diagonalWinCheck()) {
        $('h1').text(currentName + " You have Won!")
        $("h2").text("Refresh to play again")
        $('h3').fadeOut(20);
        $('.container').fadeOut(3000);
        console.log(currentName + " You have Won!")
        game_on = false;
    }
    currentPlayer = currentPlayer * -1;
    if (currentPlayer === 1) {
        currentName = player1;
        $('h3').text(currentName + " it is your turn, pick a column to drop in!")
        currentColor = player1Color;
    } else {
        currentName = player2;
        $('h3').text(currentName + " it is your turn, pick a column to drop in!")
        currentColor = player2Color;
    }
    if (game_on === false) {
        $('h3').text("Refresh the page to Play Again!")
    }
})



$("#tsparticles")
    .particles()
    .init(
        {
            background: {
                color: {
                    value: "#171717",
                },
            },
            fpsLimit: 60,
            interactivity: {
                detectsOn: "canvas",
                events: {
                    onClick: {
                        enable: true,
                        mode: "push",
                    },
                    onHover: {
                        enable: true,
                        mode: "repulse",
                    },
                    resize: true,
                },
                modes: {
                    bubble: {
                        distance: 400,
                        duration: 2,
                        opacity: 0.8,
                        size: 40,
                    },
                    push: {
                        quantity: 4,
                    },
                    repulse: {
                        distance: 200,
                        duration: 0.4,
                    },
                },
            },
            particles: {
                color: {
                    value: "#ffffff",
                },
                links: {
                    color: "#ffffff",
                    distance: 150,
                    enable: true,
                    opacity: 0.5,
                    width: 1,
                },
                collisions: {
                    enable: true,
                },
                move: {
                    direction: "none",
                    enable: true,
                    outMode: "bounce",
                    random: false,
                    speed: 6,
                    straight: false,
                },
                number: {
                    density: {
                        enable: true,
                        value_area: 800,
                    },
                    value: 80,
                },
                opacity: {
                    value: 0.5,
                },
                shape: {
                    type: "circle",
                },
                size: {
                    random: true,
                    value: 7,
                },
            },
            detectRetina: true,
        },
       
    );

