<script>
	cross = true;
	score = 0;
	document.onkeydown = function(e) {
		console.log(e.keyCode);
		if (e.keyCode == 38) {
			dragon = document.querySelector('.dragon');

			dragon.classList.add('animatedragon');
			
			setTimeout(() => {
				dragon.classList.remove('animatedragon');
			}, 700);
		}
		if (e.keyCode == 37) {
			dragon = document.querySelector('.dragon');

			dragonx = parseInt(window.getComputedStyle(
				dragon, null).getPropertyValue('left'));

			dragon.style.left = dragonx - 112 + "px";
		}
		if (e.keyCode == 39) {
			dragon = document.querySelector('.dragon');

			dragonx = parseInt(window.getComputedStyle(
				dragon, null).getPropertyValue('left'));
			
			dragon.style.left = dragonx + 112 + "px";
		}
	}
	setInterval(() => {
		dragon = document.querySelector('.dragon');
		gameover = document.querySelector('.gameover');
		obstacle = document.querySelector('.obstacle');

		dx = parseInt(window.getComputedStyle(
			dragon, null).getPropertyValue('left'));

		dy = parseInt(window.getComputedStyle(
			dragon, null).getPropertyValue('bottom'));

		ox = parseInt(window.getComputedStyle(
			obstacle, null).getPropertyValue('left'));

		oy = parseInt(window.getComputedStyle(
			obstacle, null).getPropertyValue('bottom'));

		offsetx = Math.abs(dx - ox);
		offsety = Math.abs(dy - oy);

		console.log(offsetx, offsety);

		if (offsetx < 120 && offsety <= 144) {
			if (score != 0)
				scorecount.innerHTML = "Your score : " + score;
			gameover.style.visibility = 'visible';
			obstacle.classList.remove('animateobstacle');
		} else if (offsetx < 125 && cross) {
			score += 1;
			updateScore(score);
			cross = false;
			setTimeout(() => {
				cross = true;
			}, 1000);
			setInterval(() => {
				obsanidur = parseFloat(window
				.getComputedStyle(obstacle, null)
				.getPropertyValue('animation-duration'));

				obstacle.style.animationDuration
					= obsanidur - 0.01 + 's';
			}, 500);
		}
	}, 10);

	function updateScore(score) {
		scorecount.innerHTML = "Your score : " + score;
	}
</script>
