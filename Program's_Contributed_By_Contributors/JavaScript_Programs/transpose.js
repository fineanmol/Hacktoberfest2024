function transpose(array) {
  let height = array.length;
  let width = array[0] instanceof Array ? array[0].length : 0;
  let arrTranspose = [];

  if (height == 0 || width == 0) return 'Data is not a multidimensional array';

  for (let i = 0; i < height; i++) {
    arrTranspose[i] = [];
    for (let j = 0; j < width; j++) {
      arrTranspose[i][j] = array[j][i];
    }
  }
  return arrTranspose;
}

const input = [
  [1, 2, 3],
  [1, 2, 3],
  [1, 2, 3],
];

transpose(input);