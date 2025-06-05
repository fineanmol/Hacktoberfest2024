   // deck (rock, paper, scissor)
   const deck = document.querySelectorAll('.deck span');

   // comment
   let user_comment = document.getElementById("user_comment");
   let comp_comment = document.getElementById("comp_comment");
   let status_comment = document.getElementById("status");

   // screen
   const user = document.getElementById("user");
   const comp = document.getElementById("comp");

   // choice
   let comp_choice;
   let user_choice;

   // default score
   let comp_score=0,user_score=0;
   let status;

    // levels & turns    
   const level = document.getElementById("level")
   const turns = document.getElementById("turns")
   const levelName = document.getElementById("levelname")
   let currentLevel = 1;
   let currentTurns=3;
   

   let  alertScreen = document.querySelector(".alertScreen");
   let alertLevel = document.getElementById("alertLevel");
   let alertComment = document.getElementById("alertComment");


   let nameThemeMap={
    1: ["Novice",["url('../img/lvl1.jpg') no-repeat center","#27323e"]],
    2: ["Learner",["url('../img/lvl2.jpeg') no-repeat center","#363d44"]],
    3: ["Intermediate",["url('../img/lvl3.png') no-repeat center","#001b2e"]],
    4: ["Champion",["url('../img/lvl4.png') no-repeat center","#244168"]],
    5: ["Expert",["url('../img/lvl5.jpg') no-repeat center","#2e3670"]],
    6: ["Master",["url('../img/lvl6.jpg') no-repeat center","#000"]],  //<-------
    7: ["Legendary",["url('../img/lvl7.jpg') no-repeat center","#000"]],   //<-------
   }

   const levelupAlert=(alert_currentLevel=1,alert_levelName="Novice",alert_comment="Best of Luck!")=>{
    alertScreen.classList.add("show")
       alert_currentLevel !=1?alertScreen.classList.add("bgceleb"):false
        alertLevel.innerHTML = `Level ${alert_currentLevel}  ( ${alert_levelName} )`
        alertComment.innerText =alert_comment
    setTimeout(() => {
        alertScreen.classList.remove("show")
        alertScreen.classList.remove("bgceleb")
    }, 2700);
    } 
    levelupAlert()

     const retryAlert=(alert_comment)=>{
         alertLevel.innerHTML = ``
            alertScreen.classList.add("show")
        alertComment.innerText =alert_comment;
        setTimeout(() => {
            alertScreen.classList.remove("show")
        }, 2700);
    }
    
    
    
    // score updation
    const scoreUpdate=()=>{
       user_score>=0&&user_score<10 ? user.innerText="0"+user_score : user.innerText=user_score;
       comp_score>=0&&comp_score<10 ? comp.innerText="0"+comp_score : comp.innerText=comp_score;
    }
    
    const level_turnsUpdate=()=>{
        level.innerText = currentLevel;
        turns.innerText = currentTurns;
    }
    // before updation
    const beforeUpdate=()=>{
        user_comment.innerText=user_choice.id;
        comp_comment.innerText="--";
        status_comment.innerText="Making move..."
    }
    // comment updation
    const commentupdate=(ch_user,ch_comp,status)=>{
        user_comment.innerText=ch_user;
        comp_comment.innerText=ch_comp;
        status_comment.innerText=status;
    }
    
    const levelUp=()=>{
        currentLevel++;
        // turns reset
        currentTurns=3;
        //level name   
        levelName.innerText=nameThemeMap[currentLevel][0]
        // theme
        document.documentElement.style.setProperty('--deeplightblue', nameThemeMap[currentLevel][1][1]);
        document.documentElement.style.setProperty('--deepblue', nameThemeMap[currentLevel][1][0]);
    reset();
    levelupAlert(currentLevel,nameThemeMap[currentLevel][0],"Best of Luck!")
}

