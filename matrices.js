let mat1 = [ 
	[1, 1, 1, 1], 
	[2, 2, 2, 2], 
	[3, 3, 3, 3], 
	[4, 4, 4, 4], 
]; 

let mat2 = [ 
	[1, 1, 1, 1], 
	[2, 2, 2, 2], 
	[3, 3, 3, 3], 
	[4, 4, 4, 4], 
]; 
let resmat = []; 
for (let i = 0; i < mat1.length; i++) { 
	let r = ""; 
	for (let j = 0; j < mat1[i].length; j++) { 
		r += mat1[i][j] + mat2[i][j] + " "; 
	} 
	resmat.push(r.trim()); 
} 
resmat.forEach(r => console.log(r));
