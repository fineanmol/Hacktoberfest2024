const bubbleSort = (arr) => {
	let change;
	do {
		change = false;
		for (let i = 0; i < arr.length - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				[arr[i], arr[i + 1]] = [arr[j + 1], arr[i]];
				change = true;
			}
		}
	} while (change);
	return arr;
};

console.log(bubbleSort([6, 5, 4, 3, 2, 1]));
