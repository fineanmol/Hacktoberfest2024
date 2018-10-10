// function to generate a random number range.
function randRange(minNum, maxNum) {
  return (Math.floor(Math.random() * (maxNum - minNum + 1)) + minNum);
}

// function to generate drops
function createRain() {
	var i;
	var drop_number = 0;
	for (i = 0; i < 10; i++) {
		var num_drops = randRange(3,6);
		for (x = 0; x <= num_drops; x++) {
			var dropLeft = randRange(i*10,i*10+10);
			var dropTop = randRange(-1000,1400);
			$('.rain').append('<div class="drop'+randRange(1,10)+'" id="drop'+drop_number+'">🥚</div>');
			$('#drop'+drop_number).css('left',dropLeft+"%");
			$('#drop'+drop_number).css('top',dropTop);
			drop_number++;
		}
	}
}

// Make it rain
createRain();
