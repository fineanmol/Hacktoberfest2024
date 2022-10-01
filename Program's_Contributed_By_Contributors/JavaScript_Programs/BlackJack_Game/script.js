let blackjackgame = {
    'you': {'resultspan': '#your-blackjack-result','div':'#your-box','score':0},
    'dealer': {'resultspan': '#dealer-blackjack-result','div':'#dealer-box','score':0},
    'cards': ['2','3','4','5','6','7','8','9','10','K','J','Q','A'],
    'scorecard':{'2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9, '10':10, 'K':10, 'J':10, 'Q':10, 'A':[1,11] },
    'wins':0,
    'losses':0,
    'draws':0,
    'isStand':false,
    'turnsOver':false
};

const YOU = blackjackgame['you']
const DEALER = blackjackgame['dealer']

const hitsound = new Audio('sounds/swish.m4a');
const winsound = new Audio('sounds/cash.mp3');
const lostsound = new Audio('sounds/aww.mp3');


document.querySelector('#blackjack-hit').addEventListener('click',blackjackhit);
document.querySelector('#blackjack-stand').addEventListener('click',dealerLogic);
document.querySelector('#blackjack-deal').addEventListener('click',blackjackDeal);
 
function blackjackhit(){
    if(blackjackgame['isStand'] === false){
        let card = randomCard();
        showCard(card,YOU);
        updateScore(card,YOU);
        showScore(YOU);
        console.log(YOU['score']);
    }   
}

function showCard(card, activeplayer){
    if(activeplayer['score']<=21){
    let cardimage = document.createElement('img');
    cardimage.src = `images/${card}.png`;
    document.querySelector(activeplayer['div']).appendChild(cardimage);
    hitsound.play();
    }
}

function randomCard(){
    let randomIndex = Math.floor(Math.random()*13);
    return blackjackgame['cards'][randomIndex];
}

function blackjackDeal(){
    if(blackjackgame['turnsOver'] === true){
        blackjackgame['isStand'] = false;
        let yourImages = document.querySelector('#your-box').querySelectorAll('img');
        let dealerImages = document.querySelector('#dealer-box').querySelectorAll('img');
        for(i=0;i<yourImages.length;i++){
            yourImages[i].remove();
        }
        for(i=0;i<dealerImages.length;i++){
            dealerImages[i].remove();
        }

        YOU['score'] = 0;
        DEALER['score'] = 0;
        document.querySelector('#blackjack-result').textContent = "LET'S PLAY!";
        document.querySelector('#blackjack-result').style.color='white';
        document.querySelector('#your-blackjack-result').textContent=0;
        document.querySelector('#your-blackjack-result').style.color='white';
        document.querySelector('#dealer-blackjack-result').textContent=0;
        document.querySelector('#dealer-blackjack-result').style.color='white';
        blackjackgame['turnsOver'] = false;
    }
}
 
function updateScore(card,activeplayer){
    //if adding A as 11 keeps us below 21 add 11, otherwise add 1
    if(card === 'A'){
        if(activeplayer['score']+blackjackgame['scorecard'][card][1]){
            activeplayer['score']+=blackjackgame['scorecard'][card][1];
        }else{
            activeplayer['score']+=blackjackgame['scorecard'][card][0];
        }
    }else{
        activeplayer['score']+=blackjackgame['scorecard'][card];
    }
}

function showScore(activeplayer){
    if(activeplayer['score']>21){
        document.querySelector(activeplayer['resultspan']).textContent = 'BUST!';
        document.querySelector(activeplayer['resultspan']).style.color = 'red';
    }else{
        document.querySelector(activeplayer['resultspan']).textContent = activeplayer['score'];
    }   
}

function sleep(ms){
    return new Promise(resolve => setTimeout(resolve,ms));
}
 
async function dealerLogic(){
    blackjackgame['isStand']=true;

    while(DEALER['score'] < 16 && blackjackgame['isStand'] === true){
        let card = randomCard();
        showCard(card,DEALER);
        updateScore(card,DEALER); 
        showScore(DEALER);
        await sleep(1000);
    } 
    blackjackgame['turnsOver']=true;
    let winner = computewinner();
    showWinner(winner);
}

function computewinner(){
    let winner;
    if(YOU['score']<=21){
        if(YOU['score'] > DEALER['score'] || (DEALER['score'] > 21)){
            blackjackgame['wins']++;
            winner = YOU;
        }
        else if(YOU['score'] < DEALER['score']){
            blackjackgame['losses']++;
            winner = DEALER;
        }
        else if(YOU['score'] === DEALER['score']){
            blackjackgame['draws']++;
        }
    }
    else if(YOU['score'] > 21 && DEALER['score'] <= 21){
        blackjackgame['losses']++;
        winner = DEALER;
    }
    else if(YOU['score'] > 21 && DEALER['score'] > 21){
        blackjackgame['draws']++;
    }
    return winner;
}

function showWinner(winner){
    let message,msgcolor;
    if(blackjackgame['turnsOver'] === true){
        if(winner === YOU){
            document.querySelector('#wins').textContent = blackjackgame['wins'];
            message = 'YOU WON!!';
            msgcolor = 'green';
            winsound.play();
        }
        else if(winner === DEALER){
            document.querySelector('#losses').textContent = blackjackgame['losses'];
            message = 'YOU LOST!!';
            msgcolor = 'red';
            lostsound.play();
        }
        else{
            document.querySelector('#draws').textContent = blackjackgame['draws'];
            message = 'YOU DREW!!';
            msgcolor = 'yellow';
        }
        document.querySelector('#blackjack-result').textContent = message;
        document.querySelector('#blackjack-result').style.color = msgcolor;
    }
}

