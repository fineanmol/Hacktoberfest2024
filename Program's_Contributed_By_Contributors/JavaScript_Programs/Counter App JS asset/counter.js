let savEl = document.getElementById("save-el");
let coEl = document.getElementById("count-el");

let count = 0;

function increment() {
	count = count + 1;

	coEl.textContent = count;
}

function decrement() {
	count = count - 1;

	coEl.textContent = count;
}

function save() {
	let save = ` ${count}, `;
	savEl.textContent += save;

	coEl.textContent = 0;
	count = 0;
}
