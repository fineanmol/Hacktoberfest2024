$(document).ready(function() {

	// it will reset the table
	$('#reset').click(function() {
    	$('li').remove();
    	$('.pscore p').remove();
    	$('.score h1').remove();
    	$('.dealers_cards').css("height", "96px");
    });

    // this will reset the table and start the game
    $('#start').click(function() {
    	$('li').remove();
    	$('.pscore p').remove();
    	$('.score h1').remove();
        playGame();
    });


    $('#hit').click(function() {
		playerHand.hitMe("p");
		result = firstResultCheck();
		inputUserScore(result);
		if(isNumeric(result)){
			viewConsole();
		} else {
			hideConsole();
			return;
		}
    });


    $('#stand').click(function() {
    	while(dealerHand.score() < 17){
    		countingDealersCards = 0;
    		dealerHand.hitMe("b");
    	}
		result = finalResultCheck();
		$('.dealers_cards li').remove();
		revealDealerHand(dealerHand);
		inputUserScore(result);
		hideConsole();
		return;
    });
});

// this will find the face of card
function faceOfCard(suit, figure){
	suits = {1: "clubs", 2: "diamonds", 3: "hearts", 4: "spades"};
	figures = {1: "ace", 2: "2", 3: "3", 4: "4", 5: "5", 6: "6", 7: "7", 8: "8", 9: "9", 10: "10", 11: "jack", 12: "queen", 13: "king"};
	var c = figures[figure] + "_of_" + suits[suit] + ".svg";
	return c;
}

//
function deck(){
	this.create = function(){
  	var cardArray = [];
  	var i = 1;
  	var j = 1;
  		for(i = 1; i < 14; i++){
  			for(j = 1; j < 5; j++){
  				cardArray.push(new Card(j, i));
  			}
  		}
  	return shuffle(shuffle(cardArray));
  };
}

//
function deckChecker(){
	var array = new deck();
	var array = array.create();
	for(i = 0; i < 52; i++){
	  console.log(array[i].getNumber() + " of suit "+array[i].getSuit());
	}
}

//Deck suffling
function shuffle(a) {
    for (let i = a.length; i; i--) {
        let j = Math.floor(Math.random() * i);
        [a[i - 1], a[j]] = [a[j], a[i - 1]];
    }
	return a;
}

//Card Constructor
function Card(suit, number){
	var CardSuit = suit;
	var CardNumber = number;
	this.getSuit = function(){
		return CardSuit;
	};
	this.getNumber = function(){
		return CardNumber;
	};
	this.getValue = function(){
    if( number === 1) {
        return 11;
    } else if( number > 9) {
        return 10;
    } else {
    return number;
    }
	};
}

function revealDealerHand(hand){
	var hand = hand.getHand();
	for(i=0;i<hand.length;i++){
		$('.dealers_cards ul').prepend('<li><a href="#"><img src="cards/' + faceOfCard(hand[i].getSuit(), hand[i].getNumber()) + '" /></a></li>');
	}
}

// Deal function provides players with cards and prepend card images with jQuery
var deal = function(whos){
	var newCard = gameDeck.pop();
	if(whos == "b"){
		countingDealersCards+= 1;
	}
	
	if(whos == "p"){
		$('.players_cards ul').prepend('<li><a href="#"><img src="cards/' + faceOfCard(newCard.getSuit(), newCard.getNumber()) + '" /></a></li>');
	} else if(whos == "b" && countingDealersCards < 2) {
		$('.dealers_cards').css("height", "");
		$('.dealers_cards ul').prepend('<li><a href="#"><img src="cards/' + faceOfCard(newCard.getSuit(), newCard.getNumber()) + '" /></a></li>');
	} else if(whos == "b" && countingDealersCards == 2){
		$('.dealers_cards ul').prepend('<li><a href="#"><img src="cards/back.jpg" /></a></li>');
	}
	return newCard;
};

// this is keeping the score
function Hand(whos, howManyCards){
	var who = whos;
	var cardArray = [];
		for(i = 0; i < howManyCards; i++) {
    cardArray[i] = deal(who);
	}
	this.getHand = function() {
    return cardArray;
	};

	this.score = function(){
		var handSum = 0;
		var numofaces = 0;
		for(i=0;i<cardArray.length;i++){
			handSum += cardArray[i].getValue();
			if(cardArray[i].getNumber() === 1){
        		numofaces+=1;
        	}
        }
    	if(handSum > 21 && numofaces!=0){
    		for(i=0;i<numofaces;i++){
    			if(handSum > 21){
    				handSum-=10;
    			}
    		}
    	}
        return handSum;
	};
	this.printHand = function(){
		var string = "";
		for(i=0;i<cardArray.length;i++){
			string = string + cardArray[i].getNumber() + " of suit "+cardArray[i].getSuit()+", ";
		}
		return string;
	};
	this.hitMe = function(whos){
    cardArray.push(deal(whos));
	this.getHand();
	};
}

var finalResultCheck = function(){
	var pS = playerHand.score();
	var dS = dealerHand.score();
	if(pS > 21){
      	if( dS >21){
          	return "Tide";
      	}
      	else{
      	return "Bust";
      	}
  	}
  	else if(dS>21){
    	return "Win";
 	}
  	else if(pS>dS){
      	return "Win";
  	}
  	else if(pS===dS){
      	return "Tide";
  	}
  	else{
      	return "Bust";
  	}
 };

 var inputUserScore = function(input){
 	$('.pscore p').remove();
	$('.pscore').prepend("<p>" + input + "</p>");
 }

 var firstResultCheck = function(){
	pS = playerHand.score();
	dS = dealerHand.score();
	if(pS > 21){
      	if( dS >21){
          	return "TideOver";
      	}
      	else{
      	return "Bust";
      	}
  	}
  	else if(dS>21){
    	return "Win";
 	}
 	else if(pS===21){
 		return "BJ";
 	}
  	else{
      	return pS;
  	}
 };

var phaseOne = function(){
	dealerHand = new Hand("b", 2);
	playerHand = new Hand("p", 2);
	result = firstResultCheck();

	inputUserScore(result);
	if(isNumeric(result)){
		viewConsole();
	} else {
		hideConsole();
		return;
	}
};

function isNumeric(n) {
  return !isNaN(parseFloat(n)) && isFinite(n);
}

var viewConsole = function(){
	$('.gameConsole').css("visibility", "");
}

var hideConsole = function(){
	$('.gameConsole').css("visibility", "hidden");
}

var playGame = function(){
	var gdeck = new deck();
	countingDealersCards = 0;
	gameDeck = gdeck.create();
	phaseOne();
};
