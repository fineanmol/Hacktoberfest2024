
//take the name of the player 1 and 2 from the prompt alert!
var player1 = prompt('Player 1, enter your name:'); 
var player2 = prompt('Player 2, enter your name:');

playerPrompt = $('span'); // taking the object span where it displays which player's turn it is

playerPrompt.text(player1+', it is your turn') // displays whose turn it is

circle = $('td'); //taking the object of each table cell and storing it in a queue of cells

console.log(circle);

//initializing the starting point of each column so that the chips can be placed in the bottom of the table
zero = 42;
one = 43;
two = 44;
three = 45;
four = 46;
five = 47;
six = 48;


let playerTurn = 0;

let color = "turnRed"; //initializing color with red because player 1 will always be red

//when the table cells are clicked this function is activated
circle.click(function(){

    //checking the column number of clicked cells and checking if that column is full or not
    if($(this).index()==0 && zero>=0){
        zero =chipDrop(color,zero);
    }
    else if($(this).index()==1 && one>=0){
        one =chipDrop(color,one);
    } 
    else if($(this).index()==2 && two>=0){
        two =chipDrop(color,two);
    } 
    else if($(this).index()==3 && three>=0){
        three =chipDrop(color,three);
    } 
    else if($(this).index()==4 && four>=0){
        four =chipDrop(color,four);
    }
    else if($(this).index()==5 && five>=0){
        five =chipDrop(color,five);
    }  
    else if($(this).index()==6 && six>=0){
        six =chipDrop(color,six);
    } 

})


//drops the chip to the specified cells starting from bottom
function chipDrop(currentColor,index){
    circle.eq(index).addClass(currentColor); // adds the class color (.turnRed or .turnBlue) to the index zero in circle table cell queue
        checkVertically(index); 
        checkHorizontally(index);
        colorChange();  //changes the color after each successful turn
        return index-=7;
}


//this function changes the class name of variable color after each successful turn
function colorChange(){
    //if the current color is red then it changes it to blue alternatively and vice verse
    if(color == "turnRed"){
        color =  "turnBlue"; 
        playerPrompt.text(player2+', it is your turn'); //displays the player 1 name in prompt
    }
    else{
        color = "turnRed";
        playerPrompt.text(player1+', it is your turn'); //displays the player 2 name in prompt
    }

}

function checkVertically(index){
    freq = 0;   
    
    //loop to check every cell of a column
    for(let i=index;i<49;i+=7){

        //true if the index cell has the same class name as the currently pushed color
        if(circle.eq(i).attr('class')==color){
            freq+=1;  //if there are adjacent cells with the same class then increment freq
            
            //if there are continuous 4 cells with the same name then declare the winnner
            if(freq==4){
                declareResult(color);
            }
        }
        else{
            break; //when there is another color in between and no continous streak can be formed
        }
    }
}

function checkHorizontally(index){
    freq = 0; 
    row = Math.floor(index/7); //get the integer row number of the cell in which chip was dropped
    startingPoint = row*7; //the starting cells from left of the row of which the current chip dropped

    //the loop runs along a row and should not go beyind the last cell index of that row

    for(let i=startingPoint;i<startingPoint+7 && i<(row+1)*7;i++){

        //true if the index cell has the same class name as the currently pushed color
        if(circle.eq(i).attr('class')==color){
            freq+=1;
            console.log(freq,i,circle.eq(i).attr('class'));
            if(freq==4){
                declareResult(color);
            }
        }
        else{
            freq = 0; //if there is a another color in between then intialize flag to 0
        }
    }
}

function declareResult(winningColor){
    
    if(winningColor == 'turnRed'){

        //this function delays the alert by 100ms so that the last chip can be pushed before displaying the result.
        setTimeout(function() {

            //when we click on "OK" in alert it returns false, therefore not of false gives us true and the page is reloaded
            if(!alert(player1+' has won the game\n\n click "OK" to restart')){
                window.location.reload(); //function to reload the page
            }
        }, 100);
        
    }
    else{
        setTimeout(function() {
            if(!alert(player2+' has won the game\n\n click "OK" to restart')){
                window.location.reload();
            }
        }, 100);
    }
}