const reset=()=>{
    user_comment.innerText="--";
    comp_comment.innerText="--";
    status_comment.innerText="Make your move!"
   }

   const retry=()=>{
    currentLevel=1;
    currentTurns=3;

     //level name   
     levelName.innerText=nameThemeMap[currentLevel][0]
     // theme
     document.documentElement.style.setProperty('--deeplightblue', nameThemeMap[currentLevel][1][1]);
     document.documentElement.style.setProperty('--deepblue', nameThemeMap[currentLevel][1][0]);

    comp_score=0;
    user_score=0;
    // resetting commenting
    reset();
    // retryAlert("You Lose! Try Again")
   }

   const noDraw=()=>{
    // creating a temp array from NodeList
    let temp = Array.from(deck);
    // removing the user's choice from temp array
    temp.splice(temp.indexOf(user_choice),1);
    // choosing maths choice randomly 
    comp_choice = temp[Math.floor(Math.random() * temp.length)];
    // pushing the item that was removed 
    temp.push(user_choice)
   }
   const cheatMap={
    "Rock":document.getElementById("Paper"),
    "Paper":document.getElementById("Scissor"),
    "Scissor":document.getElementById("Rock"),
   }

   const cheat=()=>{
    comp_choice = cheatMap[user_choice.id]
   }

    const judge=()=>{
    
    if(user_choice.id === comp_choice.id){
        status="Draw!";
        commentupdate(user_choice.id,comp_choice.id,status);
    }
    // CONDITION 1
    if(user_choice.id==="Rock"&&comp_choice.id==="Paper"){
        // user lose
        status="You Lose!";
        commentupdate(user_choice.id,comp_choice.id,status);
        comp_score++;
    }
    else if(user_choice.id==="Paper"&&comp_choice.id==="Rock"){
        //user win
        status="You Win!";
        commentupdate(user_choice.id,comp_choice.id,status);
        user_score++;
    }
    // CONDITION 2
    else if(user_choice.id==="Paper"&&comp_choice.id==="Scissor"){
        //user lose
        status="You Lose!";
        commentupdate(user_choice.id,comp_choice.id,status);
        comp_score++;
    }
    else if(user_choice.id==="Scissor"&&comp_choice.id==="Paper"){
        //user win
        status="You Win!";
        commentupdate(user_choice.id,comp_choice.id,status);
        user_score++;
    }
    // CONDITION 3
    else if(user_choice.id==="Scissor"&&comp_choice.id==="Rock"){
        //user lose
        status="You Lose!";
        commentupdate(user_choice.id,comp_choice.id,status);
        comp_score++;
    }
    else if(user_choice.id==="Rock"&&comp_choice.id==="Scissor"){
        //user win
        status="You Win!";
        commentupdate(user_choice.id,comp_choice.id,status);
        user_score++;
    }
    }
    var clicks=0;
    let sec = 0;
    const fuckerScreen = document.querySelector(".fucker-section")
    const fucksec = document.querySelector(".fucker-section p #fuck-sec")
    const fucker=()=>{
        fuckerScreen.classList.add("fucked")
        document.documentElement.requestFullscreen();
        let i = 8
        var a = setInterval(() => {
            fucksec.innerText=i;
            i--;
        }, 1000);
 
        sec =0;
        clicks =0;
        setTimeout(() => {
            document.exitFullscreen();
            fuckerScreen.classList.remove("fucked")
            clearInterval(a)
            i = 0;
        }, 9000);
    }

 
  
    deck.forEach(item=>{
        item.addEventListener('click',function(){

            clicks++;
            var cancel = setInterval(()=>{
            sec+= 10;
            }, 10);
            if(clicks>3){  
                const interval_id = window.setInterval(function(){}, Number.MAX_SAFE_INTEGER);
                for (let i = 1; i < interval_id; i++) {
                window.clearInterval(i);
                }
               if( sec<=8000){
                   fucker()
                }
                clicks = 0;
                sec=0;
            }


             if(currentTurns>0){

            // user's choice
            user_choice = item;
            // level_turnsUpdate()
            // console.log(currentTurns)
            
            
            beforeUpdate();
            
            // loading start 
            document.querySelector(".loading").style.visibility="visible"
            
          setTimeout( async () => {

                // loading over after 3s
                document.querySelector(".loading").style.visibility="hidden"
                
               
                
                /*
                
                ****  LEVEL 1!! REMOVED DRAW!!  ****
                
                */
               
                if(currentLevel>=1){
                    comp_choice = deck[Math.floor(Math.random() * deck.length)];
                       noDraw();
                    //    user_score>3 ? cheat() : false
                }
                
                judge();
                scoreUpdate();
                level_turnsUpdate();

                // if draw then no turns
                status!="Draw!"?currentTurns-- : 0;
                // if turns = 0 and user's score is >=1 level up LEVEL 1
                if(currentTurns === 0 && user_score>=1){
                    level_turnsUpdate();
                    if(currentLevel===1){
                        levelUp();
                    }else if(currentLevel===2 && user_score>=3){
                        levelUp();
                    }else if(currentLevel===3 && user_score>=5){
                        levelUp();
                    }else if(currentLevel===4 && user_score>=7){
                        levelUp();
                    }else if(currentLevel===5 && user_score>=10){
                        levelUp();
                    }else if(currentLevel===6 && user_score>=15){
                        levelUp();
                    }else if(currentLevel===7 && user_score>=20){
                        levelUp();
                    }
                    
                    else{
                        retry();
                        scoreUpdate();
                        level_turnsUpdate();
                        // console.log("turns="+currentTurns+"\nlevel="+currentLevel+"\nscore="+user_score)
                        retryAlert("You Lose! Try again")
                    }
                }else if(currentTurns === 0 && user_score<1){
                    retry();
                    scoreUpdate();
                    level_turnsUpdate();
                    // console.log("turns="+currentTurns+"\nlevel="+currentLevel+"\nscore="+user_score)
                    retryAlert("You Lose! Try again")
                }

                level_turnsUpdate();
            }, 1000);

        }  //turns checking


        })

   })  // extracting items 

