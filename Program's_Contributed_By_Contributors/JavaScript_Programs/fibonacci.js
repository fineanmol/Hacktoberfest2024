export default (num) => {
  if (num >= 0) {
    var a = 1;
    var b = 0;

    for (var i = 0; i < num - 1; i++) {
      var temp = a;
      a = a + b;
      b = temp;
    }

    return a;
  } else {
    throw "Index cannot be negative";
  }
}