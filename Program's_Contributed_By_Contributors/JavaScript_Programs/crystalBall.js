/// two crystal ball algorith with a run time less than O(n);
function two_crystal_balls(breaks) {
	const { floor, sqrt } = Math;
	const jumpAmount = floor(sqrt(breaks.length));
	let i = jumpAmount;
	for (i; i < breaks.length; i += jumpAmount) {
		if (breaks[i]) break;
		i -= jumpAmount;
		for (let j = 0; j < jumpAmount && i < breaks.length; i++, j++) {
			if (breaks[i]) return i;
		}
	}
	return -1;
}
