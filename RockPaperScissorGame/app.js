function start(){
    document.getElementById("rock").style.visibility="visible";
    document.getElementById("paper").style.visibility="visible";
    document.getElementById("scissors").style.visibility="visible";

}

clickedHand=["<img src='rock.PNG' id='img1'>","<img src='paper.PNG' id='img1'>","<img src='scissor.PNG' id='img1'>" ];

clickedRightHand=["<img src='rock.PNG' id='img2'>","<img src='paper.PNG' id='img2'>","<img src='scissor.PNG' id='img2'>" ];

function game(position){
    document.getElementById("img1").style.animation='LeftHand 1s 5 ease-in-out';
    document.getElementById("img2").style.animation='RightHand 1s 5 ease-in-out';

    var random=Math.floor(Math.random()*3);
    setTimeout(() => {
        document.getElementById("left_hand").innerHTML=clickedRightHand[random];
        document.getElementById("right_hand").innerHTML=clickedHand[position];
    }, 3000);
    setTimeout(() => {
        if(random==position){
            alert("YOUR MATCH IS DRAW !!");
            window.location.reload();
        }
        else if(position==0 && random==2){
            alert("YOU ARE WINNER , GOOD JOB !!");
            window.location.reload();
        }
        else if(position==1 && random==0){
            alert("YOU ARE WINNER , GOOD JOB !!");
            window.location.reload();
        }
        else if(position==2 && random==1){
            alert("YOU ARE WINNER , GOOD JOB !!");
            window.location.reload();
        }
        else{
            alert("COMPUTER IS WINNER,TRY NEXT TIME !!");
            window.location.reload();
        }
    }, 4000);
}